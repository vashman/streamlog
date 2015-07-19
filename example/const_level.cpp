// example creating and use const loglevels.

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
/* Once the loglevels have been set,
  they cannot be disabled / enabled.
*/
loglevel<true> const fatel(false);
loglevel<true> const info;
loglevel<true> const debug(false);

  if (fatel.is_enabled()){
  std::cout
  << "starting and fatel is active"
  << std::endl;
  }

  if (info.is_enabled()){
  std::cout
  << "starting and info is active"
  << std::endl;
  }

  if (debug.is_enabled()){
  std::cout
  << "starting and debug is active"
  << std::endl;
  }

set_loglevel(debug);

  if (fatel.is_enabled()){
  std::cout
  << "After level set, fatel is still"
     " not active."
  << std::endl;
  }

  if (info.is_enabled()){
  std::cout
  << "After the loglevel is set, info"
     " becomes active."
  << std::endl;
  }

  if (debug.is_enabled()){
  std::cout
  << "After level set, debug is still"
     " not active."
  << std::endl;
  }

  } catch (...) {
  return 1;
  }
return 0;
}
