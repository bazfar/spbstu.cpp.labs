#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <memory>

#include "shape.hpp"

namespace bazoune
{
  class CompositeShape : public Shape
  {
  public:
    using shape_ptr = std::shared_ptr<Shape>;
    using shape_array = std::unique_ptr<shape_ptr[]>;

    CompositeShape();
    CompositeShape(const CompositeShape& source);
    CompositeShape(CompositeShape&& source);
    ~CompositeShape() = default;

    CompositeShape& operator =(const CompositeShape& rhs);
    CompositeShape& operator =(CompositeShape&& rhs);

    shape_ptr operator [](size_t rhs) const;
    bool operator ==(const CompositeShape& rhs) const;
    bool operator !=(const CompositeShape& rhs) const;

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    point_t getPos() const override;
    void showParameters() const override;
    void move(const point_t& centre) override;
    void move(double deltaX, double deltaY) override;
    void scale(double scaleFactor) override;
    void rotate(double angle) override;

    void add(shape_ptr shape);
    void remove(size_t index);
    size_t size() const;
    shape_array list() const;

  private:
    size_t count_;
    double angle_;
    shape_array arrayOfShapes_;
  };
}

#endif
