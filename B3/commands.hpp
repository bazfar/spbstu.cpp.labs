#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include "bookmarkManager.hpp"

std::string getNumber(std::string& number);
std::string getName(std::string& name);
std::string getMarkName(std::string& markname);
void add(BookmarkManager& bookmanager, std::stringstream& in);
void store(BookmarkManager& bookmanager, std::stringstream& in);
void insert(BookmarkManager& bookmanager, std::stringstream& in);
void remove(BookmarkManager& bookmanager, std::stringstream& in);
void show(BookmarkManager& bookmanager, std::stringstream& in);
void move(BookmarkManager& bookmanager, std::stringstream& in);


#endif // !COMMANDS_HPP
