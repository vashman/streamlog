// example filtering loglevels.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/loglevel.hpp"
#include "../src/loglevel.cpp"

using streamlog::loglevel;

int main(){
try {

loglevel<true> lvl1;
loglevel<true> lvl2;
loglevel<true> const lvl3(false);
loglevel<true> const lvl4;

set_loglevel(lvl1);

lvl1.disable();
  } catch(...) {
  return 1;
  }
return 0;
}
