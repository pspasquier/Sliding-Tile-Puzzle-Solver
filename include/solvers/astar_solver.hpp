// astar_solver.hpp
#ifndef ASTAR_SOLVER_HPP
#define ASTAR_SOLVER_HPP

#include "solver_base.hpp"
#include "puzzle_state.hpp"

class AStarSolver : public SolverBase {
public:
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif