#include <stdexcept>

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"

const double ErrorValue = 1e-10;

BOOST_AUTO_TEST_SUITE(circleTestSuite)

BOOST_AUTO_TEST_CASE(invariabilityAfterMoving)
{
  bazoune::Circle testCircle({4, 4}, 8.7);
  const bazoune::rectangle_t frameRectBefore = testCircle.getFrameRect();
  const double areaBefore = testCircle.getArea();

  testCircle.move({1.9, 1.9});
  BOOST_CHECK_CLOSE(frameRectBefore.width, testCircle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testCircle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ErrorValue);

  testCircle.move(5, -7);
  BOOST_CHECK_CLOSE(frameRectBefore.width, testCircle.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testCircle.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterScaling)
{
  bazoune::Circle testCircle({4, 4}, 3);
  double areaBefore = testCircle.getArea();

  double scaleFactor = 2.75;
  testCircle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testCircle.getArea(), scaleFactor * scaleFactor * areaBefore, ErrorValue);
  areaBefore = testCircle.getArea();

  scaleFactor = 0.75;
  testCircle.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testCircle.getArea(), scaleFactor * scaleFactor * areaBefore, ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterRotating)
{
  bazoune::Circle testCircle({4, 4}, 5);
  double areaBefore = testCircle.getArea();

  double angle = 37.8;
  testCircle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ErrorValue);
  areaBefore = testCircle.getArea();

  angle = -56.88;
  testCircle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ErrorValue);
  areaBefore = testCircle.getArea();

  angle = 384.2;
  testCircle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ErrorValue);
  areaBefore = testCircle.getArea();

  angle = -887.3;
  testCircle.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testCircle.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(exceptionThrow)
{
  BOOST_CHECK_THROW(bazoune::Circle({1, 2}, -3), std::invalid_argument);

  bazoune::Circle testCircle({1, 2}, 3);
  BOOST_CHECK_THROW(testCircle.scale(-2), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
