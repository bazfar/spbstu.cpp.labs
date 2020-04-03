#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace bazoune
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };

  bool intersect(const rectangle_t& lhs, const rectangle_t& rhs);
}

#endif
