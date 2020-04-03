#include <algorithm>
#include <cmath>
#include <iostream>
#include "container.hpp"

geoShapes::Container::Container():
  countTriangle(0),
  countRectangle(0),
  countSquares(0),
  countVertices(0)
{ }

void geoShapes::Container::add(geoShapes::Container::shape_ &shape)
{
  vec.push_back(shape);
  countVertices += shape.size();
  switch (shape.size())
  {
    case 3:
    {
      countTriangle++;
    }
    break;
    case 4:
    {
      std::pair<bool, bool> type = typeQuadrangle(shape);
      if (type.first)
      {
        countRectangle++;
        if (type.second)
        {
          countSquares++;
        }
      }
    }
    break;
    default:
    break;
  }
}

void geoShapes::Container::deleteAllPentagon()
{
  size_t count = vec.size();
  vec.erase(std::remove_if(vec.begin(), vec.end(), deleterCondion), vec.end());
  if (vec.size() < count)
  {
    countVertices -= ((count - vec.size()) * 5);
  }
}

void geoShapes::Container::printCountOfShape()
{
  std::cout << "Vertices: " << countVertices << "\n";
  std::cout << "Triangles: " << countTriangle << "\n";
  std::cout << "Squares: " << countSquares << "\n";
  std::cout << "Rectangles: " << countRectangle << "\n";
}

void geoShapes::Container::printVertexPoint()
{
  std::cout << "Points: ";
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << "(" << vec.at(i).at(0).x << ";" << vec.at(i).at(0).y << ") ";
  }
}

void geoShapes::Container::printShapes()
{
  std::cout << "\nShapes:\n";
  for (size_t i = 0; i < vec.size(); i++)
  {
    std::cout << vec.at(i).size() << " ";
    for (size_t j = 0; j < vec.at(i).size(); j++)
    {
      std::cout << "(" << vec.at(i).at(j).x << ";" << vec.at(i).at(j).y << ") ";
    }
    std::cout << "\n";
  }
}

void geoShapes::Container::changePlace()
{
  std::sort(vec.begin(), vec.end(), changeCondion);
}

double geoShapes::Container::getDistance(geoShapes::Point point1, geoShapes::Point point2)
{
  double x = point2.x - point1.x;
  double y = point2.y - point1.y;
  return std::sqrt(x * x + y * y);
}

double geoShapes::Container::scalarProduct(geoShapes::Point point1, geoShapes::Point point2)
{
  return (point1.x * point2.x + point1.y * point2.y);
}

bool geoShapes::Container::deleterCondion(geoShapes::Container::shape_ &vector)
{
  if (vector.size() == 5)
  {
    return true;
  }
  return false;
}

bool geoShapes::Container::changeCondion(geoShapes::Container::shape_ &vector, geoShapes::Container::shape_ &vector1)
{
  if (vector.size() < vector1.size())
  {
    return true;
  }
  if ((vector.size() == 4) && (vector1.size() == 4))
  {
    std::pair<bool, bool> type1 = typeQuadrangle(vector);
    std::pair<bool, bool> type2 = typeQuadrangle(vector1);
    if ((!type2.second) && (type2.first))
    {
      return type1.first && type1.second;
    }
    if (!type2.first)
    {
      return type1.first;
    }
  }
  return false;
}

std::pair<bool, bool> geoShapes::Container::typeQuadrangle(geoShapes::Container::shape_ &shape)
{
  std::pair<bool, bool> type = {false, false};
  double sizeVec1 = getDistance(shape.at(0), shape.at(1));
  double sizeVec2 = getDistance(shape.at(0), shape.at(3));
  if ((sizeVec1 == 0) && (sizeVec2 == 0))
  {
    type = {true, true};
    return type;
  }
  if (sizeVec1 * sizeVec2 == 0)
  {
    type = {true, false};
    return type;
  }
  geoShapes::Point vec1 = {shape.at(1).x - shape.at(0).x, shape.at(1).y - shape.at(0).y};
  geoShapes::Point vec2 = {shape.at(3).x - shape.at(0).x, shape.at(3).y - shape.at(0).y};
  double product = std::abs(scalarProduct(vec1, vec2));
  double cos = (product / (sizeVec1 * sizeVec2));
  if (std::acos(cos) * 180 / M_PI == 90)
  {
    type.first = true;
  }
  if (!type.first)
  {
    return type;
  }
  double sizeVec3 = getDistance(shape.at(2), shape.at(3));
  double sizeVec4 = getDistance(shape.at(2), shape.at(1));
  if ((sizeVec1 == sizeVec2) && (sizeVec1 == sizeVec3) && (sizeVec1 == sizeVec4))
  {
    type.second = true;
  }
  return type;
}
