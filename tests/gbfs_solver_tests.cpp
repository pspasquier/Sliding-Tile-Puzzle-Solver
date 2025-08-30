#include "gtest/gtest.h"
#include "puzzle_state.hpp"
#include "gbfs_solver.hpp"

TEST(BFSSolverTest, GBFSSolverPuzzleTest1) {
    std::vector<int> tiles = {0, 6, 1, 7, 4, 2, 3, 8, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    GBFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 16);
    EXPECT_EQ(result.solution_length, 16);
    EXPECT_NEAR(result.heuristic_mean, 5.5, 1e-1);
    EXPECT_EQ(result.initial_heuristic, 10);
}

TEST(BFSSolverTest, GBFSSolverPuzzleTest2) {
    std::vector<int> tiles = {5, 0, 2, 6, 4, 8, 1, 7, 3};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    GBFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 96);
    EXPECT_EQ(result.solution_length, 27);
    EXPECT_NEAR(result.heuristic_mean, 8.05422, 1e-5);
    EXPECT_EQ(result.initial_heuristic, 11);
}

TEST(BFSSolverTest, GBFSSolverPuzzleTest3) {
    std::vector<int> tiles = {2, 4, 7, 0, 3, 6, 8, 1, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    GBFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 90);
    EXPECT_EQ(result.solution_length, 57);
    EXPECT_NEAR(result.heuristic_mean, 6.80982, 1e-5);
    EXPECT_EQ(result.initial_heuristic, 15);
}
