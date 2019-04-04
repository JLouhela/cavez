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
    Camera(std::int8_t id, const math::Rect& screen_rect, std::uint8_t scale);

    void set_position(const math::Vector2I& top_left);

    void center_position(const math::Vector2I& center);

    const math::Rect& get_screen_rect() const
    {
        return m_screen_rect;
    }

    math::Rect get_world_rect() const;
    
    // Return pair: first - within camera, second - translated coords
    std::pair<bool, math::Vector2I> get_screen_position(const math::Vector2I& world_position) const;

    // Return pair: first - within camera, second - translated area
    std::pair<bool, math::Bounding_box> get_screen_area(const math::Bounding_box& world_area) const;

    // Return pair: first - within camera, second - translated area
    std::pair<bool, math::Rect> get_screen_rect(const math::Rect& world_rect) const;

    std::int8_t get_id() const
    {
        return m_id;
    }

private:
    math::Vector2I m_world_pos;
    math::Rect m_screen_rect;
    std::int8_t m_id;
    std::uint8_t m_scale;
};

#endif
