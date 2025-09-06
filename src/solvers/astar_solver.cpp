// astar_solver.cpp
#include <iostream>
#include <chrono>
#include <queue>
#include <unordered_set>
#include <vector>
#include "astar_solver.hpp"

struct astar_priority {
    bool operator()(const PuzzleState& lhs, const PuzzleState& rhs) const {
        if (lhs.f != rhs.f) return lhs.f > rhs.f;
        if (lhs.h != rhs.h) return lhs.h > rhs.h;
        return lhs.order < rhs.order;
    }
};

SearchResult AStarSolver::solve(PuzzleState& initial_state) {
    using clock = std::chrono::high_resolution_clock;
    const auto start_time = clock::now();
    
    initial_state.h = heuristic->evaluate(initial_state);
    initial_state.f = initial_state.h + initial_state.g;
    
    int expanded_nodes = 0;
    int dummy_id = 1;
    int heuristic_sum = initial_state.h;

    std::priority_queue<PuzzleState, std::vector<PuzzleState>, astar_priority> open;
    std::unordered_set<uint64_t> closed;

    open.push(initial_state);

    while (!open.empty()) {
        PuzzleState current_state = open.top();
        open.pop();
        uint64_t serialized = current_state.serialize();

        if (closed.find(serialized) == closed.end()) {
            if (current_state.is_goal()) {
                auto duration = clock::now() - start_time;
                double heuristic_mean = (double)heuristic_sum / dummy_id;

                return { expanded_nodes, current_state.g, duration, heuristic_mean, initial_state.h };
            }

            closed.insert(serialized);
            expanded_nodes++;

            for (auto& successor : current_state.generate_successors()) {
                successor.order = dummy_id;
                successor.h = heuristic->evaluate(successor);
                successor.f = successor.h + successor.g;
                dummy_id++;
                open.push(successor);
                heuristic_sum += successor.h;
            }
        }
    }

    auto duration = clock::now() - start_time;
    return { expanded_nodes, -1, duration, 0.0, initial_state.h };
}