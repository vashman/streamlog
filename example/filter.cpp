// example filtering loglevels.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){
try {

loglevel lvl1;
loglevel lvl2;
loglevel const lvl3(false);
loglevel const lvl4;

loglevel::setlevel(lvl1);

lvl1.deactivate();
  } catch(...) {
  return 1;
  }
return 0;
}
