#include "gtest/gtest.h"
#include "puzzle_state.hpp"
#include "bfs_solver.hpp"

TEST(BFSSolverTest, PuzzleTest1) {
    std::vector<int> tiles = {0, 6, 1, 7, 4, 2, 3, 8, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    BFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 5209);
    EXPECT_EQ(result.solution_length, 16);
    EXPECT_EQ(result.heuristic_mean, 0.0);
    EXPECT_EQ(result.initial_heuristic, 0);
}

TEST(BFSSolverTest, PuzzleTest2) {
    std::vector<int> tiles = {5, 0, 2, 6, 4, 8, 1, 7, 3};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    BFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 42704);
    EXPECT_EQ(result.solution_length, 21);
    EXPECT_EQ(result.heuristic_mean, 0.0);
    EXPECT_EQ(result.initial_heuristic, 0);
}

TEST(BFSSolverTest, PuzzleTest3) {
    std::vector<int> tiles = {2, 4, 7, 0, 3, 6, 8, 1, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    BFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 86288);
    EXPECT_EQ(result.solution_length, 23);
    EXPECT_EQ(result.heuristic_mean, 0.0);
    EXPECT_EQ(result.initial_heuristic, 0);
}
