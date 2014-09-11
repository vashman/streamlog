Tutorial
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
3. Logging
  1. Basic Logging
  2. Logging to multiple locations
  3. Adding a new type to output

2 Log Levels
==========================================================================
1 Creating log levels
--------------------------------------------------------------------------
Log levels are an instance of the `loglevel` class. Each instance of the
class Adds a level with a severity level one less than the previous.
There for the most severe levels comes first.

[example: loglevel.cpp](../example/loglevel.cpp)
```c++
loglevel level_name;
loglevel level_name2;
```

Creating a `loglevel` with the same level as one all ready created,
can be achieved by simply copy constructing a `loglevel`.

[example: log_one_level.cpp](../example/log_one_level.cpp)
```c++
loglevel level_name;
loglevel level_name2(level_name);
```

2 Filtering log levels
--------------------------------------------------------------------------
To filter all log levels by severity level, the static member function
`setlevel` can be used. The function takes a `loglevel` instance as an
argument, All log levels higher than it (instantiated after it) are
filtered out.

[example: filter_global.cpp](../example/filter_global.cpp)
```c++
loglevel lvl1;
loglevel lvl2;

loglevel::setlevel(lvl1);
```

3 Filtering specific level
--------------------------------------------------------------------------
To filter out a specific level

[example: filter_specfic.cpp](../example/filter_specific.cpp)
```c++
loglevel lvl1;
loglevel lvl2;

lvl1.deactivate();
```

3 Logging
==========================================================================
1 Basic Logging
--------------------------------------------------------------------------
[example: logging.cpp](../example/logging.cpp)
```c++
logger(lvl1, std::clog) << "log text" << var;
```

2 Logging to multiple locations
--------------------------------------------------------------------------

3 Adding a new type to output
--------------------------------------------------------------------------