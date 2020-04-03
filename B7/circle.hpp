#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle:public Shape
{
public:
  Circle(int x, int y);

  void draw() const override;

};

#endif
