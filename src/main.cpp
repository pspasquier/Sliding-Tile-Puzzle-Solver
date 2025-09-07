#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "solver_factory.hpp"
#include "heuristic_factory.hpp"
#include "puzzle_parser.hpp"
#include "puzzle_state.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc < 4) {
            throw std::runtime_error("Usage: " + std::string(argv[0]) +
                                     " <algorithm> <heuristic> <state(s)>");
        }

        const std::string algorithm_name(argv[1]);
        const std::string heuristic_name(argv[2]);
        const int stateStartIndex = 3;

        std::ostringstream oss;
        for (int i = stateStartIndex; i < argc; ++i)
            oss << argv[i] << ' ';
        const std::string input = oss.str();

        auto heuristic = HeuristicFactory::create(heuristic_name);
        if (!heuristic)
            throw std::runtime_error("Unsupported heuristic: " + heuristic_name);

        auto solver = SolverFactory::create(algorithm_name, std::move(heuristic));
        if (!solver)
            throw std::runtime_error("Unsupported algorithm: " + algorithm_name);

        const auto states = PuzzleParser::parse_states(input);
        for (const auto& state : states) {
            PuzzleState::board_size = static_cast<int>(std::sqrt(state.size()));
            PuzzleState initial(state);
            const auto result = solver->solve(initial);

            std::cout << result.nodes_expanded << ","
                      << result.solution_length << ","
                      << result.execution_time.count() << ","
                      << result.heuristic_mean << ","
                      << result.initial_heuristic << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
