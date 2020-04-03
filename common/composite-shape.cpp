#include "composite-shape.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility>

const double FullCircle = 360.0;

bazoune::CompositeShape::CompositeShape() :
  count_(0),
  angle_(0.0)
{ }

bazoune::CompositeShape::CompositeShape(const CompositeShape& source) :
  count_(source.count_),
  angle_(source.angle_),
  arrayOfShapes_(std::make_unique<shape_ptr[]>(source.count_))
{
  for (size_t i = 0; i < count_; i++)
  {
    arrayOfShapes_[i] = source.arrayOfShapes_[i];
  }
}

bazoune::CompositeShape::CompositeShape(CompositeShape&& source) :
  count_(source.count_),
  angle_(source.angle_),
  arrayOfShapes_(std::move(source.arrayOfShapes_))
{ }

bazoune::CompositeShape& bazoune::CompositeShape::operator =(const CompositeShape& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    angle_ = rhs.angle_;
    shape_array tmpArray(std::make_unique<shape_ptr[]>(rhs.count_));
    for (size_t i = 0; i < count_; i++)
    {
      tmpArray[i] = rhs.arrayOfShapes_[i];
    }
    arrayOfShapes_.swap(tmpArray);
  }

  return *this;
}

bazoune::CompositeShape& bazoune::CompositeShape::operator =(CompositeShape&& rhs)
{
  if (this != &rhs)
  {
    count_ = rhs.count_;
    angle_ = rhs.angle_;
    arrayOfShapes_ = std::move(rhs.arrayOfShapes_);
  }

  return *this;
}

bazoune::CompositeShape::shape_ptr bazoune::CompositeShape::operator [](size_t rhs) const
{
  if (rhs >= count_)
  {
    throw std::out_of_range("Index is out of range");
  }

  return arrayOfShapes_[rhs];
}

bool bazoune::CompositeShape::operator ==(const CompositeShape& rhs) const
{
  if (count_ != rhs.count_)
  {
    return false;
  }

  for (size_t i = 0; i < count_; i++)
  {
    if (arrayOfShapes_[i] != rhs.arrayOfShapes_[i])
    {
      return false;
    }
  }

  return true;
}

bool bazoune::CompositeShape::operator !=(const CompositeShape& rhs) const
{
  return !(*this == rhs);
}

double bazoune::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (size_t i = 0; i < count_; i++)
  {
    totalArea += arrayOfShapes_[i]->getArea();
  }
  return totalArea;
}

bazoune::rectangle_t bazoune::CompositeShape::getFrameRect() const
{
  if (count_ == 0)
  {
    return {0, 0, {0, 0}};
  }

  rectangle_t tmpFrameRect = arrayOfShapes_[0]->getFrameRect();

  //leftX, rightX, bottomY are shortened for better code readability.
  double lftX = tmpFrameRect.pos.x - tmpFrameRect.width / 2;
  double rgtX = tmpFrameRect.pos.x + tmpFrameRect.width / 2;
  double btmY = tmpFrameRect.pos.y - tmpFrameRect.height / 2;
  double topY = tmpFrameRect.pos.y + tmpFrameRect.height / 2;

  for (size_t i = 1; i < count_; i++)
  {
    tmpFrameRect = arrayOfShapes_[i]->getFrameRect();

    double tmpValue = tmpFrameRect.pos.x - tmpFrameRect.width / 2;
    lftX = std::min(tmpValue, lftX);

    tmpValue = tmpFrameRect.pos.x + tmpFrameRect.width / 2;
    rgtX = std::max(tmpValue, rgtX);

    tmpValue = tmpFrameRect.pos.y - tmpFrameRect.height / 2;
    btmY = std::min(tmpValue, btmY);

    tmpValue = tmpFrameRect.pos.y + tmpFrameRect.height / 2;
    topY = std::max(tmpValue, topY);
  }

  return {rgtX - lftX, topY - btmY, {(lftX + rgtX) / 2, (btmY + topY) / 2}};
}

bazoune::point_t bazoune::CompositeShape::getPos() const
{
  return getFrameRect().pos;
}

void bazoune::CompositeShape::showParameters() const
{
  std::cout << "\nFrame Rectangle size of the composite shape is "
      << getFrameRect().width << "x" << getFrameRect().height << "\n";
  for (size_t i = 0; i < count_; i++)
  {
    std::cout << "The position of composite shape part No." << i << " is ("
        << arrayOfShapes_[i]->getFrameRect().pos.x << "; "
        << arrayOfShapes_[i]->getFrameRect().pos.y << ")\n";
  }
}

void bazoune::CompositeShape::move(const point_t& centre)
{
  const double deltaX = centre.x - getFrameRect().pos.x;
  const double deltaY = centre.y - getFrameRect().pos.y;
  move(deltaX, deltaY);
}

void bazoune::CompositeShape::move(double deltaX, double deltaY)
{
  for (size_t i = 0; i < count_; i++)
  {
    arrayOfShapes_[i]->move(deltaX, deltaY);
  }
}

void bazoune::CompositeShape::scale(double scaleFactor)
{
  if (scaleFactor <= 0.0)
  {
    throw std::invalid_argument("Composite shape scale factor must be a positive number");
  }

  const point_t centre = getFrameRect().pos;
  for (size_t i = 0; i < count_; i++)
  {
    const double deltaX = arrayOfShapes_[i]->getFrameRect().pos.x - centre.x;
    const double deltaY = arrayOfShapes_[i]->getFrameRect().pos.y - centre.y;
    arrayOfShapes_[i]->move({centre.x + deltaX * scaleFactor, centre.y + deltaY * scaleFactor});
    arrayOfShapes_[i]->scale(scaleFactor);
  }
}

void bazoune::CompositeShape::rotate(double angle)
{
  angle_ += angle;
  //to prevent unnecessary conditions, fmod is used not only when angle_ >= 360.
  angle_ = (angle_ < 0.0) ? (FullCircle + fmod(angle_, FullCircle)) : fmod(angle_, FullCircle);

  const point_t centre = getFrameRect().pos;
  const double sine = sin(angle * M_PI / 180);
  const double cosine = cos(angle * M_PI / 180);

  for (size_t i = 0; i < count_; i++)
  {
    const double oldX = arrayOfShapes_[i]->getFrameRect().pos.x - centre.x;
    const double oldY = arrayOfShapes_[i]->getFrameRect().pos.y - centre.y;

    const double newX = oldX * fabs(cosine) - oldY * fabs(sine);
    const double newY = oldX * fabs(sine) + oldY * fabs(cosine);

    arrayOfShapes_[i]->move({centre.x + newX, centre.y + newY});
    arrayOfShapes_[i]->rotate(angle);
  }
}

void bazoune::CompositeShape::add(shape_ptr shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Shape pointer must not be null");
  }

  shape_array tmpArray(std::make_unique<shape_ptr[]>(count_ + 1));
  for (size_t i = 0; i < count_; i++)
  {
    tmpArray[i] = arrayOfShapes_[i];
  }
  tmpArray[count_] = shape;
  count_++;
  arrayOfShapes_.swap(tmpArray);
}

void bazoune::CompositeShape::remove(size_t index)
{
  if (index >= count_)
  {
    throw std::out_of_range("Index is out of range");
  }

  for (size_t i = index; i < count_ - 1; i++)
  {
    arrayOfShapes_[i] = arrayOfShapes_[i + 1];
  }
  count_--;
}

size_t bazoune::CompositeShape::size() const
{
  return count_;
}

bazoune::CompositeShape::shape_array bazoune::CompositeShape::list() const
{
  shape_array tmpArray(std::make_unique<shape_ptr[]>(count_));
  for (size_t i = 0; i < count_; i++)
  {
    tmpArray[i] = arrayOfShapes_[i];
  }

  return tmpArray;
}
