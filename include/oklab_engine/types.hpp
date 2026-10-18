#pragma once
#include <cstdint>

namespace oklab_engine {

/// Scalar type for all floating-point color types.
using real = float;

/// 8-bit gamma-encoded sRGB (what hex codes represent), 0..255.
struct SRGB8 { std::uint8_t r, g, b; };

/// Gamma-encoded sRGB, nominal range [0, 1]. May leave range after math.
struct SRGB { real r, g, b; };

/// Linear-light sRGB (gamma removed), nominal range [0, 1].
struct LinearRGB { real r, g, b; };

/// OKLab: L lightness [0,1]; a green(-)/red(+); b blue(-)/yellow(+).
struct OKLab { real L, a, b; };

/// Polar OKLab: L [0,1]; C chroma >= 0; h hue in DEGREES [0,360).
struct OKLCH { real L, C, h; };

}