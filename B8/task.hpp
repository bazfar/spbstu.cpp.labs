#ifndef task_HPP
#define task_HPP

#include <string>
#include <vector>

enum Token
{
  Word,
  Punct,
  Dash,
  Number,
};

struct Element
{
  Token token;
  std::string element;
};

class task
{
public:
  task(size_t width = 40);
  void read();
  void print();

private:
  size_t width_;
  std::vector<Element> words_;

  void checkWords();
  void readNumber(std::string &str);
  void readWord(std::string &str);
  void readDash(std::string &str);
};


#endif
