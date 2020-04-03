#include <algorithm>
#include <iostream>
#include "tasks.hpp"
#include "factorialContainer.hpp"

void task2()
{
  FactorialContainer factorialContainer;
  std::copy(factorialContainer.begin(), factorialContainer.end(), std::ostream_iterator<unsigned long long>(std::cout, " "));
  std::cout << '\n';

  std::reverse_copy(factorialContainer.begin(), factorialContainer.end(), std::ostream_iterator<unsigned long long>(std::cout, " "));
  std::cout << '\n';
}
