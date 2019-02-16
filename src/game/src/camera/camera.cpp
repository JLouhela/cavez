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

#include "camera/camera.hpp"

Camera::Camera(const math::Rect& screen_rect, const math::Rect& world_rect)
    : m_screen_rect{screen_rect}, m_world_rect{world_rect}, m_world_pos{0, 0}
{
}

void Camera::set_position(const math::Vector2& world_position)
{
    m_world_pos = world_position;
}

// TODO take scale into account
std::pair<bool, math::Vector2> Camera::get_screen_position(
    const math::Vector2& world_position) const
{
    math::Vector2 screen_pos{world_position.x - m_world_pos.x, world_position.y - m_world_pos.y};
    if (screen_pos.x >= m_screen_rect.x && screen_pos.x < m_screen_rect.x + m_screen_rect.w &&
        screen_pos.y > m_screen_rect.y && screen_pos.y < m_screen_rect.y + m_screen_rect.h)
    {
        return std::make_pair(true, screen_pos);
    }
    return std::make_pair(false, screen_pos);
}

std::pair<bool, math::Bounding_box> Camera::get_screen_area(
    const math::Bounding_box& world_area) const
{
    auto top_left = get_screen_position(world_area.top_left);
    auto bottom_right = get_screen_position(world_area.bottom_right);
    return {top_left.first || bottom_right.first, {top_left.second, bottom_right.second}};
}

std::pair<bool, math::Rect> Camera::get_screen_rect(const math::Rect& world_rect) const
{
    const auto res = get_screen_area(math::Bounding_box{
        world_rect.x, world_rect.y, world_rect.x + world_rect.w, world_rect.y + world_rect.h});
    return {res.first, {res.second.top_left.x, res.second.top_left.y, world_rect.w, world_rect.h}};
}
