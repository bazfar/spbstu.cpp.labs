#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include "point.hpp"

void task1()
{
  std::set<std::string> words_;
  std::string input;
  while (getline(std::cin, input))
  {
    geoShapes::clearSpace(input);
    while (!input.empty())
    {
      auto pos = input.find_first_of(" \n\t");
      std::string newWord = input.substr(0, pos);
      input.erase(0, pos);
      words_.insert(newWord);
      geoShapes::clearSpace(input);
    }
  }

  for (auto i = words_.begin(); i != words_.end(); i++)
  {
    std::cout << *i << "\n";
  }
}
