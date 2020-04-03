#ifndef SORT_HPP
#define SORT_HPP

#include <functional>

#include "accesses.hpp"

enum class Direction
{
  ascending,
  descending
};

Direction getDirection(const char* direction);

template <template <class T> class Access, typename T>
void selectionSort(T& collection, Direction direction)
{
  using value_type = typename T::value_type;

  std::function<bool(value_type, value_type)> compare = (direction == Direction::ascending) 
      ? std::function<bool(value_type, value_type)>(std::less<value_type>())
      : std::function<bool(value_type, value_type)>(std::greater<value_type>());

  const auto begin = Access<T>::begin(collection);
  const auto end = Access<T>::end(collection);

  for (auto i = begin; i != end; ++i)
  {
    auto tmp = i;
    for (auto j = Access<T>::next(i); j != end; ++j)
    {
      if (compare(Access<T>::element(collection, j), Access<T>::element(collection, tmp)))
      {
        tmp = j;
      }
    }

    if (tmp != i)
    {
      std::swap(Access<T>::element(collection, tmp), Access<T>::element(collection, i));
    }
  }
}

#endif
