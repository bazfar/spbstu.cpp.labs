#include "commands.hpp"

#include <algorithm>
#include <sstream>

commands::execute_command commands::parseTaskArguments(std::istream& input)
{
  struct command_t
  {
    const char* name;
    std::function<execute_command(std::istream&)> action;
  };

  static const command_t Commands[] =
  {
    {"add", &parseAddArguments},
    {"get", &parseGetArguments},
    {"accelerate", &parseAccelerateArguments}
  };

  std::string commandName;
  input >> commandName;

  auto command = std::find_if(std::begin(Commands), std::end(Commands),
      [&](const command_t& command) {return commandName == command.name;});

  if (command != std::end(Commands))
  {
    return command->action(input);
  }
  else
  {
    return std::bind([&](std::ostream& output){output << "<INVALID COMMAND>\n";}, _2);
  }
}

commands::execute_command commands::parseAddArguments(std::istream& input)
{
  struct priority_t
  {
    const char* name;
    element_priority priority;
  };

  static const priority_t Priorities[] =
  {
    {"low", element_priority::LOW},
    {"normal", element_priority::NORMAL},
    {"high", element_priority::HIGH}
  };

  std::string priority;
  input >> priority;

  auto elementPriority = std::find_if(std::begin(Priorities), std::end(Priorities),
      [&](const priority_t& elementPriority) {return priority == elementPriority.name;});

  if (elementPriority == std::end(Priorities))
  {
    return std::bind([&](std::ostream& output){output << "<INVALID COMMAND>\n";}, _2);
  }

  std::string element;
  std::getline(input >> std::ws, element);
  if (element.empty())
  {
    return std::bind([&](std::ostream& output){output << "<INVALID COMMAND>\n";}, _2);
  }

  return std::bind([&](string_queue& queue, std::string& element, element_priority& priority)
      {queue.putElementToQueue(element, priority);}, _1, element, elementPriority->priority);
}

commands::execute_command commands::parseGetArguments(std::istream& input)
{
  std::string data;
  std::getline(input >> std::ws, data);

  if (!data.empty())
  {
    return std::bind([&](std::ostream& output){output << "<INVALID COMMAND>\n";}, _2);
  }

  return std::bind([&](string_queue& queue, std::ostream& output)
      {
        if (queue.empty())
        {
          output << "<EMPTY>\n";

          return;
        }

        queue.getElementFromQueue([&](std::string element) {output << element << "\n";});
      }, _1, _2);
}

commands::execute_command commands::parseAccelerateArguments(std::istream& input)
{
  std::string data;
  std::getline(input >> std::ws, data);

  if (!data.empty())
  {
    return std::bind([&](std::ostream& output){output << "<INVALID COMMAND>\n";}, _2);
  }

  return std::bind([&](string_queue& queue, std::ostream& output)
      {
        if (queue.empty())
        {
          output << "<EMPTY>\n";

          return;
        }

        queue.accelerate();
      }, _1, _2);
}
