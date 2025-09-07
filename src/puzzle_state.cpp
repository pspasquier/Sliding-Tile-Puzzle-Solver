#include "puzzle_state.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>

int PuzzleState::board_size = 0;

PuzzleState::PuzzleState(const std::vector<int>& state)
    : tiles(state),
      order(0),
      action(MoveDirection::NONE),
      h(0),
      g(0),
      f(h),
      blank_pos(std::distance(state.begin(), std::find(state.begin(), state.end(), 0)))
{}

PuzzleState::PuzzleState(const std::vector<int>& state, MoveDirection action, int g, int blank_pos)
    : tiles(state),
      order(0),
      action(action),
      h(0),
      g(g),
      f(0),
      blank_pos(blank_pos)
{}

bool PuzzleState::is_goal() const {
    for (size_t i = 0; i < tiles.size(); ++i) {
        if (tiles[i] != static_cast<int>(i))
            return false;
    }
    return true;
}

bool PuzzleState::can_move(MoveDirection dir) const {
    int row = blank_pos / board_size;
    int col = blank_pos % board_size;

    switch (dir) {
        case MoveDirection::LEFT : return col > 0;
        case MoveDirection::RIGHT: return col < board_size - 1;
        case MoveDirection::UP   : return row > 0;
        case MoveDirection::DOWN : return row < board_size - 1;
        default                  : return false;
    }
}

MoveDirection PuzzleState::opposite_direction(MoveDirection dir) {
    switch (dir) {
        case MoveDirection::UP   : return MoveDirection::DOWN;
        case MoveDirection::DOWN : return MoveDirection::UP;
        case MoveDirection::LEFT : return MoveDirection::RIGHT;
        case MoveDirection::RIGHT: return MoveDirection::LEFT;
        default                  : return MoveDirection::NONE;
    }
}

std::vector<PuzzleState> PuzzleState::generate_successors() const {
    std::vector<PuzzleState> successors;

    const std::vector<std::tuple<int, MoveDirection>> moves = {
        { -board_size, MoveDirection::UP    },
        { -1,          MoveDirection::LEFT  },
        { +1,          MoveDirection::RIGHT },
        { +board_size, MoveDirection::DOWN  },
    };

    for (const auto& [offset, direction] : moves) {
        if (direction == opposite_direction(action) || !can_move(direction))
            continue;
         
        int new_position = blank_pos + offset;
        std::vector<int> new_tiles = tiles;
        std::swap(new_tiles[blank_pos], new_tiles[new_position]);

        successors.emplace_back(new_tiles, direction, g + 1, new_position);
    }

    return successors;
}

uint64_t PuzzleState::serialize() const {
    uint64_t result = 0;
    const int BITS = 4;
    for (size_t i = 0; i < tiles.size(); ++i) {
        result |= (static_cast<uint64_t>(tiles[i]) << (i * BITS));
    }
    return result;
}

void PuzzleState::print_state() const {
    std::cout << "Action : " << print_action(action) << "\n";

    for (int i = 0; i < static_cast<int>(tiles.size()); ++i) {
        if (tiles[i] == 0) {
            std::cout << std::setw(2) << " " << " ";
        } else {
            std::cout << std::setw(2) << tiles[i] << " ";
        }

        if ((i + 1) % board_size == 0) {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;
}

const char* PuzzleState::print_action(MoveDirection dir) const {
    switch (dir) {
        case MoveDirection::UP:    return "UP";
        case MoveDirection::DOWN:  return "DOWN";
        case MoveDirection::LEFT:  return "LEFT";
        case MoveDirection::RIGHT: return "RIGHT";
        case MoveDirection::NONE:  return "START";
    }
    return "?";
}