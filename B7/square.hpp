#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

class Square:public Shape
{
public:
  Square(int x, int y);

  void draw() const override;
};


#endif
