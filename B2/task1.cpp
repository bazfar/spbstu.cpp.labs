#include <algorithm>
#include <sstream>

#include "commands.hpp"
#include "queue-with-priority.hpp"

void task1()
{
  QueueWithPriority<std::string> queue;
    
  std::string line;

  while (std::getline(std::cin, line))
  {
    std::stringstream input(line);

    commands::parseTaskArguments(input)(queue, std::cout);
  }
}
