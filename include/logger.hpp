// Logging functions

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGGER_HPP
#define STREAMLOG_LOGGER_HPP

#include "loglevel.hpp"

namespace streamlog {
/* logger */
template <
  bool Level = true
, typename ostreamT
>
bits::logstream<Level,ostreamT> &
logger(
  loglevel &
, ostreamT &
);

} /* streamlog */
#include "bits/logger.tcc"
#endif
