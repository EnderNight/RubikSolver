cmake_minimum_required(VERSION 3.10)

project(EnderSolver)

set(CMAKE_BUILD_TYPE Debug)

add_executable(solver src/main.cc src/cube.cc src/rotations.cc src/csv.cc
                      src/cube-solver.cc)
