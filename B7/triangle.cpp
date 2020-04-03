#include "triangle.hpp"
#include <iostream>

Triangle::Triangle(int x, int y):
  Shape(x, y)
{}

void Triangle::draw() const
{
  std::cout << "TRIANGLE (" << x_ << ";" << y_ << ")\n";
}
