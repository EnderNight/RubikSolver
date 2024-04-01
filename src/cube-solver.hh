#pragma once

#include "cube.hh"
#include "rotations.hh"

#include <string>
#include <vector>

class CubeSolver
{
  public:
    using solve_type = std::vector<std::string>;

    // Constructor
    CubeSolver(const Cube& cube_to_solve, const Cube& solved_cube,
               const Rotations& rotations);

    // Accessors
    const Cube& cur_cube_get() const;
    const Cube& solved_cube_get() const;

    // Heuristic counting the number of
    // wrongly placed facets in \a cube
    int calc_heuristic(const Cube& cube);

    // Solve the cur_cube_
    solve_type solve();

  private:
    // The cube to solve
    const Cube& cur_cube_;

    // The goal cube
    const Cube& solved_cube_;

    // The possible rotations
    const Rotations& rotations_;
};
