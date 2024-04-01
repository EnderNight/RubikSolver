#include "cube.hh"

#include <algorithm>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

Cube::Cube(std::istream& str)
{
    std::string face;

    while (std::getline(str, face))
    {
        std::stringstream face_stream(face);
        std::string line;

        while (face_stream >> line)
        {
            for (int i = 0; i < edge_size_; i++)
                cube_.push_back(line[i]);
        }
    }
}

Cube::Cube(const std::vector<char> cube) : cube_(cube) {}

const Cube::cube_type& Cube::cube_get() const { return cube_; }

const Cube::colors_type& Cube::colors_get() const { return colors_; }

int Cube::edge_size_get() const { return edge_size_; }

int Cube::num_colors_get() const { return num_colors_; }

std::unordered_map<char, int> Cube::get_counts() const
{
    std::unordered_map<char, int> map;

    for (const auto& link : colors_)
    {
        map.insert(std::make_pair(
            link.first,
            std::count(cube_.begin(), cube_.end(), link.first)));
    }

    return map;
}

const Cube Cube::rotate(const std::vector<int>& rotations)
{
    Cube::cube_type new_cube = cube_;

    for (int i = 0; i < rotations.size(); i++)
    {
        new_cube[i] = cube_[rotations[i]];
    }

    Cube res(new_cube);

    return res;
}

void Cube::print_counts() const
{
    std::unordered_map<char, int> counts = get_counts();

    for (const auto& link : colors_)
    {
        std::cout << link.second << ": " << counts[link.first]
                  << std::endl;
    }
}

const std::string Cube::get_face_str(int pos) const
{
    std::string res;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res += cube_[pos + i * edge_size_ + j];
        }

        if (i != 2)
            res += "|";
    }

    return res;
}

void Cube::print_cube() const
{
    int face_size = edge_size_ * edge_size_;
    std::vector<std::string> faces = {"Front", "Right", "Back",
                                      "Left",  "Up",    "Down"};

    for (int i = 0; i < faces.size(); i++)
    {
        std::cout << faces[i] << ": " << get_face_str(i * face_size)
                  << std::endl;
    }
}
