#ifndef STREAMLOG_BITS_LOGSTREAM_STREAM_TCC
#define STREAMLOG_BITS_LOGSTREAM_STREAM_TCC

namespace streamlog {
namespace bits {

/* logstream_stream ctor */
template <typename CharT, typename Traits>
logstream_stream<CharT,Traits>::logstream_stream(
  std::basic_ostream<CharT,Traits> & _stream
)
  : logstream_base (logstream_stream<CharT,Traits>::id())
  , stream (& _stream) {
}

/* logstream_stream log_id */
template <typename CharT, typename Traits>
typename logstream_base::id_type const
logstream_stream<CharT,Traits>::log_id = logstream_base::total_id++;

/* logstream_stream id */
template <typename CharT, typename Traits>
typename logstream_base::id_type
logstream_stream<CharT,Traits>::id(
){
return logstream_stream<CharT,Traits>::log_id;
}

/* logstream_stream operator << */
template <typename CharT, typename Traits>
template <typename T>
logstream_stream<CharT,Traits> &
logstream_stream<CharT,Traits>::operator <<(
  T const & _value
){
  if (this->active == true){
  *this->stream << _value;
  }
return *this;
}

/* logstream_stream set_stream */
template <typename CharT, typename Traits>
void
logstream_stream<CharT,Traits>::set_stream(
  std::basic_ostream<CharT,Traits> & _stream
){
this->stream = & _stream;
}

} /* bits */ } /* streamlog */
#endif
