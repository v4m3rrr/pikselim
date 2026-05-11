#include "pikselim/core/app.hh"

#include <iostream>

int main()
{
  pikselim::core::App app;
  std::cout<<"Value: "<<app.test()<<std::endl;
  return 0;
}
