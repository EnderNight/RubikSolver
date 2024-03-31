#pragma once

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
    // \a filename csv file name containing the rotation data
    Rotations(const std::string& filename);

    // Accessors
    const rotations_type& rotations_get() const;

  private:
    // Map linking rotation names to actual rotations
    rotations_type rotations_;
};
