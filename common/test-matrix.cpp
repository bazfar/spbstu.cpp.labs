#include <stdexcept>
#include <utility>

#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "partition.hpp"
#include "rectangle.hpp"

using shape_ptr = std::shared_ptr<bazoune::Shape>;

BOOST_AUTO_TEST_SUITE(matrixTestSuite)

BOOST_AUTO_TEST_CASE(copyAndMove)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(1, 2, 3);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);

  bazoune::Matrix testMatrix = bazoune::part(testComposite);

  BOOST_CHECK_NO_THROW(bazoune::Matrix testMatrix2(testMatrix));
  BOOST_CHECK_NO_THROW(bazoune::Matrix testMatrix2(std::move(testMatrix)));

  bazoune::Matrix testMatrix2 = bazoune::part(testComposite);
  bazoune::Matrix testMatrix3;

  BOOST_CHECK_NO_THROW(testMatrix3 = testMatrix2);
  BOOST_CHECK_NO_THROW(testMatrix3 = std::move(testMatrix2));

  bazoune::Matrix testMatrix4 = bazoune::part(testComposite);
  bazoune::Matrix testMatrix5;

  testMatrix5 = testMatrix4;
  BOOST_CHECK(testMatrix5 == testMatrix4);
  testMatrix5 = std::move(testMatrix4);
  //cannot compare testMatrix5 to testMatrix4 as we moved from the latter.
  BOOST_CHECK(testMatrix5 == testMatrix3);

  bazoune::Matrix testMatrix6(testMatrix3);
  BOOST_CHECK(testMatrix6 == testMatrix3);
  bazoune::Matrix testMatrix7(std::move(testMatrix3));
  //cannot compare testMatrix7 to testMatrix3 as we moved from the latter.
  BOOST_CHECK(testMatrix7 == testMatrix6);
}

BOOST_AUTO_TEST_CASE(exceptionThrow)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(-3, 2.5, 5);
  shape_ptr testRectangle = std::make_shared<bazoune::Rectangle>(2, -4.5, 2, 6);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);
  testComposite.add(testRectangle);

  bazoune::Matrix testMatrix = bazoune::part(testComposite);

  BOOST_CHECK_THROW(testMatrix[3], std::out_of_range);
  BOOST_CHECK_THROW(testMatrix[-1], std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
