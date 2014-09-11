#include <iostream>
#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){
loglevel lvl1;

int var = 42;

logger(lvl1, std::cout) << "log text" << var;

return 0;
}
