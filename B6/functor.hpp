#ifndef FUNCTOR_HPP
#define FUNCTOR_HPP

#include <cstdio>

class Functor
{
public:
  Functor();
  void operator()(int num);
  void showAll() const;

private:
  int max;
  int min;
  double mean;
  size_t countPositive;
  size_t countNegative;
  long int sumOdd;
  long int sumEven;
  int first;
  bool coincides;
  size_t countNumbers;
};

#endif
