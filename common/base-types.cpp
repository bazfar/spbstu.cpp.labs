#include "base-types.hpp"

bool bazoune::intersect(const rectangle_t& lhs, const rectangle_t& rhs)
{
  const point_t lhsTopLft = {lhs.pos.x - lhs.width / 2, lhs.pos.y + lhs.height / 2};
  const point_t lhsBtmRgt = {lhs.pos.x + lhs.width / 2, lhs.pos.y - lhs.height / 2};
  const point_t rhsTopLft = {rhs.pos.x - rhs.width / 2, rhs.pos.y + rhs.height / 2};
  const point_t rhsBtmRgt = {rhs.pos.x + rhs.width / 2, rhs.pos.y - rhs.height / 2};

  const bool topLftCondition = (lhsTopLft.x < rhsBtmRgt.x) && (rhsBtmRgt.y < lhsTopLft.y);
  const bool btmRgtCondition = (rhsTopLft.x < lhsBtmRgt.x) && (lhsBtmRgt.y < rhsTopLft.y);

  return topLftCondition && btmRgtCondition;
}
