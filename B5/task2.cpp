#include <string>
#include <iostream>
#include "container.hpp"

void task2()
{
  if (!std::cin)
  {
    return;
  }
  geoShapes::Container container;
  std::string input;
  while (getline(std::cin, input))
  {
    geoShapes::clearSpace(input);
    if (input.empty())
    {
      continue;
    }

    int pos = input.find_first_of(" \t");
    std::size_t countPoints = std::stoi(input.substr(0, pos));
    input.erase(0, pos);
    geoShapes::clearSpace(input);

    if (countPoints <= 2)
    {
      throw std::ios_base::failure("Invalid shape");
    }

    std::vector<geoShapes::Point> points_;
    while (!input.empty())
    {
      auto posFirstBrake = input.find_first_of('(');
      auto posSemicolon = input.find_first_of(';');
      auto posSecondBrake = input.find_first_of(')');
      if (posFirstBrake > posSecondBrake)
      {
        throw std::ios_base::failure("Couldn't read");
      }
      int x = std::stoi(input.substr(posFirstBrake + 1, posSemicolon - 1));
      int y = std::stoi(input.substr(posSemicolon + 1, posSecondBrake - posSemicolon - 1));
      input.erase(0, posSecondBrake + 1);
      geoShapes::clearSpace(input);
      points_.push_back({x, y});
    }
    if (points_.size() != countPoints)
    {
      throw std::ios_base::failure("Invalid number of points");
    }
    container.add(points_);
  }

  container.printCountOfShape();
  container.deleteAllPentagon();
  container.printVertexPoint();
  container.changePlace();
  container.printShapes();
}
