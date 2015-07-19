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
template <
  bool Level
, typename Output
, typename Out
>
class logstream {
public:
  /* ctor */
  explicit
  logstream(
    Output &
  , bool
  , Out const &
  );

  template <typename T>
  logstream<Level,Output,Out> &
  operator<<(
    T const &
  );

  /* ctor copy */
  logstream(
    logstream<Level,Output,Out> const &
  ) = default;

  /* assignment operator copy */
  logstream<Level,Output,Out> &
  operator=(
    logstream<Level,Output,Out> const &
  ) = default;

#if __cplusplus >= 201103L
  /* move*/
  logstream(
    logstream<Level,Output,Out> &&
  ) = default;

  logstream<Level,Output,Out> &
  operator=(
    logstream<Level,Output,Out> &&
  ) = default;
#endif

private:
  Output * stream;
  Out const & out;
  bool const state;
};

/* logstream disabled */
template <typename Output, typename Out>
class logstream<false,Output,Out> {
public:
  /* ctor */
  explicit
  logstream(
    Output const &
  , bool
  , Out const &
  );

  template <typename T>
  inline constexpr
  logstream<false,Output,Out> const &
  operator<<(
    T const &
  ) const;

  /* ctor copy */
  logstream(
    logstream<false,Output,Out> const &
  ) = default;

  /* assignment operator copy */
  logstream<false,Output,Out> &
  operator=(
    logstream<false,Output,Out> const &
  ) = default;

#if __cplusplus >= 201103L
  /* move*/
  logstream(
    logstream<false,Output,Out> &&
  ) = default;

  logstream<false,Output,Out> &
  operator=(
    logstream<false,Output,Out> &&
  ) = default;
#endif
};

} /* bits */ } /* streamlog */
#include "logstream.tcc"
#endif
