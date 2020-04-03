#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include "DataStruct.hpp"

std::vector<DataStruct> fillVector();
bool compare(const DataStruct& data1, const DataStruct& data2);
void printVector(const std::vector<DataStruct>& vector);

#endif // !FUNCTIONS_HPP
