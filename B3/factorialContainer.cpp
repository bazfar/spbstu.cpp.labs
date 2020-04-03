#include "factorialContainer.hpp"

const int MAX = 10;
const int MIN = 1;

FactorialIterator::FactorialIterator():
  value_(1),
  index_(1)
{
}

FactorialIterator::FactorialIterator(int index):
  value_(factorial(index)),
  index_(index)
{
  if (index > MAX + 1 || index < MIN)
  {
    throw std::out_of_range("Out of range");
  }
}

unsigned long long &FactorialIterator::operator *()
{
  return value_;
}

unsigned long long *FactorialIterator::operator ->()
{
  return &value_;
}

FactorialIterator &FactorialIterator::operator ++()
{
  if (index_ > MAX)
  {
    throw std::out_of_range("Out of range");
  }

  index_++;
  value_ *= index_;
  return *this;
}

FactorialIterator &FactorialIterator::operator --()
{
  if (index_ <= MIN)
  {
    throw std::out_of_range("Out of range");
  }
  value_ /= index_;
  index_--;
  return *this;
}

bool FactorialIterator::operator ==(FactorialIterator& iter) const
{
  return (value_ == iter.value_) && (index_ == iter.index_);
}

bool FactorialIterator::operator !=(FactorialIterator& iter) const
{
  return !(*this == iter);
}

unsigned long long FactorialIterator::factorial(int index)
{
  if (index <= MIN)
  {
    return 1;
  }
  return index * factorial(index - 1);
}

FactorialIterator FactorialContainer::begin()
{
  return FactorialIterator(MIN);
}

FactorialIterator FactorialContainer::end ()
{
  return FactorialIterator(MAX + 1);
}
