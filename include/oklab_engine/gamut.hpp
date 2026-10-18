#pragma once
#include <oklab_engine/types.hpp>

namespace oklab_engine {

[[nodiscard]] bool in_srgb_gamut(const OKLab& c, real epsilon = 1e-4f) noexcept;
[[nodiscard]] bool in_srgb_gamut(const OKLCH& c, real epsilon = 1e-4f) noexcept;

/// Reduces chroma (keeping L and h) until the color fits in sRGB
[[nodiscard]] OKLCH map_to_srgb_gamut(const OKLCH& c) noexcept;

}