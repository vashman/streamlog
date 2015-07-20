Streamlog Tutorial
==========================================================================
Examples used in this tutorial are snippets of working examples found in
the examples directory.

1 Table of Contents
==========================================================================
1. Table of Contents
2. Log Levels
  1. Creating log levels
  2. Filtering log levels
  3. Filtering specific level
  4. Complie time filtering of log levels
  5. Constant Levels
  6. Checking Log Levels
3. Logging
  1. Basic Logging
  3. Adding a new type to output

2 Log Levels
==========================================================================
1 Creating log levels
--------------------------------------------------------------------------
Log levels are an instance of the `loglevel` class. Each instance of the
class Adds a level with a severity level one less than the previous.
There for the most severe levels comes first.

[example: create.cpp](../example/create.cpp)

```c++
loglevel<true> level_name;
loglevel<true> level_name2;
```

Creating a `loglevel` with the same level as one all ready created,
can be achieved by simply copy constructing a `loglevel`.

[example: create.cpp](../example/create.cpp)

```c++
loglevel<true> level_name3(level_name);
```

2 Filtering log levels
--------------------------------------------------------------------------
To filter all log levels by severity level, the static member function
`setlevel` can be used. The function takes a `loglevel` instance as an
argument, All log levels higher than it (instantiated after it) are
filtered out.

[example: filter.cpp](../example/filter.cpp)
```c++
loglevel<true> lvl1;
loglevel<true> lvl2;

set_loglevel(lvl1);
```

3 Filtering specific level
--------------------------------------------------------------------------
To filter out a specific level

[example: filter.cpp](../example/filter.cpp)

```c++
lvl1.disable();
```

[example: filter.cpp](../example/filter.cpp)

```c++
loglevel<true> const lvl3(false);

loglevel<true> const lvl4;
```
4 Complie time filtering of log levels
--------------------------------------------------------------------------
[example: filter_complie.cpp](../example/filter_complie.cpp)
```c++
loglevel<true> const lvl1;
loglevel<fale> cosnt lvl2;
loglevel<true> const lvl3;
```

5 Constant Levels
--------------------------------------------------------------------------
To create a constant loglevel that can not be activated or deactivated
later on, simply `const` qualify the loglevel;

[example: const_level.cpp](../example/const_level.cpp)
```c++
loglevel<true> const fatel;
```

6 Checking Log Levels
--------------------------------------------------------------------------
Whether a particular loglevel is active or inactive can be checked via the
member functions `is_enabled` and `is_disabled`.

[example: checking.cpp](../example/checking.cpp)

```c++
  if (fatel.is_enabled() == true)

  if (fatel.is_disabled() == true)
```

3 Logging
==========================================================================
1 Basic Logging
--------------------------------------------------------------------------
[example: logging.cpp](../example/logging.cpp)

```c++
logger(lvl1, std::clog) << "log text" << var;
```

2 Adding a new type to output
--------------------------------------------------------------------------
Adding a new type to output only requires and overload of the type for
`std::basic_ostream`, overloading for the `logstream` class should not be
attempted as there is no gurantee that the correct overload will be
seletecd. This may not raise any complier warnings or cause runtime errors
as the type should still be sent to `std::basic_ostream`.
