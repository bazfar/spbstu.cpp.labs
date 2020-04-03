#ifndef PARTITION_HPP
#define PARTITION_HPP

#include "composite-shape.hpp"
#include "matrix.hpp"

using shape_ptr = std::shared_ptr<bazoune::Shape>;
using shape_array = std::unique_ptr<shape_ptr[]>;

namespace bazoune
{
  Matrix part(const shape_array& arr, size_t size);
  Matrix part(const CompositeShape& composite);
}

#endif
