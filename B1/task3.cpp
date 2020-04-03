#include <vector>

#include "print.hpp"

void task3()
{
  std::vector<int> vector;
  int num = 0;
  bool metZero = false;

  while (std::cin >> num)
  {
    if (num == 0)
    {
      metZero = true;
      break;
    }

    vector.push_back(num);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::ios_base::failure("Fail while reading data.");
  }

  if (vector.empty())
  {
    return;
  }

  if (!metZero)
  {
    throw std::runtime_error("No zero.");
  }

  switch (vector.back())
  {
  case 1:
    for (auto i = vector.begin(); i != vector.end();)
    {
      i = ((*i % 2) == 0) ? vector.erase(i) : ++i;
    }
    break;

  case 2:
    for (auto i = vector.begin(); i != vector.end();)
    {
      i = ((*i % 3) == 0) ? (vector.insert(++i, 3, 1) + 3) : ++i;
    }
    break;

  default:
    break;
  }

  print(vector);
}
