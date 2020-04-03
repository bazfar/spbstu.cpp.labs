#include <iostream>
#include <stdexcept>
#include <string>

void task1(const char* direction);
void task2(const char* filename);
void task3();
void task4(const char* direction, size_t size);

int main(int argc, char* argv[])
{
  try
  {
    if ((argc < 2) || (argc > 4))
    {
      std::cerr << "Incorrect number of arguments.\n";
      return 1;
    }
    
    switch (std::stoi(argv[1]))
    {
    case 1:
      if (argc != 3)
      {
        std::cerr << "Incorrect number of arguments.\n";
        return 1;
      }
      if (argv[2] == nullptr)
        {
          std::cerr << "Invalid argument";
        }
      
        task1(argv[2]);
      break;

    case 2:
      if (argc != 3)
      {
        std::cerr << "Incorrect number of arguments.\n";
        return 1;
      }
      if (argv[2] == nullptr)
        {
          std::cerr << "Invalid argument";
        }

        task2(argv[2]);
      break;

    case 3:
      if (argc != 2)
      {
        std::cerr << "Incorrect number of arguments.\n";
        return 1;
      }
      
      task3();
      break;

    case 4:
      if (argc != 4)
      {
        std::cerr << "Incorrect number of arguments.\n";
        return 1;
      }
      if (argv[2] == nullptr)
        {
          std::cerr << "Invalid argument";
        }

          task4(argv[2], std::stoi(argv[3]));
      break;

    default:
      std::cerr << "Incorrect argument.\n";
      return 1; 
    }
    
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';

    return 1;
  }

  return 0;
}
