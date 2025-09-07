#include <chrono>
#include "idfs_solver.hpp"

#define MAX_DEPTH 255

int depth_limited_search(const PuzzleState& current_state, int depth_limit, int& expanded_nodes, int g_cost) {
    if (current_state.is_goal()) 
        return g_cost;
    if (depth_limit <= 0)
        return -1;

    expanded_nodes++;
    for (const auto& successor : current_state.generate_successors()) {
        int solution = depth_limited_search(successor, depth_limit - 1, expanded_nodes, g_cost + 1);
        if (solution != -1)
            return solution;
    }
    return -1;
}

SearchResult IDFSSolver::solve(PuzzleState& initial_state) {
    using clock = std::chrono::high_resolution_clock;
    const auto start_time = clock::now();

    int expanded_nodes = 0;
    int solution_length = -1;

    for (int depth_limit = 0; depth_limit <= MAX_DEPTH; ++depth_limit) {
        solution_length = depth_limited_search(initial_state, depth_limit, expanded_nodes, 0);
        if (solution_length != -1) {
            auto duration = clock::now() - start_time;
            return { expanded_nodes, solution_length, duration, 0.0, initial_state.h };
        }
    }

    auto duration = clock::now() - start_time;
    return { expanded_nodes, -1, duration, 0.0, initial_state.h };
}
