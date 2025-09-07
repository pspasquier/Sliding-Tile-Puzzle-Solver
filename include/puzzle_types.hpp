#ifndef PUZZLE_TYPES_HPP
#define PUZZLE_TYPES_HPP

#include <chrono>
#include <vector>

struct SearchResult {
    int nodes_expanded;
    int solution_length;
    std::chrono::duration<double> execution_time;
    double heuristic_mean;
    int initial_heuristic;
};

#endif