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

#include <chrono>
#include <ctime>
#include "console_output.hpp"
#include "logger/logger.hpp"

namespace
{
std::string To_string(diagnostic::logger::loglevel::Bit_mask level)
{
    if ((level & diagnostic::logger::loglevel::DEBUG) > 0)
    {
        return "DEBUG";
    }
    if ((level & diagnostic::logger::loglevel::ERROR) > 0)
    {
        return "ERROR";
    }
    if ((level & diagnostic::logger::loglevel::WARNING) > 0)
    {
        return "WARNING";
    }
    if ((level & diagnostic::logger::loglevel::INFO) > 0)
    {
        return "INFO";
    }
    return "UNHANDLED_loglevel : " + level;
}
}  // namespace

namespace diagnostic
{
namespace logger
{
Log_entry::Log_entry()
{
    // This is definitely not performant way to log anything, do not care yet
    m_outputs.push_back(std::make_unique<Console_output>());
}

Log_entry::~Log_entry()
{
    for (auto& output : m_outputs)
    {
        if (output)
        {
            output->write(m_stringstream);
            output->flush();
        }
    }
}

std::ostringstream& Log_entry::get(loglevel::Bit_mask level)
{
    std::time_t time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    // TODO format timestamp
    m_stringstream << "[" << time << "] " << To_string(level) << ": ";
    return m_stringstream;
}

}  // namespace logger
}  // namespace diagnostic
