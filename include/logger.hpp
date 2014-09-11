// Logging functions

// Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STREAMLOG_LOGGER_HPP
#define STREAMLOG_LOGGER_HP

namespace streamlog {

template <typename CharT, typename Traits>
streamlog::bits::logstream_stream<CharT,Traits> &
logger(logstream &, std::basic_ostream<CharT,Traits> &);

}/* streamlog */
#include "bits/logging.tcc"
#endif
