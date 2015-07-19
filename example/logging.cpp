#include <iostream>
#include "../include/logger.hpp"
#include "../src/loglevel.cpp"

using streamlog::loglevel;
using streamlog::logger;

int main(){
loglevel<true> lvl1;

int var = 42;

logger(lvl1, std::clog)
<< "log text"
<< var;

return 0;
}
