#include "circle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

bazoune::Circle::Circle(const point_t& pos, double radius) :
  centre_(pos),
  radius_(radius)
{
  if (radius_ < 0.0) //if radius is equal to 0, it is technically a degenerate circle.
  {
    throw std::invalid_argument("Radius must be a non-negative number");
  }
}

bazoune::Circle::Circle(double x, double y, double radius) :
  Circle({x, y}, radius)
{ }

double bazoune::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

bazoune::rectangle_t bazoune::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, centre_};
}

bazoune::point_t bazoune::Circle::getPos() const
{
  return centre_;
}

void bazoune::Circle::showParameters() const
{
  std::cout << "\nThe radius of the circle is " << radius_ << "\n";
}

void bazoune::Circle::move(const point_t& centre)
{
  centre_ = centre;
}

void bazoune::Circle::move(double deltaX, double deltaY)
{
  centre_.x += deltaX;
  centre_.y += deltaY;
}

void bazoune::Circle::scale(double scaleFactor)
{
  if (scaleFactor < 0.0)
  {
    throw std::invalid_argument("Circle scale factor must be a non-negative number");
  }

  radius_ *= scaleFactor;
}

void bazoune::Circle::rotate(double)
{
  //circle is not affected by rotation.
}
