#include "gtest/gtest.h"
#include "puzzle_state.hpp"
#include "astar_solver.hpp"
#include "manhattan_heuristic.hpp"

TEST(AStarSolverTest, PuzzleTest1) {
    std::vector<int> tiles = {0, 6, 1, 7, 4, 2, 3, 8, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    AStarSolver solver(std::make_unique<ManhattanHeuristic>());
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 91);
    EXPECT_EQ(result.solution_length, 16);
    EXPECT_NEAR(result.heuristic_mean, 6.72561, 1e-5);
    EXPECT_EQ(result.initial_heuristic, 10);
}

TEST(AStarSolverTest, PuzzleTest2) {
    std::vector<int> tiles = {5, 0, 2, 6, 4, 8, 1, 7, 3};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    AStarSolver solver(std::make_unique<ManhattanHeuristic>());
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 612);
    EXPECT_EQ(result.solution_length, 21);
    EXPECT_NEAR(result.heuristic_mean, 9.81136, 1e-5);
    EXPECT_EQ(result.initial_heuristic, 11);
}

TEST(AStarSolverTest, PuzzleTest3) {
    std::vector<int> tiles = {2, 4, 7, 0, 3, 6, 8, 1, 5};
    PuzzleState::board_size = static_cast<int>(3);
    PuzzleState initial(tiles);

    AStarSolver solver(std::make_unique<ManhattanHeuristic>());
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 511);
    EXPECT_EQ(result.solution_length, 23);
    EXPECT_NEAR(result.heuristic_mean, 9.97655, 1e-5);
    EXPECT_EQ(result.initial_heuristic, 15);
}
