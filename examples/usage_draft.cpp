#include <oklab_engine/oklab_engine.hpp>
#include <iostream>

using namespace oklab_engine;

int main() {
    auto red  = parse_hex("#ff0000");
    auto blue = parse_hex("#0000ff");
    if (!red || !blue) return 1;

    // Perceptual mix
    OKLab a = to_oklab(*red);
    OKLab b = to_oklab(*blue);
    OKLab mid = mix(a, b, 0.5f);
    std::cout << to_hex(to_srgb8(mid)) << '\n';

    // Gradient
    Gradient g({a, b});
    for (const OKLab& c : g.sample(8))
        std::cout << to_hex(to_srgb8(c)) << ' ';
    std::cout << '\n';

    // Harmonies (hue math happens in OKLCH)
    OKLCH base = to_oklch(a);
    for (const OKLCH& c : triadic(base))
        std::cout << to_hex(to_srgb8(map_to_srgb_gamut(c))) << ' ';
    std::cout << '\n';

    auto analog = analogous(base, 5, 30.0f);
    std::cout << delta_e(a, b) << '\n';
}