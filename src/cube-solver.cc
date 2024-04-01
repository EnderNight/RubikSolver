#include "cube-solver.hh"

#include "cube.hh"
#include "rotations.hh"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

CubeSolver::CubeSolver(Cube& cube_to_solve, Cube& solved_cube)
    : cur_cube_(cube_to_solve), solved_cube_(solved_cube)
{
}

const Cube& CubeSolver::cur_cube_get() const { return cur_cube_; }

const Cube& CubeSolver::solved_cube_get() const { return solved_cube_; }

int CubeSolver::calc_heuristic()
{
    int res = 0;

    const Cube::cube_type& cur_cube = cur_cube_.cube_get();
    const Cube::cube_type& solved_cube = solved_cube_.cube_get();

    for (int i = 0; i < cur_cube.size(); i++)
    {
        res += cur_cube[i] == solved_cube[i];
    }

    return res;
}

int CubeSolver::calc_heuristic(const Cube& cube)
{
    int res = 0;

    const Cube::cube_type& cur_cube = cur_cube_.cube_get();
    const Cube::cube_type& solved_cube = cube.cube_get();

    for (int i = 0; i < cur_cube.size(); i++)
    {
        res += cur_cube[i] == solved_cube[i];
    }

    return res;
}

CubeSolver::solve_type CubeSolver::solve()
{
    using heur_type = std::vector<std::pair<std::string, int>>;

    solve_type res;
    Rotations::rotations_type rotations =
        cur_cube_.rotations_get().rotations_get();

    std::cout << calc_heuristic() << std::endl;

    while (calc_heuristic() != 54)
    {
        heur_type heuristics;

        for (const auto& rot : rotations)
        {
            cur_cube_.rotate(rot.first);

            heuristics.push_back(
                std::make_pair(rot.first, calc_heuristic()));

            cur_cube_.restore_rotation();
        }

        const auto& best_rot =
            std::max_element(heuristics.begin(), heuristics.end(),
                             [](const auto& lhs, const auto& rhs)
                             { return lhs.second < rhs.second; });

        cur_cube_.rotate(best_rot->first);
        res.push_back(best_rot->first);
    }

    return res;
}
