// linear_conflict_heuristic.cpp
#include <cmath>
#include "manhattan_heuristic.hpp"
#include "linear_conflict_heuristic.hpp"

/*
 * Counts inversions in arr (pairs i<j where arr[i] > arr[j]).
 * Each inversion = one linear conflict.
 *
 * This O(n^2) method is probably fine for sliding puzzles ≤ 6.
 * If used on much larger boards, consider switch to merge sort
 * for O(n log n) performance.
 */
int count_inversions(const std::vector<int>& arr) {
    int inv = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        for (int j = i + 1; j < (int)arr.size(); j++) {
            if (arr[i] > arr[j]) inv++;
        }
    }
    return inv;
}

int LinearConflictHeuristic::evaluate(const PuzzleState& state) const {
    ManhattanHeuristic manhattan_heuristic;
    int manhattan = manhattan_heuristic.evaluate(state);

    int size = PuzzleState::board_size;
    int linear_conflicts = 0;
    std::vector<int> goals;
    goals.reserve(size);

    // Linear conflicts in rows
    for (int row = 0; row < size; row++) {
        goals.clear();
        for (int i = 0; i < size; i++) {
            int tile = state.tiles[row * size + i];
            if (tile == 0) continue;
            int goal_row = tile / size;
            int goal_col = tile % size;
            if (goal_row == row)
                goals.push_back(goal_col);
        }
        linear_conflicts += count_inversions(goals);
    }

    // Linear conflicts in cols
    for (int col = 0; col < size; col++) {
        goals.clear();
        for (int i = 0; i < size; i++) {
            int tile = state.tiles[i * size + col];
            if (tile == 0) continue;
            int goal_row = tile / size;
            int goal_col = tile % size;
            if (goal_col == col)
                goals.push_back(goal_row);
        }
        linear_conflicts += count_inversions(goals);
    }

    return manhattan + 2 * linear_conflicts;
}