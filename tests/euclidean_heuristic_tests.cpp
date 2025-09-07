#include "gtest/gtest.h"
#include "euclidean_heuristic.hpp"
#include "puzzle_state.hpp"

TEST(euclideanHeuristicTest, PuzzleZeroCost) {
    std::vector<int> tiles = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    EuclideanHeuristic euclidean;

    EXPECT_EQ(euclidean.evaluate(state), 0);
}

TEST(euclideanHeuristicTest, Puzzle0) {
    std::vector<int> tiles = { 0, 6, 1, 7, 4, 2, 3, 8, 5 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    EuclideanHeuristic euclidean;

    EXPECT_EQ(euclidean.evaluate(state), 8);
}

TEST(euclideanHeuristicTest, Puzzle1) {
    std::vector<int> tiles = { 5, 0, 2, 6, 4, 8, 1, 7, 3 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    EuclideanHeuristic euclidean;

    EXPECT_EQ(euclidean.evaluate(state), 8);
}

TEST(euclideanHeuristicTest, Puzzle2) {
    std::vector<int> tiles = { 2, 4, 7, 0, 3, 6, 8, 1, 5 };
    PuzzleState::board_size = 3;
    PuzzleState state(tiles);

    EuclideanHeuristic euclidean;

    EXPECT_EQ(euclidean.evaluate(state), 13);
}

// TEST(euclideanHeuristicTest, Puzzle3) {
//     std::vector<int> tiles = { 7, 11, 8, 3, 14, 0, 6, 15, 1, 4, 13, 9, 5, 12, 2, 10 };
//     PuzzleState::board_size = 4;
//     PuzzleState state(tiles);

//     EuclideanHeuristic euclidean;

//     EXPECT_EQ(euclidean.evaluate(state), );
// }

// TEST(euclideanHeuristicTest, Puzzle4) {
//     std::vector<int> tiles = { 12, 9, 0, 6, 8, 3, 5, 14, 2, 4, 11, 7, 10, 1, 15, 13 };
//     PuzzleState::board_size = 4;
//     PuzzleState state(tiles);

//     EuclideanHeuristic euclidean;

//     EXPECT_EQ(euclidean.evaluate(state), );
// }

// TEST(euclideanHeuristicTest, Puzzle5) {
//     std::vector<int> tiles = { 13, 0, 9, 12, 11, 6, 3, 5, 15, 8, 1, 10, 4, 14, 2, 7 };
//     PuzzleState::board_size = 4;
//     PuzzleState state(tiles);

//     EuclideanHeuristic euclidean;
//     EXPECT_EQ(euclidean.evaluate(state), );
// }
