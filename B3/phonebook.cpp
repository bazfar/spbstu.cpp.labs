#include <iostream>
#include "phonebook.hpp"

void PhoneBook::showCurrentRecord(const iterator iterator)
{
  std::cout << iterator->number << " " << iterator->name << '\n';
}

void PhoneBook::pushback(const record_t& value)
{
  book_.push_back(value);
}

PhoneBook::iterator PhoneBook::goNext(iterator iter)
{
  if (std::next(iter) == book_.end())
  {
    return iter;
  }
  return ++iter;
}

PhoneBook::iterator PhoneBook::goPrev(iterator iter)
{
  if (iter == book_.begin())
  {
    return iter;
  }
  return --iter;
}

PhoneBook::iterator PhoneBook::insert(iterator iter, const record_t& record)
{
  return book_.insert(iter, record);
}

PhoneBook::iterator PhoneBook::replace(iterator iter, const record_t& record)
{
  return book_.insert(book_.erase(iter), record);
}

PhoneBook::iterator PhoneBook::move(iterator iter, int steps)
{
  if (steps >= 0)
  {
    while (std::next(iter) != book_.end() && steps > 0)
    {
      iter = std::next(iter);
      steps--;
    }
  }
  else
  {
    while (iter != book_.begin() && steps < 0)
    {
      iter = std::prev(iter);
      steps++;
    }
  }
  return iter;
}

PhoneBook::iterator PhoneBook::remove(iterator iter)
{
  return book_.erase(iter);
}

PhoneBook::iterator PhoneBook::begin()
{
  return book_.begin();
}

PhoneBook::iterator PhoneBook::end()
{
  return book_.end();
}

bool PhoneBook::empty()
{
  return book_.empty();
}
