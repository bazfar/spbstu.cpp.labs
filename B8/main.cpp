#include <iostream>
#include <cstring>
#include "task.hpp"

const size_t MinWidth = 25;

int main(int argc, char* argv[])
{
  try
  {
    if ((argc > 3) || (argc == 1))
    {
      throw std::invalid_argument("Incorrect count of argc");
    }
    size_t width = 40;
    if (argc == 3)
    {
      if (std::strcmp(argv[1], "--line-width") != 0)
      {
        throw std::invalid_argument("Not correct argv");
      }
      width = std::stoi(argv[2]);
      if (width < MinWidth)
      {
        throw std::invalid_argument("Line width must be greater than 25");
      }
    }

    task text(width);
    text.read();
    text.print();
  }

  catch (const std::exception &exception)
  {
    std::cerr << exception.what();
    return 1;
  }

  return 0;
}
