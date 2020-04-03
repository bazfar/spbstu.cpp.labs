#ifndef FACTORIALCONTAINER_HPP
#define FACTORIALCONTAINER_HPP
#include <iterator>

class FactorialIterator : public std::iterator<std::bidirectional_iterator_tag, unsigned long long>
{
public:
  FactorialIterator();
  FactorialIterator(int index);

  unsigned long long &operator *();
  unsigned long long *operator ->();

  FactorialIterator &operator ++();
  FactorialIterator &operator --();

  bool operator ==(FactorialIterator& iter) const;
  bool operator !=(FactorialIterator& iter) const;

private:
  unsigned long long value_;
  int index_;

  unsigned long long factorial(int index);
};



class FactorialContainer
{
public:
  FactorialIterator begin();
  FactorialIterator end();
};

#endif // !FACTORIALCONTAINER_HPP
