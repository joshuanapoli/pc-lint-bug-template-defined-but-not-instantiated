// This file demonstrates a bug in PC-Lint with tracking instantiated template
// member functions.
//
// Both Base::function_overloaded_in_derived and
// Derived::function_overloaded_in_derived are instantiated by calls in main().
// However, PC-Lint does not recognize these instantiations and erroneously
// issues diagnostic 1795.
//
//PC-lint for C/C++ (NT) Vers. 9.00j, Copyright Gimpel Software 1985-2012
//
//--- Module:   main.cpp (C++)
//
//--- Global Wrap-up
//
//main.cpp(35): error 1795: (Info -- Template 'Base::function_overloaded_in_derived(const struct A &, <1>) const' (line 35, file main.cpp) was defined but not instantiated)
//main.cpp(44): error 1795: (Info -- Template 'Derived::function_overloaded_in_derived(const struct B &, <1>) const' (line 44, file main.cpp) was defined but not instantiated)
//error 900: (Note -- Successful completion, 2 messages produced)


//lint -e1790

#include <iostream>

struct A
{
};

struct B
{
};

struct Base
{
  template<typename T>
  void function_overloaded_in_derived(const ::A&, T) const
  {
    ::std::cout << "overload 1\n";
  }
};

struct Derived : public Base
{
  template<typename T>
  void function_overloaded_in_derived(const ::B&, T) const
  {
    ::std::cout << "overload 2\n";
  }
  using Base::function_overloaded_in_derived;
};

int main()
{
  A a;
  B b;
  Derived derived;
  derived.function_overloaded_in_derived(a, 1);
  derived.function_overloaded_in_derived(b, 2);
}
