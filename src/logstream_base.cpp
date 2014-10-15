//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_BITS_LOGSTREAM_BASE_CPP
#define STREAMLOG_BITS_LOGSTREAM_BASE_CPP

#include <limits>
#include "../include/bits/logstream_base.hpp"

#if __cplusplus < 201103L
#include <stddef.h>
#define nullptr NULL
#endif

namespace streamlog {
namespace bits {

/* logstream_base ctor */
logstream_base::logstream_base(
  typename logstream_base::id_type _id
)
  : id (_id) 
  , active (true)
  , log_obj (nullptr) {
}

/* logstream_base dtor */
logstream_base::~logstream_base(
){
  if (this->log_obj != nullptr){
  delete log_obj;
  }
}

/* logstream_base set_next */
void
logstream_base::set_next(
  logstream_base & _obj
){
this->log_obj = & _obj;
}

/**/
logstream_base *
logstream_base::get_next(
) const {
return this->log_obj;
}

/* logstream_base total_id */
typename logstream_base::id_type
logstream_base::total_id
  = std::numeric_limits<typename logstream_base::id_type>::min();

} /* bits */ } /* streamlog */

#if __cplusplus < 201103L
#undef nullptr
#endif
#endif
