// loglevel implementation.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGLEVEL_TCC
#define STREAMLOG_LOGLEVEL_TCC

#include <limits>
#include "../include/loglevel.hpp"

namespace streamlog {

loglevel_type
loglevel<true>::total (
    std
  ::numeric_limits<loglevel_type>::min()
);

loglevel_type
loglevel<true>::log_lvl (
    std
  ::numeric_limits<loglevel_type>::min()
);

/* get_loglevel */
loglevel_type
get_loglevel(){
return loglevel<true>::log_lvl;
}

/* set_loglevel */
void
set_loglevel(
  loglevel<true> const & _level
){
loglevel<true>::log_lvl = _level.lvl;
}

/* set_loglevel */
void
set_loglevel(
  loglevel<false> const & _level
){
loglevel<true>::log_lvl = _level.lvl;
}

namespace bits {
/* new_loglevel */
loglevel_type
new_loglevel(){
return (++loglevel<true>::total)++;
}
} /* bits */

/* loglevel ctor true */
loglevel<true>::loglevel (
  bool const _state
)
: lvl (bits::new_loglevel()) {
  if (_state == false)
  this->disable();
}

/* loglevel ctor copy modify true */
loglevel<true>::loglevel(
  loglevel<true> const & _lvl
, bool _state
)
: lvl (_lvl.lvl) {
  if (_state == false)
  this->disable();
}

/* ctor copy modify level */
loglevel<true>::loglevel(
  loglevel<false> const & _lvl
, bool _state
)
: lvl (_lvl.lvl) {
  if (_state == false)
  this->disable();
}

/* ctor copy */
loglevel<true>::loglevel(
  loglevel<false> const & _lvl
)
: lvl (_lvl.lvl) {
}

/* assignment operator */
loglevel<true> &
loglevel<true>::operator= (
    loglevel<false> const & _rhs
){
this->lvl = _rhs.lvl;
return *this;
}

/* ctor move */
loglevel<true>::loglevel (
  loglevel<false> && _other
)
: lvl (_other.lvl) {
}

/* assignment operator move */
loglevel<true> &
loglevel<true>::operator=(
  loglevel<false> && _rhs
){
this->lvl = _rhs.lvl;
return *this;
}

/* is_enabled
  Does not check if level is set to
  zero.
*/
bool
loglevel<true>::is_enabled (
) const {
return (
  ((this->lvl % 2) != 0)
&&
  this->lvl <= get_loglevel()
);
}

/* is_disabled */
bool
loglevel<true>::is_disabled (
) const {
return !this->is_enabled();
}

/* enable */
void
loglevel<true>::enable (
){
  if ((this->lvl % 2) == 0)
  --this->lvl;
}

/* disable */
void
loglevel<true>::disable (
) {
  if ((this->lvl % 2) != 0)
  ++this->lvl;
}

/* Disabled Loglevel */

/* loglevel ctor */
loglevel<false>::loglevel (
  bool const _state
)
: lvl ((++loglevel<true>::total)++) {
this->disable();
}

/* loglevel ctor copy modify */
loglevel<false>::loglevel(
  loglevel<false> const & _lvl
, bool const _state
)
: lvl (_lvl.lvl) {
}

/* loglevel ctor copy modify */
loglevel<false>::loglevel(
  loglevel<true> const & _lvl
, bool const _state
)
: lvl (_lvl.lvl) {
this->disable();
}

/* ctor copy */
loglevel<false>::loglevel (
  loglevel<true> const & _other
)
: lvl (_other.lvl) {
this->disable();
}

/* assignment operator
  There is no need to check if the other
  instance is the same as this. Since it
  is a different type all together.
*/
loglevel<false> &
loglevel<false>::operator=(
  loglevel<true> const & _other
){
this->lvl = _other.lvl;
this->disable();
return *this;
}

/* ctor move */
loglevel<false>::loglevel(
  loglevel<true> && _other
)
: lvl (_other.lvl) {
this->disable();
}

/* assignment operator move */
loglevel<false> &
loglevel<false>::operator=(
  loglevel<true> && _other
){
this->lvl = _other.lvl;
this->disable();
return *this;
}

/* is_enabled */
bool
loglevel<false>::is_enabled(
) const {
return false;
}

/* is_disabled */
bool
loglevel<false>::is_disabled(
) const {
return true;
}

/* enable */
void
loglevel<false>::enable(
) const {
}

/* disable */
void
loglevel<false>::disable(
){
  if ((this->lvl % 2) != 0)
  ++this->lvl;
}

} /* streamlog */
#endif
