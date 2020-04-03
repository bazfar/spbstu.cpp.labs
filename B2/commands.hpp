#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "queue-with-priority.hpp"

namespace commands
{
  using namespace std::placeholders;

  using string_queue = QueueWithPriority<std::string>;
  using element_priority = string_queue::ElementPriority;
  using execute_command = std::function<void(string_queue&, std::ostream&)>;

  execute_command parseTaskArguments(std::istream& input);
  execute_command parseAddArguments(std::istream& input);
  execute_command parseGetArguments(std::istream& input);
  execute_command parseAccelerateArguments(std::istream& input);
}

#endif
