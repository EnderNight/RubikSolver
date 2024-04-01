#include "csv.hh"

#include <sstream>
#include <string>
#include <vector>

std::vector<std::vector<std::string>> read_csv(std::istream& str)
{
    std::vector<std::vector<std::string>> res;
    std::string line;

    while (std::getline(str, line))
    {
        std::vector<std::string> result;
        std::stringstream line_str(line);
        std::string cell;

        while (std::getline(line_str, cell, ','))
        {
            result.push_back(cell);
        }

        if (!line_str && cell.empty())
        {
            result.push_back("");
        }

        res.push_back(result);
    }

    return res;
}
