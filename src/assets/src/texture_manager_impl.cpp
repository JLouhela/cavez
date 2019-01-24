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

#include <memory>
#include "assets/texture_id.hpp"
#include "res_path.hpp"
#include "texture_manager_impl.hpp"

namespace
{
void load_textures(Texture_map& texture_map)
{
    sf::Texture ship_tex;
    if (ship_tex.loadFromFile(asset::resource_path + "textures/ship.png"))
    {
        texture_map[asset::texture::ship_tex] = std::move(ship_tex);
    }
}
}  // namespace

Texture_manager_impl::Texture_manager_impl()
{
    // TODO: open an interface to switch assets
    // TODO: generate asset path from cmake
    // TODO: think how the path should be generated for release
    // Now depends on git
    // Load a texture from a file
    load_textures(m_textures);
}

const sf::Texture& Texture_manager_impl::get_texture(const Texture_id id) const
{
    auto iter = m_textures.find(id);
    if (iter == m_textures.end())
    {
        static const sf::Texture invalid_texture;
        return invalid_texture;
    }
    return iter->second;
}

std::unique_ptr<Texture_manager_interface> make_texture_manager()
{
    return std::make_unique<Texture_manager_impl>();
}
