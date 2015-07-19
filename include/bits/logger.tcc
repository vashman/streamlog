//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGGER_TCC
#define STREAMLOG_LOGGER_TCC

namespace streamlog {

/* logger */
template <
  bool Level
, typename Output
, typename Out
>
bits::logstream<Level,Output,Out>
logger(
  loglevel<Level> & _log
, Output & _stream
, Out const & _out
){
return
bits::logstream<Level,Output,Out>
(_stream, _log.is_enabled(), _out);
}

} /* streamlog */
#endif
