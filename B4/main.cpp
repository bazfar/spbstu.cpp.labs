#include <iostream>
#include <algorithm>
#include "DataStruct.hpp"
#include "functions.hpp"

int main()
{
  try
  {
    std::vector<DataStruct> vector = fillVector();
    std::sort(vector.begin(), vector.end(), compare);
    printVector(vector);

  }
  catch (std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }

  return 0;
}
