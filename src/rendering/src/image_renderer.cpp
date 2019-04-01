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

#include "image_renderer.hpp"
#include <cstdint>
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "logger/logger.hpp"
#include <cstddef>

namespace
{
sf::Color convert_color(const asset::Color& color)
{
    return sf::Color{color.r, color.g, color.b, color.a};
}
}

namespace asset
{
void render_to_target(const asset::Image& image, sf::RenderTarget& target)
{
    std::size_t vertex_count{0};
    for (const auto& pixel : image.get_pixels())
    {
        vertex_count = (pixel != Color{}) ? vertex_count + 1 : vertex_count;
    }
    if (vertex_count = 0)
    {
        LOG_WARN << "No vertices to render";
        return;
    }
    sf::Vertex vertices[vertex_count];
    for (std::uint32_t y = 0; y < image.get_height(); ++y)
    {
        for (std::uint32_t x = 0; x < image.get_width(); ++x)
        {
            const auto& pixel = image.get_pixel(x, y);
            if (pixel == Color{})
            {
                continue;
            }
            sf::Vertex vertex{sf::Vector2f{static_cast<float>(x), static_cast<float>(y)},
                              sf::Color{convert_color(pixel)}};
        }
    }
    target.draw(vertices, vertex_count, sf::PrimitiveType::Points);
}
}
