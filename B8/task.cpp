#include "task.hpp"
#include <iostream>
#include <algorithm>

const size_t MaxWidthWord = 20;

task::task(size_t width):
  width_(width),
  words_()
{ }

void task::read()
{
  while (std::cin)
  {
    std::cin >> std::noskipws;
    char first = std::cin.get();
    if ((((first == '+') || (first == '-')) && (std::isdigit(std::cin.peek()))) || (std::isdigit(first)))
    {
      std::string str;
      readNumber(str += first);
      Element element = {Token::Number, str};
      words_.push_back(element);
    }
    else if (std::isalpha(first))
    {
      std::string str;
      readWord(str += first);
      Element element = {Token::Word, str};
      words_.push_back(element);
    }
    else if (std::ispunct(first))
    {
      if ((first == '-') && (std::cin.peek() == '-'))
      {
        std::string str;
        readDash(str += first);
        Element element = {Token::Dash, str};
        words_.push_back(element);
      }
      else
      {
        if (std::ispunct(std::cin.peek()))
        {
          throw std::invalid_argument("Incorrect Punctuation\n");
        }
        std::string str;
        str += first;
        Element element = {Token::Punct, str};
        words_.push_back(element);
      }
    }
  }
}

void task::print()
{
  if (words_.empty())
  {
    return;
  }
  checkWords();
  std::vector<std::string> lines;
  std::string line;
  size_t i = 0;
  size_t countLines = 0;
  while(i < words_.size())
  {
    if (line.empty())
    {
      if ((words_.at(i).token == Token::Punct) || (words_.at(i).token == Token::Dash))
      {
        if ((words_.at(i).token == Token::Punct) && (lines.at(countLines - 1).size() < width_))
        {
          lines.at(countLines - 1) += words_.at(i).element;
          i++;
          continue;
        }
        line += words_.at(i - 1).element;
        (words_.at(i).token == Token::Dash) ? line += " " + words_.at(i).element : line += words_.at(i).element;
        auto pos = lines.at(countLines - 1).find_last_of(' ');
        lines.at(countLines - 1).erase(pos);
        i++;
        continue;
      }
      line += words_.at(i).element;
      i++;
      continue;
    }

    if (line.size() + words_.at(i).element.size() + 1 <= width_)
    {
      if (words_.at(i).token == Token::Punct)
      {
        line += words_.at(i).element;
        i++;
        continue;
      }
      line += " " + words_.at(i).element;
      i++;
      continue;
    }
    lines.push_back(line);
    countLines++;
    line.clear();
  }
  lines.push_back(line);

  std::for_each(lines.begin(), lines.end(), [](std::string str)
       {
         std::cout << str << "\n";
       });
}

void task::checkWords()
{
  if ((words_.at(0).token == Token::Punct) || (words_.at(0).token == Token::Dash))
  {
    throw std::invalid_argument("Incorrect Data, first element of punctuation\n");
  }

  for (size_t i = 0; i < words_.size() - 1; i++)
  {
    if ((words_.at(i).token == Token::Punct) && (words_.at(i + 1).token == Token::Punct))
    {
      throw std::invalid_argument("Two punct contact\n");
    }
  }
}

void task::readNumber(std::string &str)
{
  size_t countDot = 0;
  while(std::cin)
  {
    if ((std::cin.peek() == '.') || (std::isdigit(std::cin.peek())))
    {
      str += std::cin.get();
      if (str.back() == '.')
      {
        countDot++;
      }
    }
    else
    {
      break;
    }
  }

  if (str.size() > MaxWidthWord)
  {
    throw std::invalid_argument("Incorrect width of Number\n");
  }

  if (countDot > 1)
  {
    throw std::invalid_argument("Too many dots in Number\n");
  }
}

void task::readWord(std::string &str)
{
  while(std::cin)
  {
    if ((std::isalpha(std::cin.peek())) || (std::cin.peek() == '-'))
    {
      str += std::cin.get();
      if (str.back() == '-')
      {
        if (std::cin.peek() == '-')
        {
          throw std::invalid_argument("Too much dash\n");
        }
      }
    }
    else
    {
      break;
    }
  }

  if (str.size() > MaxWidthWord)
  {
    throw std::invalid_argument("Incorrect width of word\n");
  }
}

void task::readDash(std::string &str)
{
  size_t count = 1;
  while (std::cin)
  {
    if (std::cin.peek() == '-')
    {
      str += std::cin.get();
      count++;
    }
    else
    {
      break;
    }
  }

  if (count > 3)
  {
    throw std::invalid_argument("Too many dashes for a hyphen\n");
  }
}
