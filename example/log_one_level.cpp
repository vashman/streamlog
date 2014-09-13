#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){
try {

loglevel level_name;
loglevel level_name2(level_name);

  } catch (...) {
  return 1;
  }
return 0;
}
