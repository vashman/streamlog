// Logging levels, and level control.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGLEVEL_HPP
#define STREAMLOG_LOGLEVEL_HPP

#include <ostream>
#include "bits/logstream_stream.hpp"

namespace streamlog {

class loglevel{
public:
  /* unsigned int is used to avoid
    modulus with negative numbers when
    checking activation, and
    deactivating the level. 
  */
  typedef unsigned int lvl_type;

  /* ctor */
  loglevel(
    bool _state = true
  );

  /* copy ctor with modifying level */
  loglevel(
    loglevel const &
  , bool _state
  );

#if __cplusplus >= 201103L
  /* loglevel */
  explicit
  loglevel(
    loglevel const &
  ) = default;

  /* operator = */
  loglevel &
  operator=(
    loglevel const &
  ) = default;

  explicit
  loglevel(
    loglevel &&
  ) = default;

  loglevel &
  operator=(
    loglevel &&
  ) = default;
#endif

  bool
  is_active() const;

  bool
  is_deactive() const;

  void
  activate();

  void
  deactivate();

  static lvl_type
  getlevel();

  static lvl_type
  setlevel(
    loglevel const &
  );

private:
  /* 0 equals an inactive log */
	 lvl_type lvl;

  /* */
  streamlog::bits::logstream_base
  * log_obj;

  /* current global log level */
  static lvl_type log_lvl;

  /* total log levels */
  static lvl_type total;

  template <
    typename CharT
  , typename Traits
  >
  friend streamlog::bits
    ::logstream_stream<CharT,Traits> &
  logger(
    loglevel &
  , std::basic_ostream<CharT,Traits> &
  );
};

} /* streamlog */
#endif