#include <forward_list>
#include <vector>

#include "print.hpp"
#include "sort.hpp"

void task1(const char* direction)
{
  Direction dir = getDirection(direction);

  std::vector<int> vectorBr;
  int num = 0;
  while (std::cin >> num)
  {
    vectorBr.push_back(num);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::ios_base::failure("Fail while reading data.");
  }

  if (vectorBr.empty())
  {
    return;
  }

  std::vector<int> vectorAt = vectorBr;
  std::forward_list<int> listIt(vectorBr.begin(), vectorBr.end());

  selectionSort<BrAccess>(vectorBr, dir);
  selectionSort<AtAccess>(vectorAt, dir);
  selectionSort<ItAccess>(listIt, dir);

  print(vectorBr);
  print(vectorAt);
  print(listIt);
}
