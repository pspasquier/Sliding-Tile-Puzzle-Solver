// solver_factory.cpp
#include <string>
#include <memory>
#include "solver_factory.hpp"
#include "solvers/bfs_solver.hpp"
#include "solvers/idfs_solver.hpp"
#include "solvers/gbfs_solver.hpp"
#include "solvers/astar_solver.hpp"
#include "solvers/idastar_solver.hpp"
#include "heuristic_factory.hpp"

std::unique_ptr<SolverBase> SolverFactory::create(const std::string& algorithm, std::unique_ptr<HeuristicBase> heuristic) {
    if (algorithm == "-bfs") return std::make_unique<BFSSolver>();
    if (algorithm == "-idfs") return std::make_unique<IDFSSolver>();
    if (algorithm == "-gbfs") return std::make_unique<GBFSSolver>(std::move(heuristic));
    if (algorithm == "-astar") return std::make_unique<AStarSolver>(std::move(heuristic));
    if (algorithm == "-idastar") return std::make_unique<IDAStarSolver>(std::move(heuristic));
    return nullptr;
}