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

#include "input_impl.hpp"
#include <cstdint>
#include <memory>
#include <set>
#include "SFML/Window/Keyboard.hpp"
#include "input/input_key.hpp"

namespace
{
std::set<input::Key> get_keys_down()
{
    std::set<input::Key> result;
    // There's 1:1 mapping between SFML and input_key => dirty loop
    for (std::int16_t i = 0; i < static_cast<std::int16_t>(sf::Keyboard::KeyCount); ++i)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i)))
        {
            result.insert(static_cast<input::Key>(i));
        }
    }
    return result;
}

}  // namespace

void Input_impl::update()
{
    reset_states();
    auto keys_down = get_keys_down();
    for (const auto& listener : m_input_listeners)
    {
        const auto& input_mapping = listener.second;
        if (keys_down.find(input_mapping.rotate_ccw) != keys_down.end())
        {
            m_input_states[listener.first].rotate_ccw = true;
        }
        if (keys_down.find(input_mapping.rotate_cw) != keys_down.end())
        {
            m_input_states[listener.first].rotate_cw = true;
        }
        if (keys_down.find(input_mapping.shoot) != keys_down.end())
        {
            m_input_states[listener.first].shoot = true;
        }
        if (keys_down.find(input_mapping.shoot_special) != keys_down.end())
        {
            m_input_states[listener.first].shoot_special = true;
        }
        if (keys_down.find(input_mapping.shield) != keys_down.end())
        {
            m_input_states[listener.first].shield = true;
        }
        if (keys_down.find(input_mapping.throttle) != keys_down.end())
        {
            m_input_states[listener.first].throttle = true;
        }
    }
}

void Input_impl::reset_states()
{
    for (auto& state : m_input_states)
    {
        state.second = input::Input_state{};
    }
}

input::Input_id Input_impl::register_listener(const input::Input_mapping& input_mapping)
{
    m_input_listeners[m_next_free_id] = input_mapping;
    return m_next_free_id++;
}

const input::Input_state& Input_impl::get_state(input::Input_id id) const
{
    static input::Input_state invalid_state;
    auto iter = m_input_states.find(id);
    return iter == m_input_states.end() ? invalid_state : iter->second;
}

void Input_impl::deregister_listener(input::Input_id id)
{
    auto iter = m_input_states.find(id);
    if (iter == m_input_states.end())
    {
        return;
    }
    m_input_states.erase(iter);
}

std::unique_ptr<Input_interface> make_input()
{
    return std::make_unique<Input_impl>();
}
