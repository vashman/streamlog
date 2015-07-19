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
template <
  bool Level
, typename Output
, typename Out
>
logstream<Level,Output,Out>::logstream (
  Output & _stream
, bool _state
, Out const & _out
)
: stream (& _stream)
, out (_out)
, state (_state){
}

/* logstream_stream ctor disabled  */
template <typename Output, typename Out>
logstream<false,Output,Out>::logstream (
  Output const & _stream
, bool _state
, Out const & _out
){
}

/* logstream_stream operator << */
template <
  bool Level
, typename Output
, typename Out
>
template <typename T>
logstream<Level,Output,Out> &
logstream<Level,Output,Out>::operator <<(
  T const & _value
){
  if (this->state == true){
  this->out(*this->stream, _value);
  }
return *this;
}

template <typename Output, typename Out>
template <typename T>
inline constexpr
logstream<false,Output,Out> const &
logstream<false,Output,Out>::operator<<(
  T const & _value
) const {
return *this;
}

} /* bits */ } /* streamlog */
#endif
