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

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <cstdint>
#include <utility>
#include "math/bounding_box.hpp"
#include "math/rect.hpp"
#include "math/vector.hpp"

class Camera
{
public:
    Camera(const math::Rect& screen_rect, const math::Rect& world_rect);

    void set_position(const math::Vector2& world_position);

    // Return pair: first - within camera, second - translated coords
    std::pair<bool, math::Vector2> get_screen_position(const math::Vector2& world_position) const;

    // Return pair: first - within camera, second - translated area
    std::pair<bool, math::Bounding_box> get_screen_area(const math::Bounding_box& world_area) const;

    // Return pair: first - within camera, second - translated area
    std::pair<bool, math::Rect> get_screen_rect(const math::Rect& world_rect) const;

private:
    math::Vector2 m_world_pos;
    math::Rect m_screen_rect;
    math::Rect m_world_rect;
};

#endif
