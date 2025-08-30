// solver_factory.hpp
#ifndef SOLVER_FACTORY_HPP
#define SOLVER_FACTORY_HPP

#include <memory>
#include "solver_base.hpp"
#include "puzzle_state.hpp"

class SolverFactory {
public:
    static std::unique_ptr<SolverBase> create(const std::string& algorithm);
};

#endif