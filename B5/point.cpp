#include "point.hpp"

void geoShapes::clearSpace(std::string &word_)
{
  while (!word_.empty() && ((word_.at(0) == ' ') || (word_.at(0) == '\t')))
  {
    word_.erase(0,1);
  }
}
