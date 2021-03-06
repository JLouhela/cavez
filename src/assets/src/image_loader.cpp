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

#include "assets/image_loader.hpp"
#include "SFML/Graphics/Image.hpp"
#include "logger/logger.hpp"
#include "res_path.hpp"

namespace
{
std::vector<asset::Color> get_colors(const sf::Image& image)
{
    std::vector<asset::Color> res;
    const auto size = image.getSize();
    for (std::uint32_t y = 0; y < size.y; ++y)
    {
        for (std::uint32_t x = 0; x < size.x; ++x)
        {
            sf::Color pixel = image.getPixel(x, y);
            res.emplace_back(pixel.r, pixel.g, pixel.b, pixel.a);
        }
    }
    return res;
}
}  // namespace

namespace asset
{
Image load_image(const std::string& name)
{
    sf::Image img;
    if (!img.loadFromFile(resource_path + name))
    {
        LOG_ERR << "Failed to load file " + name;
        return Image{{}, 0, 0};
    }

    std::vector<Color> colors = get_colors(img);
    return {colors, img.getSize().x, img.getSize().y};
}
}  // namespace asset
