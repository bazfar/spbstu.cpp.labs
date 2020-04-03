#include <iostream>
#include <string>
#include "tasks.hpp"
int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::invalid_argument("Invalid number of parameters");
    }
    switch(std::stoi(argv[1]))
    {
      case 1:
      {
        task1();
        break;
      }
      case 2:
      {
        task2();
        break;
      }
      default:
        std::cerr << "Invalid number of task";
        return 1;
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
