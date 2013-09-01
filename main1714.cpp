// This file demonstrates a bug in PC-Lint with tracking instantiated template
// functions.
//
// In this program, the template function increment::operator() is instantiated
// through a call to std::for_each. However, PC-Lint odes not recognize the
// instantiation and issues diagnostic 1714.
//
//PC-lint for C/C++ (NT) Vers. 9.00j, Copyright Gimpel Software 1985-2012
//
//--- Module:   main1714.cpp (C++)
//
//--- Global Wrap-up
//
//main.cpp(23): error 1714: (Info -- Member function 'increment::operator()(int &) const' (line 23, file main.cpp) not referenced)
//error 900: (Note -- Successful completion, 1 messages produced)

#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> x;
  x.push_back(0);
  std::vector<int>::iterator begin(x.begin());
  std::vector<int>::iterator end(x.end());
  (void)std::for_each(begin, end, increment());
  std::cout << x[0] << std::endl;
  return 0;
}
