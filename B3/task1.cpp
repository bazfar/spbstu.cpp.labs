#include <sstream>
#include <iostream>
#include "tasks.hpp"
#include "commands.hpp"
void task1()
{
  BookmarkManager bookManager;
  std::string line;
  while (std::getline(std::cin, line))
  {
    std::stringstream in(line);
    std::string command;
    in >> command;

    if (command.compare("add") == 0)
    {
      add(bookManager, in);
    }
    else if (command.compare("store") == 0)
    {
      store(bookManager, in);
    }
    else if (command.compare("insert") == 0)
    {
      insert(bookManager, in);
    }
    else if (command.compare("delete") == 0)
    {
      remove(bookManager, in);
    }
    else if (command.compare("show") == 0)
    {
      show(bookManager, in);
    }
    else if (command.compare("move") == 0)
    {
      move(bookManager, in);
    }
    else
    {
      std::cout << "<INVALID COMMAND>" << '\n';
    }
  }
}
