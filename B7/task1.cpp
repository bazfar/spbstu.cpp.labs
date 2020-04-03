#define _USE_MATH_DEFINES

#include"data.hpp"

#include <functional>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <math.h>

void Data::operator()(double num)
{
    double nextNumber = M_PI * num;
    vec.push_back(nextNumber);
}

void Data::output()
{
    if (vec.empty())
    {
     return;
    }
    std::for_each(vec.begin(), vec.end(), [](double num) {std::cout << num << " "; });
}

void task1()
{
  Data numbs;
  std::for_each(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(), std::ref(numbs));

  if (!std::cin.eof())
  {
    throw std::ios_base::failure("Couldn't read\n");
  }

  numbs.output();
}
