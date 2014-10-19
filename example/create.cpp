#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){

try {

/* create two loglevel instaces. */
loglevel level_name;
loglevel level_name2;
loglevel level_name3(level_name);

  } catch (...) {
  return 1;
  }

return 0;
}
