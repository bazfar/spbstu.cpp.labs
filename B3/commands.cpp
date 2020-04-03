#include <sstream>
#include <iostream>
#include <cctype>
#include "commands.hpp"

std::string getNumber(std::string& number)
{
  if (number.empty())
  {
    return "";
  }

  for (auto i : number)
  {
    if (!std::isdigit(i))
    {
      return "";
    }
  }
  return number;
}

std::string getName(std::string& name)
{
  if (name.empty())
  {
    return "";
  }

  if (name.front() != '\"')
  {
    return "";
  }

  name.erase(name.begin());

  size_t i = 0;
  while (i < name.size() && name[i] != '\"')
  {
    if (name[i] == '\\')
    {
      if (name[i + 1] == '\"' && i + 2 < name.size())
      {
        name.erase(i, 1);
      }
      else
      {
        return "";
      }
    }
    i++;
  }
  if (i == name.size())
  {
    return "";
  }

  name.erase(i);

  if (name.empty())
  {
    return "";
  }

  return name;
}

std::string getMarkName(std::string& markname)
{
  if (markname.empty())
  {
    return "";
  }

  for (auto i : markname)
  {
    if (!isalnum(i) && i != '-')
    {
      return "";
    }
  }
  return markname;
}

void add(BookmarkManager& bookmanager, std::stringstream& in)
{
  std::string number;
  in >> std::ws >> number;

  std::string name;
  std::getline(in >> std::ws, name);

  number = getNumber(number);
  name = getName(name);

  if (number.empty() || name.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }
  bookmanager.add({ name, number });
}

void store(BookmarkManager& bookmanager, std::stringstream& in)
{
  std::string markname;
  in >> std::ws >> markname;

  std::string newMarkname;
  std::getline(in >> std::ws, newMarkname);

  markname = getMarkName(markname);
  newMarkname = getMarkName(newMarkname);

  if (markname.empty() || newMarkname.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }
  bookmanager.store(markname, newMarkname);
}

void insert(BookmarkManager& bookmanager, std::stringstream& in)
{
  std::string position;
  in >> std::ws >> position;

  std::string markname;
  in >> std::ws >> markname;

  std::string number;
  in >> std::ws >> number;

  std::string name;
  std::getline(in >> std::ws, name);

  markname = getMarkName(markname);
  number = getNumber(number);
  name = getName(name);

  if (markname.empty() || number.empty() || name.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }

  if (position.compare("before") == 0)
  {
    bookmanager.insert(markname, { name, number }, BookmarkManager::insertPosition::before);
  }
  else if (position.compare("after") == 0)
  {
    bookmanager.insert(markname, { name, number }, BookmarkManager::insertPosition::after);
  }
  else
  {
    std::cout << "<INVALID COMMAND" << '\n';
    return;
  }
}

void remove(BookmarkManager& bookmanager, std::stringstream& in)
{
  std::string markname;
  std::getline(in >> std::ws, markname);

  markname = getMarkName(markname);

  if (markname.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }

  bookmanager.remove(markname);
}

void show(BookmarkManager& bookmanager, std::stringstream& in)
{
  std::string markname;
  std::getline(in >> std::ws, markname);

  markname = getMarkName(markname);

  if (markname.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }

  bookmanager.show(markname);
}

void move(BookmarkManager& bookmanager, std::stringstream& in)
{
  std::string markname;
  in >> std::ws >> markname;

  std::string steps;
  std::getline(in >> std::ws, steps);

  markname = getMarkName(markname);

  if (markname.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }

  if (steps.compare("first") == 0)
  {
    bookmanager.move(markname, BookmarkManager::movePosition::first);
  }
  else if (steps.compare("last") == 0)
  {
    bookmanager.move(markname, BookmarkManager::movePosition::last);
  }

  else if (steps[0] == '-' || steps[0] == '+')
  {
    std::string str = steps;
    str = steps.substr(1, steps.length() - 1);
    str = getNumber(str);
    if (str.empty())
    {
      std::cout << "<INVALID STEP>" << '\n';
      return;
    }
    bookmanager.move(markname, std::stoi(steps));
  }
  else
  {
    steps = getNumber(steps);
    if (steps.empty())
    {
        std::cout << "<INVALID STEP>" << '\n';
        return;
    }
    bookmanager.move(markname, std::stoi(steps));
  }
  if (steps.empty())
  {
    std::cout << "<INVALID COMMAND>" << '\n';
    return;
  }
}
