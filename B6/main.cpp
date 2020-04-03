#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include "functor.hpp"

int main()
{
  Functor functor;
  std::for_each(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), std::ref(functor));

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Fail while readng\n";
    return 1;
  }

  functor.showAll();
  return 0;
}
