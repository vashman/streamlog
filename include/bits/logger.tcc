//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGGER_TCC
#define STREAMLOG_LOGGER_TCC

#include <limits>

namespace streamlog {

/**/
template <typename CharT, typename Traits>
streamlog::bits::logstream_stream<CharT, Traits> &
logger(
  loglevel & _log
, std::basic_ostream<CharT,Traits> & _stream
){
streamlog::bits::logstream_base * iter = _log.log_obj;
if (iter == nullptr){
  _log.log_obj
    = new streamlog::bits::logstream_stream<CharT,Traits>(_stream);
  _log.log_obj->active = _log.is_active();
  return static_cast<streamlog::bits::logstream_stream<CharT,Traits> &>
    (* _log.log_obj);
}

  while (iter->id !=
           streamlog::bits::logstream_stream<CharT,Traits>::id()){
    if (iter == nullptr){
    iter = new streamlog::bits::logstream_stream<CharT,Traits>(_stream);
    iter->active = _log.is_active();
    return static_cast<streamlog::bits::logstream_stream<CharT,Traits> &>
      (* iter);
    }
  iter = iter->get_next();
  }
streamlog::bits::logstream_stream<CharT,Traits> & log_obj
 = static_cast<streamlog::bits::logstream_stream<CharT,Traits> &>(* iter);
log_obj.set_stream(_stream);
log_obj.active = _log.is_active();
return log_obj;
}

} /* streamlog */
#endif
