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

#ifndef GAME_STATE_IMPL_HPP
#define GAME_STATE_IMPL_HPP

#include "ec/component_container.hpp"
#include "ec/component_id.hpp"
#include "ec/entity_container.hpp"
#include "game/game_state_interface.hpp"

#include <vector>

class Entity;

class Game_state_impl : public Game_state_interface
{
public:
    Game_state_impl();
    ~Game_state_impl() override = default;

    const Component_container& get_components()
    {
        return m_components;
    }

    const Entity_container& get_entities()
    {
        return m_entities;
    }

private:
    // Component container: represents current state of entities
    Component_container m_components;
    Entity_container m_entities;
};

#endif
