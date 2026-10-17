# oklab-engine: Scope

## Problem
Compute perceptually uniform color mixes, gradients, and harmonious
palettes in OKLab/OKLCH, as a dependency-free, deterministic C++ library.

## Users
Generative artists, creative web developers, UI theme generators.

## Constraints
- Pure math; no UI, I/O, or third-party dependencies
- Deterministic: same input gives same output on the same build;
  cross-platform agreement within 1e-6; -ffast-math forbidden
- Fast: no heap allocation in core conversions

## In scope
- Types: SRGB, LinearRGB, OKLab, OKLCH
- Conversions, hex parse/format, gamut mapping (chroma reduction)
- Mixing, gradient sampling (OKLab and OKLCH)
- Harmonies: complementary, analogous, triadic, split-complementary,
  tetradic, monochromatic
- Delta-E (Euclidean in OKLab)

## Out of scope
Image I/O, palette extraction, CIELAB/HSL/Display P3, color-blindness
simulation, WCAG contrast, spline gradients, SIMD/GPU.

## Success criteria
- 8-bit sRGB round trip error < 1/255 for all colors
- White maps to ~(1, 0, 0), black to L = 0
- Gradient endpoints equal the input stops exactly
- Harmony hue offsets verified against hand calculations