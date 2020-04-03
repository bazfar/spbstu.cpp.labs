#include "shape.hpp"
#include "square.hpp"
#include "circle.hpp"
#include "triangle.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <memory>
#include <vector>

void show(std::vector<std::shared_ptr<Shape>> vec)
{
    std::for_each(vec.begin(), vec.end(), [](std::shared_ptr<Shape> firstShape) {firstShape->draw(); });
}

void backSpace(std::string& str)
{
    while ((!str.empty()) && ((str.back() == ' ') || str.back() == '\t'))
    {
        str.pop_back();
    }
}

void removeSpace(std::string& str)
{
    while ((!str.empty()) && ((str.at(0) == ' ') || str.at(0) == '\t'))
    {
        str.erase(0, 1);
    }
}

void task2()
{
  std::vector<std::shared_ptr<Shape>> vec;
  std::string line;
  while(getline(std::cin >> std::ws, line))
  {
    if (line.empty())
    {
      continue;
    }
    removeSpace(line);
    auto OpeningBracket = line.find_first_of('(');
    std::string typeShape = line.substr(0, OpeningBracket);
    backSpace(typeShape);
    line.erase(0, OpeningBracket);
    removeSpace(line);
    OpeningBracket = line.find_first_of('(');
    auto semicolon = line.find_first_of(';');
    auto closingBracket = line.find_first_of(')');

    if ((closingBracket == std::string::npos) || (OpeningBracket == std::string::npos) || (semicolon == std::string::npos))
    {
      throw std::invalid_argument("Invalid argument\n");
    }

    if (OpeningBracket > closingBracket)
    {
      throw std::invalid_argument("Invalid argument\n");
    }

    std::string str = line.substr(OpeningBracket, semicolon);

    int x = std::stoi(line.substr(OpeningBracket + 1, semicolon - 1));
    int y = std::stoi(line.substr(semicolon + 1, closingBracket - semicolon - 1));
    line.erase(0, closingBracket + 1);

    std::shared_ptr<Shape> ptr;
    if (typeShape == "CIRCLE")
    {
      ptr = std::make_shared<Circle>(x, y);
    }
    else if (typeShape == "TRIANGLE")
    {
      ptr = std::make_shared<Triangle>(x, y);
    }
    else if (typeShape == "SQUARE")
    {
      ptr = std::make_shared<Square>(x, y);
    }
    else
    {
      throw std::invalid_argument("Invalid Shape\n");
    }

    vec.push_back(ptr);
  }

  std::cout << "Original:\n";
  show(vec);
  std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Shape> firstShape, std::shared_ptr<Shape> secondShape)->bool
      {
        return firstShape->isMoreLeft(secondShape);
      });
  std::cout << "Left-Right:\n";
  show(vec);
  std::reverse(vec.begin(), vec.end());
  std::cout << "Right-Left:\n";
  show(vec);
  std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Shape> firstShape, std::shared_ptr<Shape> secondShape)->bool
      {
        return firstShape->isMoreUp(secondShape);
      });
  std::cout << "Top-Bottom:\n";
  show(vec);
  std::reverse(vec.begin(), vec.end());
  std::cout << "Bottom-Top:\n";
  show(vec);
}
