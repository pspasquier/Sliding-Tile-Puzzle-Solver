#ifndef PUZZLE_PARSER_HPP
#define PUZZLE_PARSER_HPP

#include <vector>
#include <string>

namespace PuzzleParser {

std::vector<std::vector<int>> parse_states(const std::string& input);

}

#endif