# Pretty Function Sandbox

This repo demonstrates how `__PRETTY_FUNCTION__` can be used in order
to get compile time type information.

As of now (Dec 2018), Clang and MSVC support this, GCC does not.

The rule of thumb is that the expression below should be supported
in order for this feature to be supported.


```cpp
    constexpr char const* pretty_function = __PRETTY_FUNCTION__;
```
