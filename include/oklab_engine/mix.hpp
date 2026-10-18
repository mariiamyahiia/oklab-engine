#pragma once
#include <oklab_engine/types.hpp>

namespace oklab_engine {

enum class HueMode { Shorter, Longer };

/// Returns a*(1-t) + b*t in OKLab. t is not clamped.
[[nodiscard]] OKLab mix(const OKLab& a, const OKLab& b, real t) noexcept;

/// Interpolates L and C linearly, hue along the chosen arc. t is not clamped.
[[nodiscard]] OKLCH mix(const OKLCH& a, const OKLCH& b, real t,
                        HueMode mode = HueMode::Shorter) noexcept;

}