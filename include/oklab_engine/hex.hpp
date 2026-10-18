#pragma once
#include <optional>
#include <string>
#include <string_view>
#include <oklab_engine/types.hpp>

namespace oklab_engine {

/// Accepts "#rgb", "#rrggbb", with or without '#', returns nullopt on bad input.
[[nodiscard]] std::optional<SRGB8> parse_hex(std::string_view text) noexcept;

/// Returns lowercase "#rrggbb".
[[nodiscard]] std::string to_hex(const SRGB8& c);

}