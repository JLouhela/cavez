/// Copyright (c) 2019 Joni Louhela
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to
/// deal in the Software without restriction, including without limitation the
/// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
/// sell copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
/// IN THE SOFTWARE.

#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>

namespace asset
{
struct Color
{
    constexpr Color() : r{0}, g{0}, b{0}, a{0}
    {
    }
    constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
        : r{r}, g{g}, b{b}, a{a}
    {
    }
    constexpr Color(std::uint8_t r, std::uint8_t g, std::uint8_t b) : r{r}, g{g}, b{b}, a{255U}
    {
    }

    bool operator==(const Color& other) const;
    bool operator!=(const Color& other) const;

    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
    std::uint8_t a;
};

}  // namespace asset

#endif
