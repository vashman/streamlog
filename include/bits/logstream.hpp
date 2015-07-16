//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_BITS_LOGSTREAM_STREAM_HPP
#define STREAMLOG_BITS_LOGSTREAM_STREAM_HPP

namespace streamlog {
namespace bits {

/* logstream_stream
*/
template <bool Level, typename ostreamT>
class logstream {
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

  /* ctor copy */
  logstream(
    logstream<Level,ostreamT> const &
  ) = default;

  /* assignment operator copy */
  logstream<Level,ostreamT> &
  operator=(
    logstream<Level,ostreamT> const &
  ) = default;

#if __cplusplus >= 201103L
  /* move*/
  logstream(
    logstream<Level,ostreamT> &&
  ) = default;

  logstream<Level,ostreamT> &
  operator=(
    logstream<Level,ostreamT> &&
  ) = default;
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
  ) const;

  /* ctor copy */
  logstream(
    logstream<false,ostreamT> const &
  ) = default;

  /* assignment operator copy */
  logstream<false,ostreamT> &
  operator=(
    logstream<false,ostreamT> const &
  ) = default;

#if __cplusplus >= 201103L
  /* move*/
  logstream(
    logstream<false,ostreamT> &&
  ) = default;

  logstream<false,ostreamT> &
  operator=(
    logstream<false,ostreamT> &&
  ) = default;
#endif
};

} /* bits */ } /* streamlog */
#include "logstream.tcc"
#endif
