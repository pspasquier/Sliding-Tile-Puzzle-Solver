// euclidean_distance_heuristic.cpp
#include <cmath>
#include "euclidean_heuristic.hpp"

int EuclideanHeuristic::evaluate(const PuzzleState& state) const {
    double distance = 0.0;

    for (size_t i = 0; i < state.tiles.size(); i++) {
        int tile = state.tiles[i];
        if (tile == 0) continue;

        int target_row = (tile) / state.board_size;
        int target_col = (tile) % state.board_size;
        int curr_row = i / state.board_size;
        int curr_col = i % state.board_size;

        int dr = curr_row - target_row;
        int dc = curr_col - target_col;
        distance += std::sqrt(dr * dr + dc * dc);
    }

    return static_cast<int>(distance);
}