// heuristic_factory.hpp
#ifndef HEURISTIC_FACTORY_HPP
#define HEURISTIC_FACTORY_HPP

#include <memory>
#include "heuristic_base.hpp"
#include "puzzle_state.hpp"

class HeuristicFactory {
public:
    static std::unique_ptr<HeuristicBase> create(const std::string& heuristic);
};

#endif