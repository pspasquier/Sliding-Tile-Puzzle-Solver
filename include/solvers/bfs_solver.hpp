// bfs_solver.hpp
#ifndef BFS_SOLVER_HPP
#define BFS_SOLVER_HPP

#include "solver_base.hpp"
#include "puzzle_state.hpp"

class BFSSolver : public SolverBase {
public:
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif