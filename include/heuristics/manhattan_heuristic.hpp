// heuristics/manhattan_heuristic.hpp
#ifndef MANHATTAN_HEURISTIC_HPP
#define MANHATTAN_HEURISTIC_HPP

#include "heuristic_base.hpp"

class ManhattanHeuristic : public HeuristicBase {
public:
    int evaluate(const PuzzleState& state) const override;
};

#endif