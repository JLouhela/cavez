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
#include "ec/entity_factory.hpp"
#include "game/game_state_interface.hpp"
#include "level/level.hpp"

#include <vector>

class Entity;
class Input_interface;

class Game_state_impl : public Game_state_interface
{
public:
    explicit Game_state_impl(Input_interface& input_interface);
    ~Game_state_impl() override = default;

    void initialize(Level level);

    const Component_container& get_components() const
    {
        return m_components;
    }

    Component_container& get_components()
    {
        return m_components;
    }

    const Entity_container& get_entities() const
    {
        return m_entities;
    }

    Entity_container& get_entities()
    {
        return m_entities;
    }

    const Level& get_level() const
    {
        return m_level;
    }

    Level& get_level()
    {
        return m_level;
    }

private:
    // Component container: represents current state of entities
    Component_container m_components;
    Entity_container m_entities;
    Entity_factory m_entity_factory;
    Level m_level;
};

#endif
