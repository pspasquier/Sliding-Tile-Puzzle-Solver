#ifndef HEURISTIC_BASE_HPP
#define HEURISTIC_BASE_HPP

#include "puzzle_state.hpp"

class HeuristicBase {
public:
    virtual ~HeuristicBase() = default;
    virtual int evaluate(const PuzzleState& state) const = 0;
};

#endif
