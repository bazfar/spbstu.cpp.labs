#include <stdexcept>
#include <utility>

#include <boost/test/auto_unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "rectangle.hpp"

using shape_ptr = std::shared_ptr<bazoune::Shape>;

const double ErrorValue = 1e-10;

BOOST_AUTO_TEST_SUITE(compositeTestSuite)

BOOST_AUTO_TEST_CASE(invariabilityAfterMoving)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(4, 4, 8.7);
  shape_ptr testRectangle = std::make_shared<bazoune::Rectangle>(5, 6, 7.8, 8.9);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);
  testComposite.add(testRectangle);
  const bazoune::rectangle_t frameRectBefore = testComposite.getFrameRect();
  const double areaBefore = testComposite.getArea();

  testComposite.move({1.9, 1.9});
  BOOST_CHECK_CLOSE(frameRectBefore.width, testComposite.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testComposite.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(areaBefore, testComposite.getArea(), ErrorValue);

  testComposite.move(5, -7);
  BOOST_CHECK_CLOSE(frameRectBefore.width, testComposite.getFrameRect().width, ErrorValue);
  BOOST_CHECK_CLOSE(frameRectBefore.height, testComposite.getFrameRect().height, ErrorValue);
  BOOST_CHECK_CLOSE(areaBefore, testComposite.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterScaling)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(4, 4, 3);
  shape_ptr testRectangle = std::make_shared<bazoune::Rectangle>(5, 6, 2.1, 1);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);
  testComposite.add(testRectangle);
  double areaBefore = testComposite.getArea();

  double scaleFactor = 2.75;
  testComposite.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testComposite.getArea(), scaleFactor * scaleFactor * areaBefore, ErrorValue);
  areaBefore = testComposite.getArea();

  scaleFactor = 0.75;
  testComposite.scale(scaleFactor);
  BOOST_CHECK_CLOSE(testComposite.getArea(), scaleFactor * scaleFactor * areaBefore, ErrorValue);
}

BOOST_AUTO_TEST_CASE(areaAfterRotating)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(4, 7, 1);
  shape_ptr testRectangle = std::make_shared<bazoune::Rectangle>(5, 6, 4.5, 1.25);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);
  testComposite.add(testRectangle);
  double areaBefore = testComposite.getArea();

  double angle = 48.2;
  testComposite.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testComposite.getArea(), ErrorValue);
  areaBefore = testComposite.getArea();

  angle = -30.88;
  testComposite.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testComposite.getArea(), ErrorValue);
  areaBefore = testComposite.getArea();

  angle = 765.2;
  testComposite.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testComposite.getArea(), ErrorValue);
  areaBefore = testComposite.getArea();

  angle = -987.3;
  testComposite.rotate(angle);
  BOOST_CHECK_CLOSE(areaBefore, testComposite.getArea(), ErrorValue);
}

BOOST_AUTO_TEST_CASE(copyAndMove)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(1, 2, 3);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);

  BOOST_CHECK_NO_THROW(bazoune::CompositeShape testComposite2(testComposite));
  BOOST_CHECK_NO_THROW(bazoune::CompositeShape testComposite2(std::move(testComposite)));

  bazoune::CompositeShape testComposite2;
  testComposite2.add(testCircle);

  bazoune::CompositeShape testComposite3;

  BOOST_CHECK_NO_THROW(testComposite3 = testComposite2);
  BOOST_CHECK_NO_THROW(testComposite3 = std::move(testComposite2));

  bazoune::CompositeShape testComposite4;
  testComposite4.add(testCircle);

  bazoune::CompositeShape testComposite5;

  testComposite5 = testComposite4;
  BOOST_CHECK(testComposite5 == testComposite4);
  testComposite5 = std::move(testComposite4);
  //cannot compare testComposite5 to testComposite4 as we moved from the latter.
  BOOST_CHECK(testComposite5 == testComposite3);

  bazoune::CompositeShape testComposite6(testComposite3);
  BOOST_CHECK(testComposite6 == testComposite3);
  bazoune::CompositeShape testComposite7(std::move(testComposite3));
  //cannot compare testComposite7 to testComposite3 as we moved from the latter.
  BOOST_CHECK(testComposite7 == testComposite6);
}

BOOST_AUTO_TEST_CASE(exceptionThrow)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(1, 2, 3);
  shape_ptr testRectangle = std::make_shared<bazoune::Rectangle>(4, 5, 6, 7);
  bazoune::CompositeShape testComposite;
  testComposite.add(testCircle);
  testComposite.add(testRectangle);
  BOOST_CHECK_THROW(testComposite.scale(-2), std::invalid_argument);

  BOOST_CHECK_THROW(testComposite.add(nullptr), std::invalid_argument);
  BOOST_CHECK_THROW(testComposite.remove(4), std::out_of_range);
  BOOST_CHECK_THROW(testComposite.remove(-2), std::out_of_range);

  BOOST_CHECK_THROW(testComposite[100], std::out_of_range);
  BOOST_CHECK_THROW(testComposite[-1], std::out_of_range);

  testComposite.remove(1);
  testComposite.remove(0);
  BOOST_CHECK_THROW(testComposite.remove(0), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END()
