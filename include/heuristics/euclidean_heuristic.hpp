// heuristics/euclidean_heuristic.hpp
#ifndef EUCLIDEAN_HEURISTIC_HPP
#define EUCLIDEAN_HEURISTIC_HPP

#include "heuristic_base.hpp"

class EuclideanHeuristic : public HeuristicBase {
public:
    int evaluate(const PuzzleState& state) const override;
};

#endif