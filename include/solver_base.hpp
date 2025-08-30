#ifndef SOLVER_BASE_HPP
#define SOLVER_BASE_HPP

#include "puzzle_types.hpp"
#include "puzzle_state.hpp"
#include <vector>

class SolverBase {
public:
    virtual ~SolverBase() = default;
    virtual SearchResult solve(PuzzleState& initial_state) = 0;
};

#endif