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

#include "math/bresenham.hpp"
#include <cstdlib>

namespace math
{
std::vector<Vector2I> get_line(const Vector2I& from, const Vector2I& to)
{
    // From rosettacode: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B
    std::int32_t x1 = from.x;
    std::int32_t y1 = from.y;
    std::int32_t x2 = to.x;
    std::int32_t y2 = to.y;

    const bool steep = (abs(y2 - y1) > abs(x2 - x1));
    if (steep)
    {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }

    if (x1 > x2)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    const std::int32_t dx = x2 - x1;
    const std::int32_t dy = abs(y2 - y1);

    float error = static_cast<float>(dx) / 2.0f;
    const std::int32_t y_step = (y1 < y2) ? 1 : -1;

    std::vector<Vector2I> res;
    for (std::int32_t x = x1, y = y1; x < x2; ++x)
    {
        if (steep)
        {
            res.push_back({y, x});
        }
        else
        {
            res.push_back({x, y});
        }
        error -= static_cast<float>(dy);
        if (error < 0)
        {
            y += y_step;
            error += static_cast<float>(dx);
        }
    }
    return res;
}
}  // namespace math
