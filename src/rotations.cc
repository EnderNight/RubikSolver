#include "rotations.hh"

#include "csv.hh"

#include <iostream>
#include <istream>
#include <string>
#include <utility>
#include <vector>

Rotations::Rotations(std::istream& str)
{
    using csv_type = std::vector<std::vector<std::string>>;

    csv_type csv = read_csv(str);

    for (const auto& line : csv)
    {
        std::vector<int> rotation;

        for (int i = 1; i < line.size(); i++)
        {
            rotation.push_back(std::stoi(line[i]));
        }

        rotations_.insert(std::make_pair(line[0], rotation));
    }
}

const Rotations::rotations_type& Rotations::rotations_get() const
{
    return rotations_;
}

void Rotations::print_rotations() const
{
    for (const auto& rot : rotations_)
    {
        std::cout << rot.first << ": ";

        for (auto& move : rot.second)
        {
            std::cout << move << " ";
        }

        std::cout << std::endl;
    }
}
