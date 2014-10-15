// loglevel implementation.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_LOGLEVEL_CPP
#define STREAMLOG_LOGLEVEL_CPP

#include <limits>
#include "../include/loglevel.hpp"

#if __cplusplus < 201103L
#define nullptr NULL
#endif

namespace streamlog {

/* loglevel ctor */
loglevel::loglevel(
  bool _state
)
  : lvl ((++loglevel::total)++)
  , log_obj (nullptr) {
  if (_state == false){
  this->deactivate();
  }
}

/* loglevel ctor copy modify */
loglevel::loglevel(
  loglevel const & _lvl
, bool _state
)
  : lvl (_lvl.lvl)
  , log_obj (nullptr) {
  if (_state == false){
  this->deactivate();
  }
}

/**/
bool
loglevel::is_active(
) const {
  if (this->lvl != 0){
    if (((this->lvl % 2) != 0) && (this->lvl <= loglevel::getlevel())){
    return true;
    }
  }
return false;
}

/**/
bool
loglevel::is_deactive(
) const {
return !this->is_active();
}

/**/
typename loglevel::lvl_type
loglevel::getlevel(
){
return loglevel::log_lvl;
}

typename loglevel::lvl_type
loglevel::setlevel(
  loglevel const & _log
){
typename loglevel::lvl_type temp = loglevel::log_lvl;
loglevel::log_lvl = _log.lvl; 
return temp;
}

/**/
void
loglevel::activate(
){
  if ((this->lvl % 2) == 0){
  --this->lvl;
  }
}

/**/
void
loglevel::deactivate(
){
  if ((this->lvl % 2) != 0){
  ++this->lvl;
  }
}

/**/
typename loglevel::lvl_type
loglevel::total
  = std::numeric_limits<typename loglevel::lvl_type>::min();

/**/
typename loglevel::lvl_type
loglevel::log_lvl = loglevel::total;

} /* streamlog */
#if __cplusplus < 201103L
#undef nullptr
#endif
#endif
