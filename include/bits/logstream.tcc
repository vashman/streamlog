//

//          Copyright Sundeep S. Sangha 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef STREAMLOG_BITS_LOGSTREAM_STREAM_TCC
#define STREAMLOG_BITS_LOGSTREAM_STREAM_TCC

namespace streamlog {
namespace bits {

/* logstream_stream ctor */
template <bool Level, typename ostreamT>
logstream<Level,ostreamT>::logstream (
  ostreamT & _stream
, bool _state
)
: logstream_base ()
, stream (& _stream)
, state (_state){
}

/* logstream_stream ctor disabled  */
template <typename ostreamT>
logstream<false,ostreamT>::logstream (
  ostreamT const & _stream
, bool _state
)
: logstream_base (){
}

/* logstream_stream operator << */
template <bool Level, typename ostreamT>
template <typename T>
logstream<Level,ostreamT> &
logstream<Level,ostreamT>::operator <<(
  T const & _value
){
  if (this->state == true){
  *this->stream << _value;
  }
return *this;
}

template <typename ostreamT>
template <typename T>
logstream<false,ostreamT> const &
logstream<false,ostreamT>::operator <<(
  T const & _value
){
return *this;
}

} /* bits */ } /* streamlog */
#endif
