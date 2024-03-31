#include "cube.hh"
#include <fstream>
#include <iostream>
#include <sstream>

void print_usage()
{
    std::cout << "Usage: solver [cube.esl]" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        print_usage();
        return 0;
    }

    std::ifstream file(argv[1]);
    std::stringstream buffer;

    buffer << file.rdbuf();

    Cube cube(buffer);

    for (char c : cube.cube_get())
        std::cout << c << std::endl;

    return 0;
}
