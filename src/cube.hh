#pragma once

#include "rotations.hh"
#include <istream>
#include <string>
#include <unordered_map>
#include <vector>

class Cube
{
  public:
    // Types
    using cube_type = std::vector<char>;
    using colors_type = std::unordered_map<char, std::string>;

    // Constructor
    Cube(std::istream& cube_str, std::istream& rotations_str);

    // Accessors
    const cube_type& cube_get() const;
    const Rotations& rotations_get() const;
    const colors_type& colors_get() const;
    int edge_size_get() const;
    int num_colors_get() const;

    // Get the number of blocks per colors
    std::unordered_map<char, int> get_counts() const;

    // Rotate the cube with the specified rotation
    // if the rotation is not found, do nothing
    void rotate(const std::string& rotation);

    // Display every color count
    void print_counts() const;
    // Pretty print the cube pattern
    void print_cube() const;

  private:
    // Create human readable representation of a face
    const std::string get_face_str(int pos) const;

  private:
    // Internal representation as an array of char
    // Each letter (W, Y, R, ...) represents colors
    // (White, Yellow, Red, ...) as in colors_
    cube_type cube_;

    // Possible rotations
    Rotations rotations_;

    // Number of blocks per edges
    // For now, only 3x3x3 cubes are supported
    int edge_size_ = 3;

    // Number of different colors
    // For now, only 3x3x3 cubes with 6 colors are supported
    int num_colors_ = 6;

    // Human readable representation of colors in cube_ vector
    colors_type colors_ = {
        {'W', "White"}, {'O', "Orange"}, {'Y', "Yellow"},
        {'R', "Red"},   {'G', "Green"},  {'B', "Blue"},
    };
};
