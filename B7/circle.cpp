#include <iostream>
#include "circle.hpp"

Circle::Circle(int x, int y):
  Shape(x, y)
{}

void Circle::draw() const
{
  std::cout << "CIRCLE (" << x_ << ";" << y_ << ")\n";
}
