//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_BITS_LOGSTREAM_BASE_HPP
#define STREAMLOG_BITS_LOGSTREAM_BASE_HPP

namespace streamlog {
namespace bits {

/**/
class logstream_base{
public:
  typedef int id_type;

  logstream_base(id_type);

  virtual
  ~logstream_base();

  void
  set_next(logstream_base &);

  logstream_base *
  get_next() const;

  id_type const id;

  static id_type total_id;

  bool active;

private:
  logstream_base * log_obj;
};

} /* bits */ } /* streamlog */
#endif
