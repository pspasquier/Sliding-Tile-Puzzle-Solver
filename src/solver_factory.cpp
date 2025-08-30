// solver_factory.cpp
#include <string>
#include "solver_factory.hpp"
#include "solvers/bfs_solver.hpp"
#include "solvers/idfs_solver.hpp"
#include "solvers/gbfs_solver.hpp"
#include "solvers/astar_solver.hpp"
#include "solvers/idastar_solver.hpp"

std::unique_ptr<SolverBase> SolverFactory::create(const std::string& algorithm) {
    if (algorithm == "-bfs") return std::make_unique<BFSSolver>();
    if (algorithm == "-idfs") return std::make_unique<IDFSSolver>();
    if (algorithm == "-gbfs") return std::make_unique<GBFSSolver>();
    if (algorithm == "-astar") return std::make_unique<AStarSolver>();
    if (algorithm == "-idastar") return std::make_unique<IDAStarSolver>();
    return nullptr;
}