// manhattan_heuristic.cpp
#include "manhattan_heuristic.hpp"

int ManhattanHeuristic::evaluate(const PuzzleState& state) const {
    int eval = 0;

    for (size_t i = 0; i < state.tiles.size(); ++i) {
        int tile = state.tiles[i];
        if (tile == 0) continue;

        int target_row = (tile) / state.board_size;
        int target_col = (tile) % state.board_size;
        int curr_row = i / state.board_size;
        int curr_col = i % state.board_size;
        eval += std::abs(curr_row - target_row) + std::abs(curr_col - target_col);
    }
    
    return eval;
}