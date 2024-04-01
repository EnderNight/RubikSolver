#pragma once

#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

class Rotations
{
  public:
    // Types
    using rotations_type =
        std::unordered_map<std::string, std::vector<int>>;

    // Constructor
    Rotations(std::istream& str);

    // Accessors
    const rotations_type& rotations_get() const;

    // Pretty print the loaded rotations
    void print_rotations() const;

  private:
    // Map linking rotation names to actual rotations
    rotations_type rotations_;
};
