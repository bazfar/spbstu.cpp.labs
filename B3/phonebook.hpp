#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <list>

class PhoneBook
{
public:
  struct record_t
  {
    std::string name;
    std::string number;
  };

  using container = std::list<record_t>;
  using iterator = container::iterator;

  void showCurrentRecord(const iterator iterator);
  void pushback(const record_t& value);

  iterator goNext(iterator iter);
  iterator goPrev(iterator iter);
  iterator insert(iterator iter, const record_t& record);
  iterator replace(iterator iter, const record_t& record);
  iterator move(iterator iter, const int qty);
  iterator remove(iterator iter);

  iterator begin();
  iterator end();

  bool empty();
private:
  container book_;
};

#endif // !PHONEBOOK_HPP
