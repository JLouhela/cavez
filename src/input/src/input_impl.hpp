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

#ifndef INPUT_IMPL_HPP
#define INPUT_IMPL_HPP

#include "input/input_interface.hpp"
#include "input/input_mapping.hpp"
#include "input/input_state.hpp"

#include <unordered_map>

class Input_impl : public Input_interface
{
public:
    Input_impl();
    ~Input_impl() override = default;

    void update() override;
    void register_listener(input::Input_id id, const input::Input_mapping& input_mapping) override;
    const input::Input_state& get_state(input::Input_id id) const override;
    void deregister_listener(input::Input_id id) override;

private:
    std::unordered_map<input::Input_id, input::Input_mapping> m_input_listeners;
    std::unordered_map<input::Input_id, input::Input_state> m_input_states;
};

#endif
