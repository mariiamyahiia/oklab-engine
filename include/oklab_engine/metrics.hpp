#pragma once
#include <oklab_engine/types.hpp>

namespace oklab_engine {

/// Euclidean distance in OKLab
[[nodiscard]] real delta_e(const OKLab& a, const OKLab& b) noexcept;

}