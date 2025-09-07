// gbfs_solver.hpp
#ifndef GBFS_SOLVER_HPP
#define GBFS_SOLVER_HPP

#include <memory>
#include "heuristic_base.hpp"
#include "solver_base.hpp"
#include "puzzle_state.hpp"

class GBFSSolver : public SolverBase {
private:
    std::unique_ptr<HeuristicBase> heuristic;
public:
    explicit GBFSSolver(std::unique_ptr<HeuristicBase> h) : heuristic(std::move(h)) {};
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif