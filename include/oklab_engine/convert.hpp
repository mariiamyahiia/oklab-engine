#pragma once
#include <oklab_engine/types.hpp>

namespace oklab_engine {

// Float-target conversions do not clamp. to_srgb8 clamps and rounds.

[[nodiscard]] SRGB8     to_srgb8(const SRGB& c) noexcept;
[[nodiscard]] SRGB8     to_srgb8(const LinearRGB& c) noexcept;
[[nodiscard]] SRGB8     to_srgb8(const OKLab& c) noexcept;
[[nodiscard]] SRGB8     to_srgb8(const OKLCH& c) noexcept;

[[nodiscard]] SRGB      to_srgb(const SRGB8& c) noexcept;
[[nodiscard]] SRGB      to_srgb(const LinearRGB& c) noexcept;
[[nodiscard]] SRGB      to_srgb(const OKLab& c) noexcept;
[[nodiscard]] SRGB      to_srgb(const OKLCH& c) noexcept;

[[nodiscard]] LinearRGB to_linear(const SRGB8& c) noexcept;
[[nodiscard]] LinearRGB to_linear(const SRGB& c) noexcept;
[[nodiscard]] LinearRGB to_linear(const OKLab& c) noexcept;
[[nodiscard]] LinearRGB to_linear(const OKLCH& c) noexcept;

[[nodiscard]] OKLab     to_oklab(const SRGB8& c) noexcept;
[[nodiscard]] OKLab     to_oklab(const SRGB& c) noexcept;
[[nodiscard]] OKLab     to_oklab(const LinearRGB& c) noexcept;
[[nodiscard]] OKLab     to_oklab(const OKLCH& c) noexcept;

[[nodiscard]] OKLCH     to_oklch(const SRGB8& c) noexcept;
[[nodiscard]] OKLCH     to_oklch(const SRGB& c) noexcept;
[[nodiscard]] OKLCH     to_oklch(const LinearRGB& c) noexcept;
[[nodiscard]] OKLCH     to_oklch(const OKLab& c) noexcept;

}