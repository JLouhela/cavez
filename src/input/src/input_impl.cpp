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
#include <memory>

namespace
{
// TODO sflm key from input_key
}

Input_impl::Input_impl()
{
}

void Input_impl::update()
{
    // TODO read keys from sfml, assign states based on mappings
}

input::Input_id Input_impl::register_listener(const input::Input_mapping& input_mapping)
{
    // TODO register mapping, assign id, return assigned id
    return input::Input_id();
}

const input::Input_state& Input_impl::get_state(input::Input_id id)
{
    static input::Input_state invalid_state;
    auto iter = m_input_states.find(id);
    return iter == m_input_states.end() ? invalid_state : *iter;
}

std::unique_ptr<Input_interface> make_input()
{
    return std::make_unique<Input_impl>();
}
