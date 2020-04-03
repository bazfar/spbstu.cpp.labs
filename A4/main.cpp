#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "matrix.hpp"
#include "partition.hpp"

void showDemonstration(const bazoune::Shape& shape)
{
  std::cout << "\nArea of the shape is "
      << shape.getArea() << "\n";
  std::cout << "Position of the shape is ("
      << shape.getPos().x << "; "
      << shape.getPos().y << ")\n";
  std::cout << "Frame Rectangle size of the shape is "
      << shape.getFrameRect().width << "x"
      << shape.getFrameRect().height << "\n";
}

int main()
{
  bazoune::Rectangle rect(9, 4, 1.5, 1.5);

  std::cout << "\n  <<  Rectangle:  >>";
  showDemonstration(rect);
  std::cout << "> Moving the rectangle to a point of (3; 11)";
  rect.move({3, 11});
  showDemonstration(rect);

  rect.showParameters();
  std::cout << "> Scaling the rectangle by a factor of 4";
  rect.scale(4);
  rect.showParameters();

  showDemonstration(rect);
  std::cout << "> Rotating the rectangle by 48 degrees";
  rect.rotate(48);
  showDemonstration(rect);

  bazoune::Circle circ(17, 7.33, 12);

  std::cout << "\n  <<  Circle:  >>";
  showDemonstration(circ);
  std::cout << "> Moving the circle -8 along x and +5.67 along y";
  circ.move(-8, 5.67);
  showDemonstration(circ);

  circ.showParameters();
  std::cout << "> Scaling the circle by a factor of 2.4";
  circ.scale(0.25);
  circ.showParameters();

  showDemonstration(circ);
  std::cout << "> Rotating the circle by 39 degrees";
  rect.rotate(39);
  showDemonstration(circ);

  bazoune::Rectangle rect2(11, 3, 6, 6);

  bazoune::CompositeShape::shape_ptr part1 = std::make_shared<bazoune::Rectangle>(rect);
  bazoune::CompositeShape::shape_ptr part2 = std::make_shared<bazoune::Rectangle>(rect2);
  bazoune::CompositeShape::shape_ptr part3 = std::make_shared<bazoune::Circle>(circ);

  bazoune::CompositeShape composite;
  composite.add(part1);
  composite.add(part2);
  composite.add(part3);

  std::cout << "\n  <<  Composite shape:  >>";
  showDemonstration(composite);
  composite.showParameters();
  std::cout << "> Scaling the composite shape by a factor of 0.5";
  composite.scale(0.5);
  composite.showParameters();
  std::cout << "> Rotating the composite shape by 30 degrees";
  composite.rotate(30);
  composite.showParameters();

  showDemonstration(composite);
  std::cout << "> Moving the composite shape to a point of (3; 4)";
  composite.move({3, 4});
  showDemonstration(composite);

  std::cout << "\n  <<  Matrix and layer-by-layer partition:  >>\n";
  bazoune::Matrix matrix = bazoune::part(composite);
  for (size_t i = 0; i < matrix.getRows(); i++)
  {
    for (size_t j = 0; j < matrix.getColumns(); j++)
    {
      if (matrix[i][j] != nullptr)
      {
        std::cout << "Layer no. " << i << ":\n" << "Figure no. " << j << ":\n";
        std::cout << "Position: (" << matrix[i][j]->getPos().x << "; "
            << matrix[i][j]->getPos().y << ")\n";
      }
    }
  }

  return 0;
}
