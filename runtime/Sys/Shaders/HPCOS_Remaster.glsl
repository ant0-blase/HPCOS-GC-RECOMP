/*
[configuration]

[OptionRangeFloat]
GUIName = Saturation
OptionName = HPCOS_SATURATION
MinValue = 0.0
MaxValue = 2.0
StepAmount = 0.01
DefaultValue = 1.08

[OptionRangeFloat]
GUIName = Vibrance
OptionName = HPCOS_VIBRANCE
MinValue = -1.0
MaxValue = 1.0
StepAmount = 0.01
DefaultValue = 0.12

[OptionRangeFloat]
GUIName = Contrast
OptionName = HPCOS_CONTRAST
MinValue = 0.5
MaxValue = 1.8
StepAmount = 0.01
DefaultValue = 1.06

[OptionRangeFloat]
GUIName = Exposure
OptionName = HPCOS_EXPOSURE
MinValue = -1.0
MaxValue = 1.0
StepAmount = 0.01
DefaultValue = 0.03

[OptionRangeFloat]
GUIName = Gamma
OptionName = HPCOS_GAMMA
MinValue = 0.5
MaxValue = 2.0
StepAmount = 0.01
DefaultValue = 1.0

[OptionRangeFloat]
GUIName = Temperature
OptionName = HPCOS_TEMPERATURE
MinValue = -1.0
MaxValue = 1.0
StepAmount = 0.01
DefaultValue = 0.02

[OptionRangeFloat]
GUIName = Sharpen
OptionName = HPCOS_SHARPEN
MinValue = 0.0
MaxValue = 1.5
StepAmount = 0.01
DefaultValue = 0.28

[OptionRangeFloat]
GUIName = Bloom
OptionName = HPCOS_BLOOM
MinValue = 0.0
MaxValue = 1.0
StepAmount = 0.01
DefaultValue = 0.10

[OptionRangeFloat]
GUIName = Vignette
OptionName = HPCOS_VIGNETTE
MinValue = 0.0
MaxValue = 1.0
StepAmount = 0.01
DefaultValue = 0.06

[OptionRangeFloat]
GUIName = Film grain
OptionName = HPCOS_GRAIN
MinValue = 0.0
MaxValue = 0.25
StepAmount = 0.005
DefaultValue = 0.0

[/configuration]
*/

float HPCOSLuma(float3 c)
{
  return dot(c, float3(0.2126, 0.7152, 0.0722));
}

float HPCOSHash(float2 p)
{
  float h = dot(p, float2(127.1, 311.7)) + float(time) * 0.017;
  return fract(sin(h) * 43758.5453);
}

void main()
{
  const float4 center_sample = Sample();
  float3 color = center_sample.rgb;

  // Five-tap local detail pass. Keeping the taps close avoids halos at high internal resolutions.
  const float3 n = SampleOffset(int2(0, -1)).rgb;
  const float3 s = SampleOffset(int2(0, 1)).rgb;
  const float3 e = SampleOffset(int2(1, 0)).rgb;
  const float3 w = SampleOffset(int2(-1, 0)).rgb;
  const float3 local_average = (n + s + e + w) * 0.25;

  const float sharpen = GetOption(HPCOS_SHARPEN);
  color += (color - local_average) * sharpen;

  // A restrained local bloom. It only lifts bright neighbouring detail instead of blurring the whole frame.
  const float bloom_amount = GetOption(HPCOS_BLOOM);
  const float3 bright = max(local_average - float3(0.72), float3(0.0));
  color += bright * (bloom_amount * 0.35);

  // Exposure then contrast, before chroma shaping.
  color *= exp2(GetOption(HPCOS_EXPOSURE));
  color = (color - float3(0.5)) * GetOption(HPCOS_CONTRAST) + float3(0.5);

  const float luma = HPCOSLuma(color);
  color = lerp(float3(luma), color, GetOption(HPCOS_SATURATION));

  // Vibrance protects already-saturated pixels more than a second saturation control would.
  const float max_channel = max(max(color.r, color.g), color.b);
  const float min_channel = min(min(color.r, color.g), color.b);
  const float chroma = max_channel - min_channel;
  const float vibrance = GetOption(HPCOS_VIBRANCE) * (1.0 - clamp(chroma, 0.0, 1.0));
  color = lerp(float3(HPCOSLuma(color)), color, 1.0 + vibrance);

  const float temperature = GetOption(HPCOS_TEMPERATURE);
  color.r += temperature * 0.065;
  color.g += temperature * 0.012;
  color.b -= temperature * 0.070;

  color = max(color, float3(0.0));
  color = pow(color, float3(1.0 / max(GetOption(HPCOS_GAMMA), 0.001)));

  // Soft vignette, intentionally subtle even at the default remaster preset.
  const float2 uv = GetCoordinates();
  const float2 centered = uv * 2.0 - float2(1.0);
  const float radial = dot(centered, centered);
  const float vignette = 1.0 - clamp((radial - 0.20) * GetOption(HPCOS_VIGNETTE) * 0.55, 0.0, 0.55);
  color *= vignette;

  const float grain = GetOption(HPCOS_GRAIN);
  if (grain > 0.0)
  {
    const float noise = (HPCOSHash(uv * GetWindowResolution()) - 0.5) * grain;
    color += float3(noise);
  }

  SetOutput(float4(clamp(color, 0.0, 1.0), center_sample.a));
}
