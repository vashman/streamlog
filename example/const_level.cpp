// example creating and use const loglevels.

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){

try {

loglevel const fatel(false);
loglevel const info;
loglevel const debug(false);

  if (fatel.is_active()){
  std::cout << "starting and fatel is active" << std::endl;
  }

  if (info.is_active()){
  std::cout << "starting and info is active" << std::endl;
  }

  if (debug.is_active()){
  std::cout << "starting and debug is active" << std::endl;
  }

loglevel::setlevel(debug);

  if (fatel.is_active()){
  std::cout << "after level set, fatel is still active" << std::endl;
  }

  if (info.is_active()){
  std::cout << "after level set, info is still active" << std::endl;
  }

  if (debug.is_active()){
  std::cout << "after level set, debug is still active" << std::endl;
  }

  } catch (...) {
  return 1;
  }
return 0;
}
