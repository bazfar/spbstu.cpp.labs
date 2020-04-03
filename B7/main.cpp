#include <iostream>
#include <stdexcept>
#include <string>

void task1();
void task2();


int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Invalid number of parameters\n";
    return 1;
  }
  try
  {
    switch (std::stoi(argv[1]))
    {
      case 1:
      {
        task1();
      }
        break;
      case 2:
      {
        task2();
      }
        break;
      default:
      {
        std::cerr << "Invalid number task\n";
        return 1;
      }
    }
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  return 0;
}
