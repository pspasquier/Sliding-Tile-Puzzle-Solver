// idastar_solver.hpp
#ifndef IDAStar_SOLVER_HPP
#define IDAStar_SOLVER_HPP

#include <memory>
#include <tuple>
#include "heuristic_base.hpp"
#include "solver_base.hpp"
#include "puzzle_state.hpp"

class IDAStarSolver : public SolverBase {
private:
    std::unique_ptr<HeuristicBase> heuristic;
public:
    explicit IDAStarSolver(std::unique_ptr<HeuristicBase> h) : heuristic(std::move(h)) {};
    std::tuple<int,int> recursive_search_ida(PuzzleState& current_state, int f_limit, int& expanded_nodes, int& dummy_id, int& heuristic_sum);
    SearchResult solve(PuzzleState& initial_state) override;
};

#endif