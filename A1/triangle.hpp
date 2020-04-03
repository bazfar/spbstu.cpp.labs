#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &pt1, const point_t &pt2, const point_t &pt3);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &point) override;
  void move(double dx, double dy) override;
  void print() const override;
private:
  point_t pos_;
  point_t a_;
  point_t b_;
  point_t c_;
};
#endif
