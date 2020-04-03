#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace bazoune
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual point_t getPos() const = 0;
    virtual void showParameters() const = 0;
    virtual void move(const point_t& centre) = 0;
    virtual void move(double deltaX, double deltaY) = 0;
    virtual void scale(double scaleFactor) = 0;
    virtual void rotate(double angle) = 0;
  };
}

#endif
