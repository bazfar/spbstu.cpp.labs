#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>

void recursivePrint(std::list<int>::iterator begin, std::list<int>::iterator end)
{
  if (begin == end)
  {
    std::cout << "\n";

    return;
  }

  if (begin == std::prev(end))
  {
    std::cout << *begin << "\n";

    return;
  }

  std::cout << *begin << " " << *std::prev(end) << " ";

  ++begin;
  --end;

  recursivePrint(begin, end);
}

void task2()
{
  const int minValue = 1;
  const int maxValue = 20;
  const int maxSize = 20;

  std::list<int> list(0);
  int num = 0;

  while (std::cin >> num)
  {
    if ((num < minValue) || (num > maxValue))
    {
      throw std::invalid_argument("One of the numbers is invalid.");
    }
    list.push_back(num);

    if (list.size() > maxSize)
    {
      throw std::invalid_argument("Too many numbers.");
    }
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::ios_base::failure("Failed to read data.");
  }

  recursivePrint(list.begin(), list.end());
}
