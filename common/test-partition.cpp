#include <boost/test/auto_unit_test.hpp>

#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "partition.hpp"
#include "rectangle.hpp"

using shape_ptr = std::shared_ptr<bazoune::Shape>;

BOOST_AUTO_TEST_SUITE(partitionTestSuite)

BOOST_AUTO_TEST_CASE(correctPartition)
{
  shape_ptr testCircle = std::make_shared<bazoune::Circle>(-3, 2.5, 5);
  shape_ptr testRectangle1 = std::make_shared<bazoune::Rectangle>(2, -4.5, 2, 6);
  shape_ptr testRectangle2 = std::make_shared<bazoune::Rectangle>(0.5, -5.5, 11, 2);
  shape_ptr partOfComposite1 = std::make_shared<bazoune::Rectangle>(2.5, -3, 5, 1);
  shape_ptr partOfComposite2 = std::make_shared<bazoune::Rectangle>(-4, 0, 2, 17);
  bazoune::CompositeShape composite;
  composite.add(partOfComposite1);
  composite.add(partOfComposite2);
  shape_ptr testComposite = std::make_shared<bazoune::CompositeShape>(composite);

  bazoune::CompositeShape testComposite1;
  testComposite1.add(testCircle);
  testComposite1.add(testRectangle1);
  testComposite1.add(testRectangle2);
  testComposite1.add(testComposite);

  bazoune::Matrix testMatrix = bazoune::part(testComposite1);

  BOOST_CHECK_EQUAL(testMatrix.getRows(), 3);
  BOOST_CHECK_EQUAL(testMatrix.getColumns(), 2);

  BOOST_CHECK(testMatrix[0][0] == testCircle);
  BOOST_CHECK(testMatrix[0][1] == testRectangle2);
  BOOST_CHECK(testMatrix[1][0] == testRectangle1);
  BOOST_CHECK(testMatrix[2][0] == testComposite);
}

BOOST_AUTO_TEST_SUITE_END()
