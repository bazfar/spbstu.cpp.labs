#include "circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <cassert>

Circle::Circle(double r, const point_t &center) :
  r_(r),
  center_(center)
{
  assert((r > 0) && "invalid r"); 
}

double Circle::getArea() const
{
  return  r_ * r_ * M_PI;
}

rectangle_t Circle::getFrameRect() const
{
  return rectangle_t{ r_ * 2, r_ * 2, center_ };
}

 void Circle::print() const
{
  std::cout << "Circle :  " << std::endl;
  std::cout << '\n';
  std::cout << "center X = " << center_.x << std::endl; 
  std::cout << "center y = " << center_.y << std::endl;
  std::cout << "circle ray = " << r_ << std::endl;
}

void Circle::move(const point_t &point)
{
  center_ = point;
}

void Circle::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}
