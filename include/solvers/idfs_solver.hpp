// idfs_solver.hpp
#ifndef IDFS_SOLVER_HPP
#define IDFS_SOLVER_HPP

#include "solver_base.hpp"
#include "puzzle_state.hpp"

class IDFSSolver : public SolverBase {
public:
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif