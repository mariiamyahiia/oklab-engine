#pragma once
#include <array>
#include <cstddef>
#include <vector>
#include <oklab_engine/types.hpp>

namespace oklab_engine {

// All results keep the input's L and C; only hue changes (except monochromatic).
// result[0] is always `base`.

[[nodiscard]] std::array<OKLCH, 2> complementary(const OKLCH& base) noexcept;       // h, h+180
[[nodiscard]] std::array<OKLCH, 3> triadic(const OKLCH& base) noexcept;             // h, h+120, h+240
[[nodiscard]] std::array<OKLCH, 3> split_complementary(const OKLCH& base,
                                                       real spread_deg = 30.0f) noexcept;
[[nodiscard]] std::array<OKLCH, 4> tetradic(const OKLCH& base) noexcept;            // square: +90 steps

[[nodiscard]] std::vector<OKLCH> analogous(const OKLCH& base, std::size_t count,
                                           real step_deg = 30.0f);
[[nodiscard]] std::vector<OKLCH> monochromatic(const OKLCH& base, std::size_t count);

}