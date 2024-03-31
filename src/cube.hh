#pragma once

#include <sstream>
#include <vector>

class Cube
{
  public:
    using cube_type = std::vector<char>;

    Cube(std::stringstream& cube_stream);

    // Accessors
    const cube_type& cube_get() const;

    // Display every color count
    void print_counts() const;
    // Pretty print the cube pattern
    void print_cube() const;

  private:
    // Internal representation as an array of char
    // Each letter (W, Y, R, ...) represents colors
    // (White, Yellow, Red, ...)
    std::vector<char> cube_;

    // Number of block per edges
    // For now, only 3x3x3 cubes are supported
    int edge_size_ = 3;
};
