// solver_factory.hpp
#ifndef SOLVER_FACTORY_HPP
#define SOLVER_FACTORY_HPP

#include <memory>
#include <string>
#include "solver_base.hpp"
#include "puzzle_state.hpp"
#include "heuristic_base.hpp"

class SolverFactory {
public:
    static std::unique_ptr<SolverBase> create(const std::string& algorithm, std::unique_ptr<HeuristicBase> heuristic);
};

#endif
