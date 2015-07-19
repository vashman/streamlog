// Logging functions

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGGER_HPP
#define STREAMLOG_LOGGER_HPP

#include "loglevel.hpp"

namespace streamlog {
template <typename Output>
struct leftshift {
  template <typename T>
  void
  operator()(
    Output & _out
  , T const _var
  ) const {
  _out << _var;
  }
};

/* logger */
template <
  bool Level
, typename Output
, typename Out = leftshift<Output>
>
bits::logstream<Level,Output,Out>
logger(
  loglevel<Level> &
, Output &
, Out const & _out = Out()
);

} /* streamlog */
#include "bits/logger.tcc"
#endif
