#include "cube.hh"
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

    Cube cube(argv[1]);

    cube.print_counts();
    cube.print_cube();

    return 0;
}
