#ifndef BOOKMARKMANAGER_HPP
#define BOOKMARKMANAGER_HPP

#include <map>
#include "phonebook.hpp"

class BookmarkManager
{
public:
  enum class movePosition
  {
    first,
    last
  };

  enum class insertPosition
  {
    before,
    after
  };

  BookmarkManager();

  void add(const PhoneBook::record_t& record);
  void store(const std::string& bookmark, const std::string& name);
  void insert(const std::string& bookmark, const PhoneBook::record_t& record, insertPosition position);
  void remove(const std::string& bookmark);
  void show(const std::string& bookmark);
  void move(std::string& bookmark, int number);
  void move(std::string& bookmark, movePosition position);


private:
  PhoneBook phoneBook_;
  std::map<std::string, PhoneBook::iterator> bookmarks_;
};

#endif // BOOKMARK_MANAGER
