// idastar_solver.hpp
#ifndef IDAStar_SOLVER_HPP
#define IDAStar_SOLVER_HPP

#include "solver_base.hpp"
#include "puzzle_state.hpp"

class IDAStarSolver : public SolverBase {
public:
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif