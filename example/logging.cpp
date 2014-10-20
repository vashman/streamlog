#include <iostream>
#include "../include/logger.hpp"

using streamlog::loglevel;
using streamlog::logger;

int main(){
loglevel lvl1;

int var = 42;

logger(lvl1, std::clog) << "log text" << var;

return 0;
}
