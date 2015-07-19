// Logging levels, and level control.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGLEVEL_HPP
#define STREAMLOG_LOGLEVEL_HPP

#include "bits/logstream.hpp"

namespace streamlog {
/* This unsigned int type is used to avoid
  modulus with negative numbers when
  checking activation, and
  deactivating the level. 
*/
typedef unsigned int loglevel_type;

/* loglevel */
template <bool Level>
class loglevel {};

inline loglevel_type
get_loglevel();

void
set_loglevel(
  loglevel<true> const & _level
);

void
set_loglevel(
  loglevel<false> const & _level
);

namespace bits {
loglevel_type
new_loglevel();
} /* bits */

/* loglevel */
template <>
class loglevel<true> {
public:
  /* ctor */
  loglevel(
    bool const _state = true
  );

  /* ctor copy modifying level true
    Copies the loglevel and then
    activates / deactivates this
    loglevel.
  */
  loglevel(
    loglevel<true> const &
  , bool _state
  );

  /* ctor copy modifying level false
    Copies the disabled loglevel as a
    enabled loglevel. Then sets this
    loglevels state.
  */
  loglevel(
    loglevel<false> const &
  , bool _state
  );

#if __cplusplus >= 201103L
  /* ctor copy */
  explicit
  loglevel(
    loglevel<true> const &
  ) = default;
  
  /* ctor copy
    Copy disabled statement as an
    enabled statement.
  */
  explicit
  loglevel(
    loglevel<false> const &
  );

  /* assignment operator */
  loglevel<true> &
  operator=(
    loglevel<true> const &
  ) = default;

  /* assignment operator */
  loglevel<true> &
  operator=(
    loglevel<false> const &
  );

  /* ctor move */
  explicit
  loglevel(
    loglevel<true> &&
  ) = default;

  /* ctor move */
  explicit
  loglevel(
    loglevel<false> &&
  );

  /* assignment operator move */
  loglevel<true> &
  operator=(
    loglevel<true> &&
  ) = default;

  /* assignment operator move */
  loglevel<true> &
  operator=(
    loglevel<false> &&
  );
#endif

  bool
  is_enabled() const;

  bool
  is_disabled() const;

  void
  enable();

  void
  disable();

private:
  /* lvl is a binary value which may be
    disabled.
  */
  loglevel_type lvl;

  /* current global log level */
  static loglevel_type log_lvl;

  /* total log levels */
  static loglevel_type total;
  
  friend class loglevel<false>;
  friend loglevel_type get_loglevel();

  friend loglevel_type
  bits::new_loglevel();

  friend void
  set_loglevel(
    loglevel<true> const &
  );
  
  friend void
  set_loglevel(
    loglevel<false> const &
  );
};

/* loglevel
  A disabled loglevel always remains
  inactive.
*/
template <>
class loglevel<false> {
public:
  /* ctor */
  loglevel(
    bool const _state = false
  );

  /* ctor copy modifying level true */
  loglevel(
    loglevel<false> const &
  , bool const
  );

  /* ctor copy modifying level false */
  loglevel(
    loglevel<true> const &
  , bool const
  );

#if __cplusplus >= 201103L
  /* ctor copy */
  explicit
  loglevel(
    loglevel<false> const &
  ) = default;
  
  /* ctor copy */
  explicit
  loglevel(
    loglevel<true> const &
  );

  /* assignment operator */
  loglevel<false> &
  operator=(
    loglevel<false> const &
  ) = default;

  /* assignment operator */
  loglevel<false> &
  operator=(
    loglevel<true> const &
  );

  /* ctor move */
  explicit
  loglevel(
    loglevel<true> &&
  );

  /* ctor move */
  explicit
  loglevel(
    loglevel<false> &&
  ) = default;

  /* assignment operator move */
  loglevel<false> &
  operator=(
    loglevel<true> &&
  );

  /* assignment operator move */
  loglevel<false> &
  operator=(
    loglevel<false> &&
  ) = default;
#endif

  bool
  is_enabled() const;

  bool
  is_disabled() const;

  void
  enable() const;

  void
  disable();

  static inline loglevel_type
  getlevel();

  static loglevel_type
  setlevel(
    loglevel<true> const &
  );

  static loglevel_type
  setlevel(
    loglevel<false> const &
  );

private:
  /* lvl is a binary value which may be
    disabled.
  */
  loglevel_type lvl;

  friend class loglevel<true>;
  
  friend void
  set_loglevel(
    loglevel<false> const &
  );
};

} /* streamlog */
#endif