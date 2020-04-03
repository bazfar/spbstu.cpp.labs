#include "partition.hpp"

bazoune::Matrix bazoune::part(const shape_array& arr, size_t size)
{
  Matrix matrix;

  for (size_t i = 0; i < size; i++)
  {
    size_t rightRow = 0;
    size_t rightColumn = 0;
    for (size_t j = 0; j < matrix.getRows(); j++)
    {
      for (size_t k = 0; k < matrix.getColumns(); k++)
      {
        if (matrix[j][k] == nullptr)
        {
          rightRow = j;
          rightColumn = k;
          break;
        }

        if (intersect(arr[i]->getFrameRect(), matrix[j][k]->getFrameRect()))
        {
          rightRow = j + 1;
          rightColumn = 0;
          break;
        }
        else
        {
          rightRow = j;
          rightColumn = k + 1;
        }
      }

      if (rightRow == j) //if the right row is found
      {
        break;
      }
    }

    matrix.add(arr[i], rightRow, rightColumn);
  }

  return matrix;
}

bazoune::Matrix bazoune::part(const CompositeShape& composite)
{
  return part(composite.list(), composite.size());
}
