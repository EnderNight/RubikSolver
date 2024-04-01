#pragma once

#include <istream>
#include <string>
#include <vector>

// Read a CSV stream
std::vector<std::vector<std::string>> read_csv(std::istream& str);
