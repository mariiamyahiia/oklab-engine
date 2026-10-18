
| **Decision** | **Choice** | **Reason** |
| :-: | :-: | :-: |
| Scalar type | `float`, behind one alias `using real = float;` | Fast and compact; one-line change later. Fix it at build time, because changing it breaks ABI. |
| ***Types** | ***Plain aggregates: `struct OKLab \{ real L, a, b; \};`** | ***Trivially copyable, no allocation, `OKLab\{1,0,0\}` works** |
| Spaces | `SRGB8`, `SRGB`, `LinearRGB`, `OKLab`, `OKLCH` as distinct types | Compile-time protection |
| Hue unit | **Degrees, `\[0, 360\]`** | Human-friendly; documented in the header |
| Conversions | Free functions named by destination: `to\_oklab(x)` accepts any space | Small, predictable API |
| Clamping | Float conversions never clamp; `to\_srgb8` clamps and rounds | Narrowing conversions saturate; float math keeps out-of-gamut info |
| Recoverable errors | `std::optional` (e.g. `parse\_hex`) | Bad user input is expected |
| Programming errors | Documented precondition + `assert` (e.g. empty gradient) | A bug, not a runtime condition |
| Exceptions | None thrown; core is `noexcept` | Embedded- and `-fno-exceptions`-friendly |
| Gradients | `Gradient` object: `at(t)` allocation-free, `sample(n)` returns a vector | Matches “no heap in core” for the hot path |
| Mixing | **`mix(a, b, t)`: `t` is the weight of `b`, not clamped** | A weighted mix is just `t`; extrapolation allowed |
| Fixed-size harmonies | Return `std::array` | No allocation |
| Variable-size harmonies | Return `std::vector` | Count is a runtime value |

