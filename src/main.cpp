#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "solver_factory.hpp"
#include "puzzle_parser.hpp"
#include "puzzle_state.hpp"

int main(int argc, char* argv[]) {
    try {
        if (argc < 3) {
            throw std::runtime_error(
                "Usage: " + std::string(argv[0]) + " <algorithm> <state(s)>"
            );
        }

        const std::string algorithm(argv[1]);
        const std::string input = [&]() {
            std::ostringstream oss;
            for (int i = 2; i < argc; ++i) {
                oss << argv[i] << ' ';
            }
            return oss.str();
        }();

        auto solver = SolverFactory::create(algorithm);
        if (!solver) {
            throw std::runtime_error("Unsupported algorithm: " + algorithm);
        }

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