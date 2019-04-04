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

#include "level/level_builder.hpp"
#include <type_traits>
#include "assets/image_loader.hpp"
#include "level/environment_mapping.hpp"
#include "logger/logger.hpp"
#include "rendering/rendering_interface.hpp"

namespace
{
Level load_debug_level(Rendering_interface& rendering_interface)
{
    std::vector<Environment_type> environment;
    const auto lvl_image = asset::load_image("levels/debug_level.png");
    for (std::uint32_t x = 0; x < lvl_image.get_width(); ++x)
    {
        for (std::uint32_t y = 0; y < lvl_image.get_height(); ++y)
        {
            const auto pixel = lvl_image.get_pixel(x, y);
            environment.emplace_back(get_environment_type(pixel));
        }
    }
    const auto lvl_overlay_img = asset::load_image("levels/debug_level_ol.png");
    const auto buffer_idx = rendering_interface.init_render_buffer(lvl_overlay_img);
    return Level{environment, lvl_image.get_width(), lvl_image.get_height(), buffer_idx};
}
}  // namespace

Level Level_builder::load_level(Rendering_interface& rendering_interface, Level_id level_id)
{
    LOG_INFO << "Loading level"; 
    if (level_id == Level_id::Debug_level)
    {
        LOG_INFO << "Level loaded";
        return load_debug_level(rendering_interface);
    }
    return Level{{}, 0U, 0U, asset::texture::invalid_texture_id};
}
