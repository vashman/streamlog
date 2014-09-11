// Logging functions

// Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STREAMLOG_LOGGER_HPP
#define STREAMLOG_LOGGER_HP

#include "loglevel.hpp"

namespace streamlog {

template <typename CharT, typename Traits>
streamlog::bits::logstream_stream<CharT,Traits> &
logger(loglevel &, std::basic_ostream<CharT,Traits> &);

}/* streamlog */
#include "bits/logging.tcc"
#endif
