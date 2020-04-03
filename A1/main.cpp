#include "circle.hpp"
#include "rectangle.hpp"
#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"
#include "base-types.hpp"

int main()
{
  const point_t myPoint = {0, 0};
  std::cout << "mypoint " << "( " << myPoint.x ;
  std::cout << "," << myPoint.y << ")" << std::endl;
  std::cout << '\n';
  
  Circle myCircle(3, myPoint);
  Shape *ptr_shape = &myCircle;
  ptr_shape->print();
  std::cout << "circle area " << myCircle.getArea() << std::endl;
  ptr_shape->move(1, 2);
  std::cout << '\n';
  std::cout << "move the circle with (1, 2)" << std::endl;
  std::cout << '\n';
  ptr_shape->print();
  std::cout << '\n';
  ptr_shape->move({1.3, 2.4});
  std::cout << '\n';
  std::cout << "move the circle with (1.3, 2.4)" << std::endl;
  std::cout << '\n';
  ptr_shape->print();
  std::cout << '\n';
  std::cout << "frame rect.width= " << myCircle.getFrameRect().width << std::endl;
  std::cout << "frame rect.height= " << myCircle.getFrameRect().height << std::endl;
  ptr_shape->move(myPoint);
  std::cout << '\n';

  Rectangle myRect(8, 4, {2, 2});
  ptr_shape = &myRect;
  ptr_shape->print();
  ptr_shape->move(3, 4);
  std::cout << '\n';
  std::cout << "move the rectangle with (3,4)" << std::endl;
  std::cout << '\n';
  ptr_shape->print();
  ptr_shape->move({3.2, 4.5});
  std::cout << '\n';
  std::cout << "move the rectangle with (3.2,4.5)"<< std::endl;
  std::cout << '\n';
  ptr_shape->print();
  std::cout << '\n';
  std::cout << "rectangle area = " << myRect.getArea() << std::endl;
  std::cout << '\n';

  Triangle myTri({0, 3}, {4, 0}, {0, 0});
  ptr_shape = &myTri;
  ptr_shape->print();
  std::cout << "Area is = " << ptr_shape->getArea() << '\n';
  std::cout << '\n';
  std::cout << "Shape move to {1, 5}\n";
  ptr_shape->move({1, 5});
  ptr_shape->print();
  std::cout << '\n';
  std::cout << "Shape move to {1.5, 5.1}\n";
  ptr_shape->move({1.5, 5.1});
  ptr_shape->print();
  std::cout << "frame rect.width= " << myTri.getFrameRect().width << std::endl;
  std::cout << "frame rect.height= " << myTri.getFrameRect().height << std::endl;
  std::cout << '\n';
  return 0;
}
