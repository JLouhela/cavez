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
#include "assets/image_loader.hpp"
#include "level/environment_mapping.hpp"

namespace
{
Level load_debug_level()
{
    std::vector<std::uint8_t> environment;
    const auto image = asset::load_image("debug_level.png");
    for (std::uint32_t x = 0; x < image.get_width(); ++x)
    {
        for (std::uint32_t y = 0; y < image.get_height(); ++y)
        {
            const auto pixel = image.get_pixel(x, y);
            environment.emplace_back(static_cast<uint8_t>(get_environment_type(pixel)));
        }
    }
    return Level{environment, asset::texture::debug_level};
}
}  // namespace

Level Level_builder::load_level(Level_id level_id)
{
    if (level_id == Level_id::Debug_level)
    {
        return load_debug_level();
    }
    return Level{{}, asset::texture::invalid_texture_id};
}
