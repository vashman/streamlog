//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_BITS_LOGSTREAM_STREAM_HPP
#define STREAMLOG_BITS_LOGSTREAM_STREAM_HPP

#include "logstream_base.hpp"

namespace streamlog {
namespace bits {

/* logstream_stream
*/
template <bool Level, typename ostreamT>
class logstream : public logstream_base{
public:
  /* ctor */
  explicit
  logstream(
    ostreamT &
  , bool
  );

  template <typename T>
  logstream<Level,ostreamT> &
  operator<<(
    T const &
  );

#if __cplusplus >= 201103L
  /* ctor copy */
  logstream(
    logstream<Level,ostreamT> const &
  ) = delete;

  /* assignment operator copy */
  logstream<Level,ostreamT> &
  operator=(
    logstream<Level,ostreamT> const &
  ) = delete;

  /* move*/
  logstream(
    logstream<Level,ostreamT> &&
  ) = delete;

  logstream<Level,ostreamT> &
  operator=(
    logstream<Level,ostreamT> &&
  ) = delete;
#endif

private:
  ostreamT * stream;
  bool const state;
};

/* logstream disabled */
template <typename ostreamT>
class logstream<false,ostreamT> {
public:
  /* ctor */
  explicit
  logstream(
    ostreamT const &
  , bool
  );

  template <typename T>
  logstream<false,ostreamT> const &
  operator<<(
    T const &
  );

#if __cplusplus >= 201103L
  /* ctor copy */
  logstream(
    logstream<false,ostreamT> const &
  ) = delete;

  /* assignment operator copy */
  logstream<false,ostreamT> &
  operator=(
    logstream<false,ostreamT> const &
  ) = delete;

  /* move*/
  logstream(
    logstream<false,ostreamT> &&
  ) = delete;

  logstream<false,ostreamT> &
  operator=(
    logstream<false,ostreamT> &&
  ) = delete;
#endif
};

} /* bits */ } /* streamlog */
#include "logstream.tcc"
#endif
