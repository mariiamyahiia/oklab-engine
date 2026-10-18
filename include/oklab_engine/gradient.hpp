#pragma once
#include <cstddef>
#include <vector>
#include <oklab_engine/types.hpp>

namespace oklab_engine {

enum class GradientSpace { OKLab, OKLCH };

/// Evenly spaced color stops, interpolated in the chosen space.
class Gradient {
public:
    /// Precondition: stops.size() >= 1 (asserted in debug builds).
    explicit Gradient(std::vector<OKLab> stops,
                      GradientSpace space = GradientSpace::OKLab);

    /// t is clamped to [0,1]. Does not allocate.
    [[nodiscard]] OKLab at(real t) const noexcept;

    /// n evenly spaced samples including both endpoints (n >= 2 for both).
    [[nodiscard]] std::vector<OKLab> sample(std::size_t n) const;

    [[nodiscard]] std::size_t stop_count() const noexcept;

private:
    std::vector<OKLab> stops_;
    GradientSpace space_;
};

}