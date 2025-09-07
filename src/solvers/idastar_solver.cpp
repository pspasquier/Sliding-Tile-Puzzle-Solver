// idastar_solver.cpp
#include <chrono>
#include <tuple>
#include <limits>
#include <algorithm>
#include "idastar_solver.hpp"

std::tuple<int, int> IDAStarSolver::recursive_search_ida(
    PuzzleState& current_state,
    int f_limit,
    int& expanded_nodes,
    int& dummy_id,
    int& heuristic_sum
) {
    heuristic_sum += current_state.h;
    dummy_id++;
    if (current_state.f > f_limit)
        return { current_state.f, -1 };
    if (current_state.is_goal())
        return { -1, current_state.g };
    
    expanded_nodes++;
    int next_limit = std::numeric_limits<int>::max();
    
    for (auto& successor : current_state.generate_successors()) {
        successor.h = heuristic->evaluate(successor);
        successor.f = successor.h + successor.g;

        const auto [rec_limit, solution] = recursive_search_ida(successor, f_limit, expanded_nodes, dummy_id, heuristic_sum);
        if (solution != -1)
            return { -1, solution };
        next_limit = std::min(next_limit, rec_limit);
    }

    return { next_limit, -1 };
}

SearchResult IDAStarSolver::solve(PuzzleState& initial_state) {
    using clock = std::chrono::high_resolution_clock;
    const auto start_time = clock::now();

    initial_state.h = heuristic->evaluate(initial_state);
    initial_state.f = initial_state.h + initial_state.g;
    
    int expanded_nodes = 0;
    int dummy_id = 1;
    int heuristic_sum = initial_state.h;
    int f_limit = initial_state.h;

    while (f_limit != std::numeric_limits<int>::max()) {
        const auto [next_limit, solution] = recursive_search_ida(initial_state, f_limit, expanded_nodes, dummy_id, heuristic_sum);
        f_limit = next_limit;
        if (solution != -1) {
            auto duration = clock::now() - start_time;
            double heuristic_mean = (double)heuristic_sum / dummy_id;
            return { expanded_nodes, solution, duration, heuristic_mean, initial_state.h };
        }
    }

    auto duration = clock::now() - start_time;
    return { expanded_nodes, -1, duration, 0.0, initial_state.h };
}