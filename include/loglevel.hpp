// General logging with stream objects, with control of log levels and multiple sinks.

//          Copyright Sundeep S. Sangha 2013 - 2014.

#ifndef STREAMLOG_LOGLEVEL_HPP
#define STREAMLOG_LOGLEVEL_HPP

#include <ostream>
#include "bits/logstream_stream.hpp"

namespace streamlog {

class loglevel{
public:
  typedef int lvl_type;

  loglevel();

#if __cplusplus >= 201103L
  explicit
  loglevel(
    loglevel const &
  ) = default;

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
  loglvl();

  static lvl_type
  loglvl(loglevel const &);

private:
	lvl_type lvl; // 0 equals an inactive log

  streamlog::bits::logstream_base * log_obj;

  static lvl_type log_lvl;

  static lvl_type total;

  template <typename CharT, typename Traits>
  friend streamlog::bits::logstream_stream<CharT,Traits> &
  logger(logstream &, std::basic_ostream<CharT,Traits> &);
};

} /* streamlog */
#endif
