#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "point.hpp"
#include <vector>

namespace geoShapes
{
  class Container
  {
  public:
    using shape_ = std::vector<geoShapes::Point>;

    Container();
    void add(shape_ &shape);
    void deleteAllPentagon();
    void printCountOfShape();
    void printVertexPoint();
    void printShapes();
    void changePlace();
    static double getDistance(geoShapes::Point point1, geoShapes::Point point2);
    static double scalarProduct(geoShapes::Point point1, geoShapes::Point point2);
    static bool deleterCondion(shape_ &vector);
    static bool changeCondion(shape_ &vector, shape_&vector1);
    static std::pair<bool, bool> typeQuadrangle(shape_ &shape);

  private:
    std::size_t countTriangle;
    std::size_t countRectangle;
    std::size_t countSquares;
    std::size_t countVertices;
    std::vector<shape_> vec;
  };
}

#endif
