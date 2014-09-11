//

#ifndef STREAMLOG_LOGLEVEL_CPP
#define STREAMLOG_LOGLEVEL_CPP

#include "../include/loglevel.hpp"

#if __cplusplus < 201103L
#define nullptr NULL
#endif

namespace streamlog {

/* logstream ctor */
loglevel::loglevel(
)
	: lvl ((++loglevel::total)++)
  , log_obj (nullptr) {
}

/**/
bool
loglevel::is_active(
) const {
  if (this->lvl != 0){
    if (((this->lvl % 2) != 0) && (this->lvl <= loglevel::loglvl())){
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
loglevel::loglvl(
){
return loglevel::log_lvl;
}

typename loglevel::lvl_type
loglevel::loglvl(
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
