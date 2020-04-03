#include <iostream>
#include "bookmarkManager.hpp"


BookmarkManager::BookmarkManager()
{
  bookmarks_["current"] = phoneBook_.begin();
}

void BookmarkManager::add(const PhoneBook::record_t& record)
{
  phoneBook_.pushback(record);
  if (std::next(phoneBook_.begin()) == phoneBook_.end())
  {
    bookmarks_["current"] = phoneBook_.begin();
  }
}

void BookmarkManager::store(const std::string& bookmark, const std::string& name)
{
  std::map<std::string, PhoneBook::iterator>::iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    bookmarks_.emplace(name, iter->second);
    return;
  }
  std::cout << "<INVALID BOOKMARK>" << '\n';
}

void BookmarkManager::insert(const std::string& bookmark, const PhoneBook::record_t& record, insertPosition position)
{
  std::map<std::string, PhoneBook::iterator>::iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    if (iter->second == phoneBook_.end())
    {
      add(record);
    }

    switch (position)
    {
      case insertPosition::before:
      {
        phoneBook_.insert(iter->second, record);
        break;
      }
      case insertPosition::after:
      {
        phoneBook_.insert(std::next(iter->second), record);
        break;
      }
    }
    return;
  }
  std::cout << "<INVALID BOOKMARK>" << '\n';
}


void BookmarkManager::remove(const std::string& bookmark)
{
  std::map<std::string, PhoneBook::iterator>::iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    auto deleteIter = iter->second;

    for (auto i = bookmarks_.begin(); i != bookmarks_.end(); i++)
    {
      if (i->second == deleteIter)
      {
        if (std::next(i->second) == phoneBook_.end())
        {
          i->second = phoneBook_.goPrev(deleteIter);
        }
        else
        {
          i->second = phoneBook_.goNext(deleteIter);
        }
      }
    }
    phoneBook_.remove(deleteIter);
    return;
  }
  std::cout << "<INVALID BOOKMARK>" << '\n';
}

void BookmarkManager::show(const std::string& bookmark)
{
  std::map<std::string, PhoneBook::iterator>::iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    if (phoneBook_.empty())
    {
      std::cout << "<EMPTY>" << '\n';
      return;
    }
    return phoneBook_.showCurrentRecord(iter->second);
  }
  std::cout << "<INVALID BOOKMARK>" << '\n';
}

void BookmarkManager::move(std::string& bookmark, int number)
{
  std::map<std::string, PhoneBook::iterator>::iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    iter->second = phoneBook_.move(iter->second, number);
    return;
  }
  std::cout << "<INVALID BOOKMARK>" << '\n';
}

void BookmarkManager::move(std::string& bookmark, movePosition position)
{
  std::map<std::string, PhoneBook::iterator>::iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    switch (position)
    {
      case movePosition::first:
      {
        iter->second = phoneBook_.begin();
        break;
      }
      case movePosition::last:
      {
        iter->second = phoneBook_.goPrev(phoneBook_.end());
        break;
      }
    }
    return;
  }
  std::cout << "<INVALID BOOKMARK>" << '\n';
}
