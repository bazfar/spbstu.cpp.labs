#ifndef B7_Data_HPP
#define B7_Data_HPP

#include <vector>

class Data
{
public:
  void operator()(double num);
  void output();

private:
  std::vector<double> vec;
};


#endif
