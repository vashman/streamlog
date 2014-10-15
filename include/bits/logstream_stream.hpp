//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_BITS_LOGSTREAM_STREAM_HPP
#define STREAMLOG_BITS_LOGSTREAM_STREAM_HPP

#include <ostream>
#include "logstream_base.hpp"

namespace streamlog {
namespace bits {

/* logstream_stream
*/
template <typename CharT, typename Traits>
class logstream_stream : public logstream_base{
public:
  explicit
  logstream_stream(
    std::basic_ostream<CharT, Traits> &
  );

  template <typename T>
  logstream_stream<CharT, Traits> &
  operator<<(
    T const &
  );

  static typename logstream_base::id_type
  id();

  void
  set_stream(
    std::basic_ostream<CharT,Traits> &
  );

#if __cplusplus >= 201103L
  logstream_stream(
    logstream_stream<CharT, Traits> const &
  ) = delete;

  logstream_stream<CharT,Traits> &
  operator=(
    logstream_stream<CharT,Traits> const &
  ) = delete;

  logstream_stream(
    logstream_stream<CharT,Traits> &&
  ) = delete;

  logstream_stream<CharT,Traits> &
  operator=(
    logstream_stream<CharT,Traits> &&
  ) = delete;
#endif

private:
  std::basic_ostream<CharT,Traits> * stream;

  static typename logstream_base::id_type const log_id;
};

} /* bits */ } /* streamlog */
#include "logstream_stream.tcc"
#endif
