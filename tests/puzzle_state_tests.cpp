#include <gtest/gtest.h>
#include "puzzle_state.hpp"

TEST(PuzzleStateTest, GoalStateDetection) {
    std::vector<int> tiles = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState state(tiles);
    EXPECT_TRUE(state.is_goal());
}

TEST(PuzzleStateTest, GoalStateDetection2) {
    std::vector<int> tiles = {1, 0, 3, 4, 5, 6, 7, 8, 2};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState state(tiles);
    EXPECT_FALSE(state.is_goal());
}