#include "gtest/gtest.h"
#include "puzzle_state.hpp"
#include "astar_solver.hpp"
#include "manhattan_heuristic.hpp"

TEST(AStar15SolverTest, PuzzleTest1) {
    std::vector<int> tiles = {7, 11, 8, 3, 14, 0, 6, 15, 1, 4, 13, 9, 5, 12, 2, 10};
    PuzzleState::board_size = static_cast<int>(4);
    PuzzleState initial(tiles);

    AStarSolver solver(std::make_unique<ManhattanHeuristic>());
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 154092);
    EXPECT_EQ(result.solution_length, 46);
    EXPECT_NEAR(result.heuristic_mean, 22.9871, 1e-4);
    EXPECT_EQ(result.initial_heuristic, 36);
}

TEST(AStar15SolverTest, PuzzleTest2) {
    std::vector<int> tiles = {12, 9, 0, 6, 8, 3, 5, 14, 2, 4, 11, 7, 10, 1, 15, 13};
    PuzzleState::board_size = static_cast<int>(4);
    PuzzleState initial(tiles);

    AStarSolver solver(std::make_unique<ManhattanHeuristic>());
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 2731989);
    EXPECT_EQ(result.solution_length, 50);
    EXPECT_NEAR(result.heuristic_mean, 24.6075, 1e-4);
    EXPECT_EQ(result.initial_heuristic, 32);
}

TEST(AStar15SolverTest, PuzzleTest3) {
    std::vector<int> tiles = {13, 0, 9, 12, 11, 6, 3, 5, 15, 8, 1, 10, 4, 14, 2, 7};
    PuzzleState::board_size = static_cast<int>(4);
    PuzzleState initial(tiles);

    AStarSolver solver(std::make_unique<ManhattanHeuristic>());
    SearchResult result = solver.solve(initial);

    EXPECT_EQ(result.nodes_expanded, 744209);
    EXPECT_EQ(result.solution_length, 53);
    EXPECT_NEAR(result.heuristic_mean, 28.0517, 1e-4);
    EXPECT_EQ(result.initial_heuristic, 39);
}
