#include "cube-solver.hh"

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "cube.hh"
#include "rotations.hh"

CubeSolver::CubeSolver(const Cube& cube_to_solve, const Cube& solved_cube,
                       const Rotations& rotations)
    : cur_cube_(cube_to_solve), solved_cube_(solved_cube),
      rotations_(rotations)
{
}

const Cube& CubeSolver::cur_cube_get() const { return cur_cube_; }

const Cube& CubeSolver::solved_cube_get() const { return solved_cube_; }

int CubeSolver::calc_heuristic(const Cube& cube)
{
    int res = 0;

    const Cube::cube_type& cur_cube = cube.cube_get();
    const Cube::cube_type& solved_cube = solved_cube_.cube_get();

    for (int i = 0; i < cur_cube.size(); i++)
    {
        res += cur_cube[i] != solved_cube[i];
    }

    return res;
}

CubeSolver::solve_type CubeSolver::solve()
{
    using heur_type = std::vector<std::tuple<std::string, int, Cube>>;

    solve_type res;
    Cube cur_cube = cur_cube_;

    while (calc_heuristic(cur_cube) != 0)
    {
        heur_type heuristics;

        for (const auto& rot : rotations_.rotations_get())
        {
            Cube tmp_cube = cur_cube.rotate(rot.second);

            heuristics.push_back(std::make_tuple(
                rot.first, calc_heuristic(tmp_cube), tmp_cube));
        }

        auto max_ele = std::min_element(
            heuristics.begin(), heuristics.end(),
            [](const auto& lhs, const auto& rhs)
            { return std::get<1>(lhs) < std::get<1>(rhs); });

        res.push_back(std::get<0>(*max_ele));
        cur_cube = std::get<Cube>(*max_ele);
    }

    return res;
}
