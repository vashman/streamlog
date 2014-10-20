// example creating and using loglevels.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){

try {

/* create two loglevel instaces. */
loglevel level_name;
loglevel level_name2;
/* copy construct a third instance */
loglevel level_name3(level_name);

  if (level_name.is_active()){
  std::cout << "starting and level_name is active" << std::endl;
  }

  if (level_name2.is_active()){
  std::cout << "starting and info is active" << std::endl;
  }

  if (level_name3.is_active()){
  std::cout << "starting and debug is active" << std::endl;
  }

  } catch (...) {
  return 1;
  }

return 0;
}
