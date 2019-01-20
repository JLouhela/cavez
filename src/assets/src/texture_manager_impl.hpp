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

#ifndef TEXTURE_MANAGER_IMPL_HPP
#define TEXTURE_MANAGER_IMPL_HPP

#include <cstdint>
#include <unordered_map>
#include "SFML/Graphics/Texture.hpp"
#include "assets/texture_manager_interface.hpp"

using Texture_map = std::unordered_map<Texture_id, sf::Texture>;

const static sf::Texture invalid_texture;

class Texture_manager_impl : public Texture_manager_interface
{
public:
    Texture_manager_impl();
    ~Texture_manager_impl() override = default;

    const sf::Texture& get_texture(Texture_id id) override;

private:
    Texture_map m_textures;
};

#endif
