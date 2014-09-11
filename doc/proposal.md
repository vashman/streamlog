Sundeep S. Sangha < <sun.sangha@gmail.com> >

September 10, 2014

1 Table of Contents
==========================================================================
1. Table of Contents
2. Introduction
3. Motivation and Scope
4. Impact On the Standard
5. Desgin Decisions

2 Introduction
==========================================================================
Logging that is easy to re-organize, whether adding new logging levels or
removing levels without breaking the code. Also provide granular control
over log filtering.

3 Motivation and Scope
==========================================================================
Logging libraries tend to offer a finite set of features where the user
must create thier logs based on the concepts defined by the library, or
more extensable feature set at the expensive of complexity and releabilty.

This libray provides a way to express log statments in such a way that
changing the overall logging settings or descision will not cause
problems. The library attempts to avoid marcos for everything thing except
optional addtions.

4 Impact On the Standard
==========================================================================

5 Desgin Decisions
==========================================================================
A. log levels
--------------------------------------------------------------------------
Log levels are class instances that provide access to them selves and
global log levels. Log levels are compared and expressed relative to other
log levels. Levels may be copy constructed in order to more than one
equivilent instance of the same level.

Every log level created is distinct to the ones before it, such that any
opertion on that level does not effect others. This provides more
granularity when setting log levels.

B. Checking log levels
--------------------------------------------------------------------------
Log levels are can be checked through member functions, so it is possible
for a user to inspect log levels prior to logging. The log filters the
levels for every agrument passed to it, there for it is possible that the
log level can change within a logging statment. 

Avoiding deactivated levels from being checked within the stream requires
checking them before hand and then modifying the logging statment in 

C. Logging with standard stream
--------------------------------------------------------------------------
The actual output is don via `std::basic_ostream`, while the logging
wrapper provides a way to filter out statments. This incresase the total
number of options and settings to match that of a standard stream.

When a logger object uses a standard stream object it will contain a
referance or pointer to that stream. Because of this the logger object
is non-copyable and non-movable. This ensures that the stream object is
not used outside of the scope of the logging statment. Leacing the end
user to break code only explictly with pointer.

D. Thread Safty
--------------------------------------------------------------------------

E. Logging Expressions
--------------------------------------------------------------------------

F. Changing Global Logging 
--------------------------------------------------------------------------

G. Adding Custom Logging Sinks
--------------------------------------------------------------------------
Logging uses `std::basic_ostream` and `std::basic_istream` for all input
and output operations, This allows all potential io sinks to be used for
logging.

