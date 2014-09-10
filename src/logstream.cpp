//

#ifndef STREAMLOG_LOGSTREAM_CPP
#define STREAMLOG_LOGSTREAM_CPP

#include "../include/logstream.hpp"

#if __cplusplus < 201103L
#define nullptr NULL
#endif

namespace streamlog {

/* logstream ctor */
logstream::logstream(
)
	: lvl ((++logstream::total)++)
  , log_obj (nullptr) {
}

/**/
bool
logstream::is_active(
) const {
  if (this->lvl != 0){
    if (((this->lvl % 2) != 0) && (this->lvl <= logstream::loglvl())){
    return true;
    }
  }
return false;
}

/**/
bool
logstream::is_deactive(
) const {
return !this->is_active();
}

/**/
typename logstream::lvl_type
logstream::loglvl(
){
return logstream::log_lvl;
}

typename logstream::lvl_type
logstream::loglvl(
  logstream const & _log
){
typename logstream::lvl_type temp = logstream::log_lvl;
logstream::log_lvl = _log.lvl; 
return temp;
}

/**/
void
logstream::activate(
){
  if ((this->lvl % 2) == 0){
  --this->lvl;
  }
}

/**/
void
logstream::deactivate(
){
  if ((this->lvl % 2) != 0){
  ++this->lvl;
  }
}

/**/
typename logstream::lvl_type
logstream::total
  = std::numeric_limits<typename logstream::lvl_type>::min();

/**/
typename logstream::lvl_type
logstream::log_lvl = logstream::total;

} /* streamlog */
#if __cplusplus < 201103L
#undef nullptr
#endif
#endif
