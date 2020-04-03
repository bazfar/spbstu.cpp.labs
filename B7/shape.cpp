#include "shape.hpp"

Shape::Shape(int x, int y):
 x_(x),
 y_(y)
{}


bool Shape::isMoreLeft(const std::shared_ptr<Shape> &sh) const
{
  return (x_ < sh->x_);
}

bool Shape::isMoreUp(const std::shared_ptr<Shape> &sh) const
{
  return (y_ > sh->y_);
}
