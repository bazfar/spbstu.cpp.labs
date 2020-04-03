#include <iostream>
#include "functions.hpp"

const int MAX = 5;
const int MIN = -5;

std::vector<DataStruct> fillVector()
{
  std::vector<DataStruct> vector;
  std::string str;
  while (std::getline(std::cin, str))
  {
    if (str.empty())
    {
      throw std::invalid_argument("Incorrect input");
    }
    int keys[2];
    int separatorCounter = 0;
    for (int j = 0; j < 2; j++)
    {
      for (size_t i = 0; i < str.length(); i++)
      {
        if (str[i] == ',')
        {
          separatorCounter++;
          std::string subStr = str.substr(0, i);
          str.erase(0, i + 1);
          keys[j] = std::stoi(subStr);
          if (keys[j] > MAX || keys[j] < MIN)
          {
            throw std::invalid_argument("Incorrect input");
          }
          break;
        }
      }
    }
    if (separatorCounter != 2)
    {
      throw std::invalid_argument("Invalid input");
    }
    if (str.empty())
    {
      throw std::invalid_argument("Invalid input");
    }
    while (str[0] == ' ')
    {
      str.erase(0, 1);
    }
    vector.push_back({ keys[0], keys[1], str });
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input");
  }

  return vector;
}

bool compare(const DataStruct& data1, const DataStruct& data2)
{
  if  (data1.key1 < data2.key1)
  {
    return true;
  }
  else if (data1.key1 == data2.key1)
  {
    if (data1.key2 < data2.key2)
    {
      return true;
    }

    else if (data1.key2 == data2.key2)
    {
      if (data1.str.length() < data2.str.length())
      {
        return true;
      }
    }
  }
  return false;
}

void printVector(const std::vector<DataStruct>& vector)
{
  for (size_t i = 0; i < vector.size(); i++)
  {
    std::cout << vector[i].key1 << "," << vector[i].key2 << "," << vector[i].str << '\n';
  }
}
