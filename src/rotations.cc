#include "rotations.hh"
#include <fstream>
#include <stdexcept>
#include <string>

Rotations::Rotations(const std::string& filename)
{

    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Could not open rotations file");
}

const Rotations::rotations_type& Rotations::rotations_get() const
{
    return rotations_;
}
