#include "gtest/gtest.h"
#include "puzzle_state.hpp"
#include "idfs_solver.hpp"

TEST(IDFSSolverTest, PuzzleTest1) {
    std::vector<int> tiles = {0, 6, 1, 7, 4, 2, 3, 8, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    IDFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 20305);
    EXPECT_EQ(result.solution_length, 16);
    EXPECT_EQ(result.heuristic_mean, 0.0);
    EXPECT_EQ(result.initial_heuristic, 0);
}

TEST(IDFSSolverTest, PuzzleTest2) {
    std::vector<int> tiles = {5, 0, 2, 6, 4, 8, 1, 7, 3};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    IDFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 336804);
    EXPECT_EQ(result.solution_length, 21);
    EXPECT_EQ(result.heuristic_mean, 0.0);
    EXPECT_EQ(result.initial_heuristic, 0);
}

TEST(IDFSSolverTest, PuzzleTest3) {
    std::vector<int> tiles = {2, 4, 7, 0, 3, 6, 8, 1, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    IDFSSolver solver;
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 1183127);
    EXPECT_EQ(result.solution_length, 23);
    EXPECT_EQ(result.heuristic_mean, 0.0);
    EXPECT_EQ(result.initial_heuristic, 0);
}
