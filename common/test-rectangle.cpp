#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "rectangle.hpp"

const double ErrorValue = 1e-10;

BOOST_AUTO_TEST_SUITE(rectangleTestSuite)

BOOST_AUTO_TEST_CASE(invariabilityAfterMoving)
{
  bazoune::Rectangle testRectangle({6, 6}, 1.3, 2.4);
  const bazoune::rectangle_t frameRectBefore = testRectangle.getFrameRect();
  const double areaBefore = testRectangle.getArea();

  testRectangle.move({1.9, 1.9});
  BOOST_CHECK_CLOSE(frameRectBefore.width, testRectangle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testRectangle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ErrorValue);

  testRectangle.move(5, -7);
  BOOST_CHECK_CLOSE(frameRectBefore.width, testRectangle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testRectangle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterScaling)
{
  bazoune::Rectangle testRectangle({4, 4}, 3, 8);
  double areaBefore = testRectangle.getArea();

  double scaleFactor = 2.75;
  testRectangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), scaleFactor * scaleFactor * areaBefore, ErrorValue);
  areaBefore = testRectangle.getArea();

  scaleFactor = 0.75;
  testRectangle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testRectangle.getArea(), scaleFactor * scaleFactor * areaBefore, ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterRotating)
{
  bazoune::Rectangle testRectangle({4, 4}, 5, 8);
  double areaBefore = testRectangle.getArea();

  double angle = 97.2;
  testRectangle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ErrorValue);
  areaBefore = testRectangle.getArea();

  angle = -27.4;
  testRectangle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ErrorValue);
  areaBefore = testRectangle.getArea();

  angle = 1087.23;
  testRectangle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ErrorValue);
  areaBefore = testRectangle.getArea();

  angle = -597.2;
  testRectangle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testRectangle.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(exceptionThrow)
{
  BOOST_CHECK_THROW(bazoune::Rectangle({1, 2}, -3, 4), std::invalid_argument);
  BOOST_CHECK_THROW(bazoune::Rectangle({1, 2}, 3, -4), std::invalid_argument);

  bazoune::Rectangle testRectangle({1, 2}, 3, 4);
  BOOST_CHECK_THROW(testRectangle.scale(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
