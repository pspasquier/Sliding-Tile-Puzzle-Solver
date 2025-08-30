// bfs_solver.cpp
#include <chrono>
#include <queue>
#include <unordered_set>
#include "bfs_solver.hpp"

SearchResult BFSSolver::solve(PuzzleState& initial_state) {
    using clock = std::chrono::high_resolution_clock;
    const auto start_time = clock::now();

    if (initial_state.is_goal()) {
        auto duration = clock::now() - start_time;
        return { 0, 0, duration, 0.0, initial_state.h };
    }

    int expanded_nodes = 0;

    std::queue<PuzzleState> open;
    std::unordered_set<uint64_t> closed;

    open.push(initial_state);
    closed.insert(initial_state.serialize());

    while (!open.empty()) {
        PuzzleState current_state = open.front();
        open.pop();
        expanded_nodes++;

        for (const auto& successor : current_state.generate_successors()) {
            if (successor.is_goal()) {
                auto duration = clock::now() - start_time;
                return { expanded_nodes, successor.g, duration, 0.0, initial_state.h };
            }
            
            uint64_t serialized = successor.serialize();
            if (closed.find(serialized) == closed.end()) {
                closed.insert(serialized);
                open.push(successor);
            }
        }
    }

    auto duration = clock::now() - start_time;
    return { expanded_nodes, -1, duration, 0.0, initial_state.h };
}