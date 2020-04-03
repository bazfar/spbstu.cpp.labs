#ifndef ACCESSES_HPP
#define ACCESSES_HPP

#include <iterator>

template <typename T>
struct BrAccess
{
  typedef size_t index;

  static index begin(const T&) 
  {
    return 0;
  }

  static index end(const T& collection) 
  {
    return collection.size();
  }

  static typename T::reference element(T& collection, index i)
  {
    return collection[i];
  }

  static index next(index i) 
  {
    return i + 1;
  }
};

template <typename T>
struct AtAccess
{
  typedef size_t index;

  static index begin(const T&) 
  {
    return 0;
  }

  static index end(const T& collection) 
  {
    return collection.size();
  }

  static typename T::reference element(T& collection, index i)
  {
    return collection.at(i);
  }

  static index next(index i) 
  {
    return i + 1;
  }
};

template <typename T>
struct ItAccess
{
  typedef typename T::iterator index;

  static index begin(T& collection)
  {
    return collection.begin();
  }

  static index end(T& collection)
  {
    return collection.end();
  }

  static typename T::reference element(T&, index& iterator)
  {
    return *iterator;
  }

  static index next(index& iterator) 
  {
    return std::next(iterator);
  }
};

#endif
