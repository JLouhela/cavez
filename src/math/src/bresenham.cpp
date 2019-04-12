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
#include <cmath>

namespace math
{
namespace bresenham
{
// TODO should not swap but orientate from -> to
// -> study algorithm and adapt, also consider screen wrap (e.g. prev_pos y = 599, cur_pos y = 1)
std::vector<Vector2I> get_line(const Vector2F& from, const Vector2F& to)
{
    // From rosettacode: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C.2B.2B
    float x1 = from.x;
    float y1 = from.y;
    float x2 = to.x;
    float y2 = to.y;

    const bool steep = (std::fabs(y2 - y1) > std::fabs(x2 - x1));
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

    const float dx = x2 - x1;
    const float dy = std::fabs(y2 - y1);

    float error = static_cast<float>(dx) / 2.0f;
    const std::int32_t y_step = (y1 < y2) ? 1 : -1;

    std::vector<Vector2I> res;
    for (std::int32_t x = static_cast<std::int32_t>(x1), y = static_cast<std::int32_t>(y1);
         x < static_cast<std::int32_t>(x2); ++x)
    {
        if (steep)
        {
            res.push_back({y, x});
        }
        else
        {
            res.push_back({x, y});
        }
        error -= dy;
        if (error < 0)
        {
            y += y_step;
            error += dx;
        }
    }
    return res;
}
}
}  // namespace math
