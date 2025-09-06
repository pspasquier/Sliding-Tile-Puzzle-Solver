// misplaced_tiles_heuristic.cpp
#include "misplaced_heuristic.hpp"

int MisplacedHeuristic::evaluate(const PuzzleState& state) const {
    int misplaced = 0;

    for (int i = 0; i < static_cast<int>(state.tiles.size()); i++)
        if (state.tiles[i] != i)
            misplaced++;

    return misplaced;
}