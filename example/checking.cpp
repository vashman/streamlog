// example checking loglevels

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include "../include/loglevel.hpp"
#include "../src/loglevel.cpp"

using streamlog::loglevel;
using streamlog::get_loglevel;

int main(){
try {

loglevel<true> const fatel;
loglevel<true> const info;
loglevel<true> const debug;

  /* By default the global loglevel must
    be enabled by the user.
  */
  if (fatel.is_enabled() == true){
  std::cout
  << "fatel is currently activated."
  << std::endl;
  }

  if (fatel.is_disabled() == true){
  std::cout
  << "fatel is currently deactivated."
  << std::endl;
  }

std::cout
<< "The current loglevel is: "
<< get_loglevel()
<< std::endl;

  } catch (...) {
  std::clog << "Exception thrown";
  return 1;
  }
return 0;
}
