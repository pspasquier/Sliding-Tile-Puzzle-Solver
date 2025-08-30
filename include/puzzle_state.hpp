#ifndef PUZZLE_STATE_HPP
#define PUZZLE_STATE_HPP

#include <vector>
#include <cstdint>
#include <functional>

enum class MoveDirection { UP, DOWN, LEFT, RIGHT, NONE };

class PuzzleState {
public:
    static int board_size;
    std::vector<int> tiles;
    int order;
    MoveDirection action;
    int h;
    int g;
    int f;
    int blank_pos;

    PuzzleState(const std::vector<int>& state);
    PuzzleState(const std::vector<int>& state, int order, MoveDirection action, int h, int g, int blank_pos);

    bool is_goal() const;
    std::vector<PuzzleState> generate_successors() const;
    uint64_t serialize() const;

    static int manhattan_distance(int value, int position);
    static int compute_heuristic(const std::vector<int>& tiles);
    bool can_move(MoveDirection dir) const;
    static MoveDirection opposite_direction(MoveDirection dir);

    void print_state() const;
    const char* print_action(MoveDirection dir) const;
};

#endif // PUZZLE_STATE_HPP
