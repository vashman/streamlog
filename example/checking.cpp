// example checking loglevels

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/loglevel.hpp"

using streamlog::loglevel;

int main(){
try {

loglevel const fatel;
loglevel const info;
loglevel const debug;

  /**/
  if (fatel.is_active() == true){
  std::cout << "fatel is currently activated." << std::endl;
  }

  if (fatel.is_deactive() == true){
  std::cout << "fatel is currently deactivate." << std::endl;
  }

std::cout << "The current loglevel is: " << loglevel::getlevel()
  << std::endl;

  } catch (...) {
  return 1;
  }
return 0;
}
