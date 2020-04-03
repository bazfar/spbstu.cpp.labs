#include <iostream>
#include "square.hpp"

Square::Square(int x, int y):
  Shape(x, y)
{}

void Square::draw() const
{
  std::cout << "SQUARE (" << x_ << ";" << y_ << ")\n";
}
