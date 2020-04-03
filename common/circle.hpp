#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace bazoune
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t& pos, double radius);
    Circle(double x, double y, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getPos() const override;
    void showParameters() const override;
    void move(const point_t& centre) override;
    void move(double deltaX, double deltaY) override;
    void scale(double scaleFactor) override;
    void rotate(double) override;

  private:
    point_t centre_;
    double radius_;
  };
}

#endif
