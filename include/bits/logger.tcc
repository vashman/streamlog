//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGGER_TCC
#define STREAMLOG_LOGGER_TCC

#include <limits>

namespace streamlog {

/* logger */
template <typename ostreamT>
bits::logstream_stream<ostreamT>
logger(
  loglevel & _log
, ostreamT & _stream
){
return
logstream(_stream, _log.is_active());
}

} /* streamlog */
#endif
