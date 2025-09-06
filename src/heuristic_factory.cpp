#include <memory>
#include <string>
#include "heuristic_factory.hpp"
#include "heuristics/manhattan_heuristic.hpp"
#include "heuristics/misplaced_heuristic.hpp"
#include "heuristics/euclidean_heuristic.hpp"
#include "heuristics/linear_conflict_heuristic.hpp"

std::unique_ptr<HeuristicBase> HeuristicFactory::create(const std::string& heuristic) {
    if (heuristic == "-manhattan") return std::make_unique<ManhattanHeuristic>();
    if (heuristic == "-misplaced") return std::make_unique<MisplacedHeuristic>();
    if (heuristic == "-euclidean") return std::make_unique<EuclideanHeuristic>();
    if (heuristic == "-linear_conflict") return std::make_unique<LinearConflictHeuristic>();
    return nullptr;
}
