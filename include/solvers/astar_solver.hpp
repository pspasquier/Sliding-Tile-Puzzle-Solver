// astar_solver.hpp
#ifndef ASTAR_SOLVER_HPP
#define ASTAR_SOLVER_HPP

#include <memory>
#include "heuristic_base.hpp"
#include "solver_base.hpp"
#include "puzzle_state.hpp"

class AStarSolver : public SolverBase {
private:
    std::unique_ptr<HeuristicBase> heuristic;
public:
    explicit AStarSolver(std::unique_ptr<HeuristicBase> h) : heuristic(std::move(h)) {};
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif