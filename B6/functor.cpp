#include "functor.hpp"
#include <iostream>

Functor::Functor():
  max(0),
  min(0),
  mean(0),
  countPositive(0),
  countNegative(0),
  sumOdd(0),
  sumEven(0),
  first(0),
  coincides(true),
  countNumbers(0)
{ }

void Functor::operator()(int num)
{
  if ((countPositive) == 0 && (countNegative == 0))
  {
    min = num;
    max = num;
    first = num;
  }
  countNumbers++;
  if (max < num)
  {
    max = num;
  }
  else if (min > num)
  {
    min = num;
  }
  if (num > 0)
  {
    countPositive++;
  }
  else if (num < 0)
  {
    countNegative++;
  }
  (num % 2 == 0) ? sumEven += num : sumOdd += num;
  coincides = (first == num) ? true : false;
  mean = (static_cast<double>(sumEven) + static_cast<double>(sumOdd)) / static_cast<double>(countNumbers);
}

void Functor::showAll() const
{
  if (countNumbers == 0)
  {
    std::cout << "No Data\n";
    return;
  }
  std::cout << "Max: " << max << "\n";
  std::cout << "Min: " << min << "\n";
  std::cout << "Mean: " << mean << "\n";
  std::cout << "Positive: " << countPositive << "\n";
  std::cout << "Negative: " << countNegative << "\n";
  std::cout << "Odd Sum: " << sumOdd << "\n";
  std::cout << "Even Sum: " << sumEven << "\n";
  std::string str = (coincides) ? "yes" : "no";
  std::cout << "First/Last Equal: " << str << "\n";
}
