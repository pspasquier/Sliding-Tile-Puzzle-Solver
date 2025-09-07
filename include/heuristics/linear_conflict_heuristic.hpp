// heuristics/linear_conflict_heuristic.hpp
#ifndef LINEAR_CONFLICT_HEURISTIC_HPP
#define LINEAR_CONFLICT_HEURISTIC_HPP

#include "heuristic_base.hpp"

class LinearConflictHeuristic : public HeuristicBase {
public:
    int evaluate(const PuzzleState& state) const override;
};

#endif