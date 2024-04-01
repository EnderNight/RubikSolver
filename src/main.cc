#include "cube-solver.hh"
#include "cube.hh"
#include "rotations.hh"
#include <fstream>
#include <iostream>

void print_usage()
{
    std::cout
        << "Usage: solver [cube.esl] [cube_solved.esl] [rotations.csv]"
        << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        print_usage();
        return 0;
    }

    std::ifstream cube_file(argv[1]);
    std::ifstream solved_cube_file(argv[2]);
    std::ifstream rotations_file(argv[3]);

    if (!cube_file.is_open() || !solved_cube_file.is_open() ||
        !rotations_file.is_open())
    {
        std::cerr << "Could not open file" << std::endl;
        return 1;
    }

    Cube cube(cube_file);
    Cube solved_cube(solved_cube_file);
    Rotations rotations(rotations_file);
    CubeSolver solver(cube, solved_cube, rotations);

    cube = cube.rotate(rotations.rotations_get().find("R")->second);
    cube = cube.rotate(rotations.rotations_get().find("U")->second);
    cube = cube.rotate(rotations.rotations_get().find("R'")->second);

    std::cout << "Cube: " << std::endl;
    cube.print_cube();

    std::cout << std::endl;

    CubeSolver::solve_type movements = solver.solve();

    for (const auto& move : movements)
    {
        std::cout << move << " ";
    }

    std::cout << std::endl;

    return 0;
}
