#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){
try {

loglevel lvl1;
loglevel lvl2;

lvl1.deactivate();

  } catch (...) {
  return 1;
  }
return 0;
}
