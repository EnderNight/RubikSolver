#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class Cube
{
  public:
    using cube_type = std::vector<char>;
    using colors_type = std::unordered_map<char, std::string>;

    Cube(std::stringstream& cube_stream);

    // Accessors
    const cube_type& cube_get() const;
    const colors_type& colors_get() const;
    int edge_size_get() const;
    int num_colors_get() const;

    // Display every color count
    void print_counts() const;
    // Pretty print the cube pattern
    void print_cube() const;

  private:
    // Internal representation as an array of char
    // Each letter (W, Y, R, ...) represents colors
    // (White, Yellow, Red, ...)
    cube_type cube_;

    // Number of block per edges
    // For now, only 3x3x3 cubes are supported
    int edge_size_ = 3;

    // Number of different colors
    // For now, only 3x3x3 cubes with 6 colors are supported
    int num_colors_ = 6;

    // Human representation of colors in cube_ vector
    colors_type colors_ = {
        {'W', "White"}, {'O', "Orange"}, {'Y', "Yellow"},
        {'R', "Red"},   {'G', "Green"},  {'B', "Blue"},
    };
};
