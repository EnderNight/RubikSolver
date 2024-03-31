#include "cube.hh"

#include <iostream>
#include <sstream>
#include <string>

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

void Cube::print_counts() const
{
    std::cout << "Not implemented" << std::endl;
}

void Cube::print_cube() const
{
    std::cout << "Not implemented" << std::endl;
}
