#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){
try {

loglevel lvl1;
loglevel lvl2;

loglevel::setlevel(lvl1);

  } catch(...) {
  return 1;
  }
return 0;
}
