#include "rectangle.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

const double FullCircle = 360.0;

bazoune::Rectangle::Rectangle(const point_t& pos, double width, double height) :
  centre_(pos),
  width_(width),
  height_(height),
  angle_(0.0)
{
  if ((width_ <= 0.0) || (height_ <= 0.0))
  {
    throw std::invalid_argument("Width and height must be positive numbers");
  }
}

bazoune::Rectangle::Rectangle(double x, double y, double width, double height) :
  Rectangle({x, y}, width, height)
{ }

double bazoune::Rectangle::getArea() const
{
  return width_ * height_;
}

bazoune::rectangle_t bazoune::Rectangle::getFrameRect() const
{
  const double sine = sin(angle_ * M_PI / 180);
  const double cosine = cos(angle_ * M_PI / 180);
  const double width = height_ * fabs(sine) + width_ * fabs(cosine);
  const double height = height_ * fabs(cosine) + width_ * fabs(sine);

  return {width, height, centre_};
}

bazoune::point_t bazoune::Rectangle::getPos() const
{
  return centre_;
}

void bazoune::Rectangle::showParameters() const
{
  std::cout << "\nThe size of the rectangle is " << width_ << "x" << height_ << "\n";
}

void bazoune::Rectangle::move(const point_t& centre)
{
  centre_ = centre;
}

void bazoune::Rectangle::move(double deltaX, double deltaY)
{
  centre_.x += deltaX;
  centre_.y += deltaY;
}

void bazoune::Rectangle::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Rectangle scale factor must be a positive number");
  }

  width_ *= scaleFactor;
  height_ *= scaleFactor;
}

void bazoune::Rectangle::rotate(double angle)
{
  angle_ += angle;
  //to prevent unnecessary conditions, fmod is used not only when angle_ >= 360.
  angle_ = (angle_ < 0.0) ? (FullCircle + fmod(angle_, FullCircle)) : fmod(angle_, FullCircle);
}
