#include "gtest/gtest.h"
#include "misplaced_heuristic.hpp"
#include "puzzle_state.hpp"

TEST(MisplacedHeuristicTest, PuzzleZeroCost) {
    std::vector<int> tiles = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;

    EXPECT_EQ(misplaced.evaluate(state), 0);
}

TEST(MisplacedHeuristicTest, Puzzle0) {
    std::vector<int> tiles = { 0, 6, 1, 7, 4, 2, 3, 8, 5 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;

    EXPECT_EQ(misplaced.evaluate(state), 7);
}

TEST(MisplacedHeuristicTest, Puzzle1) {
    std::vector<int> tiles = { 5, 0, 2, 6, 4, 8, 1, 7, 3 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;

    EXPECT_EQ(misplaced.evaluate(state), 6);
}

TEST(MisplacedHeuristicTest, Puzzle2) {
    std::vector<int> tiles = { 2, 4, 7, 0, 3, 6, 8, 1, 5 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;

    EXPECT_EQ(misplaced.evaluate(state), 9);
}

TEST(MisplacedHeuristicTest, Puzzle3) {
    std::vector<int> tiles = { 7, 11, 8, 3, 14, 0, 6, 15, 1, 4, 13, 9, 5, 12, 2, 10 };
    PuzzleState::board_size = 4;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;

    EXPECT_EQ(misplaced.evaluate(state), 14);
}

TEST(MisplacedHeuristicTest, Puzzle4) {
    std::vector<int> tiles = { 12, 9, 0, 6, 8, 3, 5, 14, 2, 4, 11, 7, 10, 1, 15, 13 };
    PuzzleState::board_size = 4;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;

    EXPECT_EQ(misplaced.evaluate(state), 16);
}

TEST(MisplacedHeuristicTest, Puzzle5) {
    std::vector<int> tiles = { 13, 0, 9, 12, 11, 6, 3, 5, 15, 8, 1, 10, 4, 14, 2, 7 };
    PuzzleState::board_size = 4;
    PuzzleState state(tiles);

    MisplacedHeuristic misplaced;
    EXPECT_EQ(misplaced.evaluate(state), 16);
}
