#pragma once

#include "cube.hh"

#include <string>
#include <vector>

class CubeSolver
{
  public:
    using solve_type = std::vector<std::string>;

    // Constructor
    CubeSolver(Cube& cube_to_solve, Cube& solved_cube);

    // Accessors
    const Cube& cur_cube_get() const;
    const Cube& solved_cube_get() const;

    // Calculate gap compared to solved cube
    int calc_heuristic();
    // Calculate gap compared to \a cube
    int calc_heuristic(const Cube& cube);

    // Solve the cur_cube_
    solve_type solve();

  private:
    // The cube to solve
    Cube& cur_cube_;

    // The cube goal for cur_cube_
    Cube& solved_cube_;
};
