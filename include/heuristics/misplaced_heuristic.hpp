// heuristics/manhattan_heuristic.hpp
#ifndef MISPLACED_HEURISTIC_HPP
#define MISPLACED_HEURISTIC_HPP

#include "heuristic_base.hpp"

class MisplacedHeuristic : public HeuristicBase {
public:
    int evaluate(const PuzzleState& state) const override;
};

#endif