#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public: 
  Rectangle(double setWidth, double setHeight, const point_t &setCenter);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(const double dx, const double dy) override;
  void print() const override;
private:
  double width_, height_;
  point_t center_;
};

#endif
