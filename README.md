PC-Lint bug with diagnostic 1795: Defined template ’Symbol’ was not instantiated
================================================================================

This repo demonstrates a bug in PC-Lint with tracking instantiated template
member functions.

Base::function_overloaded_in_derived and Derived::function_overloaded_in_derived
are class member template functions, instantiated by calls in main(). PC-Lint
does not recognize these instantiations. It erroneously issues diagnostic 1795
for both cases.

```
PC-lint for C/C++ (NT) Vers. 9.00j, Copyright Gimpel Software 1985-2012

--- Module:   main.cpp (C++)

--- Global Wrap-up

main.cpp(35): error 1795: (Info -- Template 'Base::function_overloaded_in_derived(const struct A &, <1>) const' (line 35, file main.cpp) was defined but not instantiated)
main.cpp(44): error 1795: (Info -- Template 'Derived::function_overloaded_in_derived(const struct B &, <1>) const' (line 44, file main.cpp) was defined but not instantiated)
error 900: (Note -- Successful completion, 2 messages produced)
```
