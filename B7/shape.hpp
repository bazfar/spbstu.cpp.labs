#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>

class Shape
{
public:
  Shape(int x, int y);
  virtual ~Shape() = default;

  bool isMoreLeft(const std::shared_ptr<Shape> & sh) const;
  bool isMoreUp(const std::shared_ptr<Shape> & sha) const;
  virtual void draw() const = 0;

  int x_;
  int y_;
};

#endif
