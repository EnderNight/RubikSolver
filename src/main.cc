#include "cube.hh"
#include <fstream>
#include <iostream>

void print_usage()
{
    std::cout << "Usage: solver [cube.esl] [rotations.csv]" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        print_usage();
        return 0;
    }

    std::ifstream cube_file(argv[1]);
    std::ifstream rotations_file(argv[2]);

    if (!cube_file.is_open())
    {
        std::cerr << "Could not open cube file '" << argv[1] << "'"
                  << std::endl;
        return 1;
    }

    if (!rotations_file.is_open())
    {
        std::cerr << "Could not open rotations file '" << argv[1] << "'"
                  << std::endl;
        return 1;
    }

    Cube cube(cube_file, rotations_file);

    std::cout << "Cube: " << std::endl;
    cube.print_cube();

    std::cout << std::endl;
    cube.rotate("S'");
    cube.print_cube();

    return 0;
}
