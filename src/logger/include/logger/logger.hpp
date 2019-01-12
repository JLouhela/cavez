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

#ifndef logger_HPP
#define logger_HPP

#include "logger/output_interface.hpp"

#include <memory>
#include <sstream>
#include <vector>

// Based on http://www.drdobbs.com/cpp/logging-in-c/201804215
// Inefficient, consider switching to something else
// e.g. https://github.com/gabime/spdlog later

// Entry point for the users of logger.h are these macros:
#define LOG_INFO                                   \
    if ((diagnostic::logger::OUTPUT_LOG_LEVEL &    \
         diagnostic::logger::loglevel::INFO) == 0) \
        ;                                          \
    else                                           \
        diagnostic::logger::Log_entry().get(diagnostic::logger::loglevel::INFO)

#define LOG_WARN                                      \
    if ((diagnostic::logger::OUTPUT_LOG_LEVEL &       \
         diagnostic::logger::loglevel::WARNING) == 0) \
        ;                                             \
    else                                              \
        diagnostic::logger::Log_entry().get(          \
            diagnostic::logger::loglevel::WARNING)

#define LOG_ERR                                     \
    if ((diagnostic::logger::OUTPUT_LOG_LEVEL &     \
         diagnostic::logger::loglevel::ERROR) == 0) \
        ;                                           \
    else                                            \
        diagnostic::logger::Log_entry().get(diagnostic::logger::loglevel::ERROR)

#define LOG_DEBUG                                   \
    if ((diagnostic::logger::OUTPUT_LOG_LEVEL &     \
         diagnostic::logger::loglevel::DEBUG) == 0) \
        ;                                           \
    else                                            \
        diagnostic::logger::Log_entry().get(diagnostic::logger::loglevel::DEBUG)

// Usage LOG_WARN << message;

// Internal stuff
namespace diagnostic
{
namespace logger
{
namespace loglevel
{
typedef unsigned short Bit_mask;
const static Bit_mask INFO = 1;
const static Bit_mask WARNING = 2;
const static Bit_mask ERROR = 4;
const static Bit_mask DEBUG = 8;
}  // namespace loglevel

const static loglevel::Bit_mask LOG_ALL =
    diagnostic::logger::loglevel::ERROR |
    diagnostic::logger::loglevel::WARNING | diagnostic::logger::loglevel::INFO |
    diagnostic::logger::loglevel::DEBUG;

const static loglevel::Bit_mask UP_TO_INFO =
    diagnostic::logger::loglevel::ERROR |
    diagnostic::logger::loglevel::WARNING | diagnostic::logger::loglevel::INFO;

// TOOD allow runtime setting
const static loglevel::Bit_mask OUTPUT_LOG_LEVEL = LOG_ALL;

class Log_entry
{
public:
    Log_entry();
    ~Log_entry();
    Log_entry(const Log_entry&) = delete;

    std::ostringstream& get(loglevel::Bit_mask level);

private:
    Log_entry& operator=(const Log_entry&);

    std::vector<std::unique_ptr<Output_interface> > m_outputs;
    std::ostringstream m_stringstream;
};
}  // namespace logger
}  // namespace diagnostic

#endif
