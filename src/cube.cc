#include "cube.hh"

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

Cube::Cube(std::stringstream& cube_stream)
{
    std::string face;

    while (std::getline(cube_stream, face))
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

const Cube::cube_type& Cube::cube_get() const { return cube_; }

const Cube::colors_type& Cube::colors_get() const { return colors_; }

int Cube::edge_size_get() const { return edge_size_; }

int Cube::num_colors_get() const { return num_colors_; }

static std::map<char, int> get_counts(const Cube& cube)
{
    std::map<char, int> map;
    const Cube::cube_type& blocks = cube.cube_get();

    for (const auto& link : cube.colors_get())
    {
        map.insert(std::make_pair(
            link.first,
            std::count(blocks.begin(), blocks.end(), link.first)));
    }

    return map;
}

void Cube::print_counts() const
{
    std::map<char, int> counts = get_counts(*this);

    for (const auto& link : colors_)
    {
        std::cout << link.second << ": " << counts[link.first]
                  << std::endl;
    }
}

void Cube::print_cube() const
{
    std::cout << "Not implemented" << std::endl;
}
