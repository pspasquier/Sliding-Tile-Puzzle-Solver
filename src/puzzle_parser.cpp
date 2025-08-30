#include "puzzle_parser.hpp"
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <unordered_set>

namespace {

std::vector<int> parse_single_state(const std::string& group) {
    std::vector<int> state;
    std::istringstream group_stream(group);
    std::string token;
    int tile;
    
    while (group_stream >> token) {
        try {
            tile = std::stoi(token);
        } catch (const std::invalid_argument&) {
            throw std::runtime_error("Invalid tile value: " + token);
        } catch (const std::out_of_range&) {
            throw std::runtime_error("Tile value out of range: " + token);
        }
        state.push_back(tile);
    }
    
    return state;
}

void validate_state(const std::vector<int>& state) {
    const size_t expected_size = state.size();
    const bool valid_size = (expected_size == 9 || expected_size == 16);
    
    if (!valid_size) {
        throw std::runtime_error("Invalid state size: " 
            + std::to_string(expected_size));
    }

    std::unordered_set<int> unique_tiles(state.begin(), state.end());
    const bool has_duplicates = (unique_tiles.size() != expected_size);
    const bool has_valid_range = std::all_of(state.begin(), state.end(),
        [expected_size](int tile) { 
            return tile >= 0 && tile < static_cast<int>(expected_size); 
        });

    if (has_duplicates) {
        throw std::runtime_error("Duplicate tiles found in state");
    }

    if (!has_valid_range) {
        throw std::runtime_error("Tile values out of valid range");
    }

    if (unique_tiles.count(0) != 1) {
        throw std::runtime_error("State must contain exactly one empty tile (0)");
    }
}

}

namespace PuzzleParser {

std::vector<std::vector<int>> parse_states(const std::string& input) {
    std::vector<std::vector<int>> states;
    std::istringstream iss(input);
    std::string group;
    int state_count = 0;

    while (std::getline(iss, group, ',')) {
        state_count++;
        try {
            group.erase(group.find_last_not_of(" \t\n\r") + 1);
            group.erase(0, group.find_first_not_of(" \t\n\r"));

            if (group.empty()) {
                throw std::runtime_error("Empty state group");
            }

            auto state = parse_single_state(group);
            validate_state(state);
            states.push_back(std::move(state));
        } catch (const std::exception& e) {
            throw std::runtime_error("Error in state group #" 
                + std::to_string(state_count) + ": " + e.what());
        }
    }

    if (states.empty()) {
        throw std::runtime_error("No valid states provided");
    }

    return states;
}

}