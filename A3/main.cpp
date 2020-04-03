#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

int main()
{
  bazoune::Rectangle rect1 {bazoune::point_t{1, 2.3}, 4.56, 7};
  bazoune::Rectangle rect2 {8, -9.1, 0.11, 12};
  bazoune::Circle circ1 {bazoune::point_t{13, -1.4}, 1.51};
  bazoune::Circle circ2 {6.17, 18, 1.9};

  bazoune::Shape* figures[] = {&rect1, &rect2, &circ1, &circ2};
  const int Size = sizeof(figures) / sizeof(bazoune::Shape);

  for (int i = 0; i < Size; i++)
  {
    std::cout << "\nArea of figure No. " << i << " is "
        << figures[i]->getArea() << "\n";
    std::cout << "Frame Rectangle position of figure No. " << i << " is ("
        << figures[i]->getFrameRect().pos.x << "; "
        << figures[i]->getFrameRect().pos.y << ")\n";
    std::cout << "Frame Rectangle size of figure No. " << i << " is "
        << figures[i]->getFrameRect().width << "x"
        << figures[i]->getFrameRect().height << "\n";
  }

  std::cout << "\nThe position of the first rectangle is ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")\n";
  std::cout << "\nMoving first rectangle to a point of (3; 4)";
  figures[0]->move({3, 4});
  std::cout << "\nNow the position of the first rectangle is ("
      << figures[0]->getPos().x << "; "
      << figures[0]->getPos().y << ")\n";

  std::cout << "\nThe position of the first circle is ("
      << figures[2]->getPos().x << "; "
      << figures[2]->getPos().y << ")\n";
  std::cout << "\nMoving first circle -8 along x and +5.67 along y";
  figures[2]->move(-8, 5.67);
  std::cout << "\nNow the position of the first circle is ("
      << figures[2]->getPos().x << "; "
      << figures[2]->getPos().y << ")\n";

  figures[0]->showParameters();
  std::cout << "Scaling first rectangle by a factor of 1.3";
  figures[0]->scale(1.3);
  figures[0]->showParameters();

  figures[2]->showParameters();
  std::cout << "Scaling first circle by a factor of 2.4";
  figures[2]->scale(2.4);
  figures[2]->showParameters();

  bazoune::CompositeShape::shape_ptr partOfComposite1 = std::make_shared<bazoune::Rectangle>(3, 11, 6, 6);
  bazoune::CompositeShape::shape_ptr partOfComposite2 = std::make_shared<bazoune::Rectangle>(11, 3, 6, 6);
  bazoune::CompositeShape::shape_ptr partOfComposite3 = std::make_shared<bazoune::Circle>(9, 13, 3);

  bazoune::CompositeShape composite;
  composite.add(partOfComposite1);
  composite.add(partOfComposite2);
  composite.add(partOfComposite3);

  std::cout << "\nArea of the composite shape is " << composite.getArea() << "\n";
  std::cout << "Frame Rectangle position of the composite shape is ("
      << composite.getFrameRect().pos.x << "; "
      << composite.getFrameRect().pos.y << ")\n";
  composite.showParameters();
  std::cout << "Scaling the composite shape by a factor of 0.5";
  composite.scale(0.5);
  composite.showParameters();

  std::cout << "\nThe position of the composite shape is ("
      << composite.getPos().x << "; "
      << composite.getPos().y << ")\n";
  std::cout << "\nMoving the composite shape to a point of (3; 4)";
  composite.move({3, 4});
  std::cout << "\nNow the position of the composite shape is ("
      << composite.getPos().x << "; "
      << composite.getPos().y << ")\n";
  std::cout << "\nMoving the composite shape -8 along x and +5.67 along y";
  composite.move(-8, 5.67);
  std::cout << "\nNow the position of the composite shape is ("
      << composite.getPos().x << "; "
      << composite.getPos().y << ")\n";

  std::cout << "\nDeleting a shape";
  composite.remove(2);
  composite.showParameters();

  return 0;
}
