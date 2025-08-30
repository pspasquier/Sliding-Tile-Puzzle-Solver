// gbfs_solver.hpp
#ifndef GBFS_SOLVER_HPP
#define GBFS_SOLVER_HPP

#include "solver_base.hpp"
#include "puzzle_state.hpp"

class GBFSSolver : public SolverBase {
public:
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif