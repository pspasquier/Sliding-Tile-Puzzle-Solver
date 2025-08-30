# Sliding-Tile Puzzle Solver (N-Puzzle)

This project is an implementation of the **N-Puzzle (Sliding-Tile Puzzle)** solver in C++, developed as part of the **Advanced Artificial Intelligence** course at **UFRGS**.  
It is designed with a modular and extensible architecture to support different search strategies.

---

## Features

- Supports customizable N-Puzzle sizes (e.g., **8-puzzle**, **15-puzzle**).  
- Multiple search algorithms implemented:
  - **BFS** (Breadth-First Search)  
  - **IDFS** (Iterative Deepening DFS)  
  - **GBFS** (Greedy Best-First Search)  
  - **A\*** (A-Star Search)
  - **IDA\*** (Iterative Deepening A-Star)
- Utilize the Manhattan distance as heuristic for GBFS, A\* and IDA\*
- Tracks important search metrics:
  - Number of expanded nodes  
  - Solution cost (solution length)  
  - Execution time  
  - Heuristic values (initial, mean)  
- Automatic test suites with **CTest**.  
- Bash scripts to benchmark **8-puzzle** and **15-puzzle** under time and memory constraints.  

---

## Build Instructions

This project uses **CMake** as the build system and **GoogleTest/CTest** for testing.

### Requirements
- C++17 or later  
- CMake 3.10+  

### Steps
```
git clone https://github.com/pspasquier/Sliding-Tile-Puzzle-Solver
cd Sliding-Tile-Puzzle-Solver
mkdir build && cd build
cmake ..
make
ctest
```

---

## Running the Solver

After building, the solver binary is available inside the build/ folder.

### Syntax

```./main -<algorithm> <puzzles configuration>```

### Parameters

- algorithm → Search strategy to use. Options:
  - bfs → Breadth-First Search
  - idfs → Iterative Deepening DFS
  - gbfs → Greedy Best-First Search
  - astar → A* Search
  - idastar → Iterative Deepening A*
- puzzles configuration → Initial puzzle states, as a flattened list of numbers separated by spaces, each configuration separated by comma:

### Example
```
cd build
./main -bfs 0 6 1 7 4 2 3 8 5, 5 0 2 6 4 8 1 7 3, 2 4 7 0 3 6 8 1 5
./main -astar 7 11 8 3 14 0 6 15 1 4 13 9 5 12 2 10
```

---

## Benchmark Scripts

Two helper scripts are provided to automatically run batches of instances under time and memory constraints. Results are stored in the results/ directory as .csv files

### 8-Puzzle script

- Time limit: 10 minutes for the entire dataset
- Memory limit: 4 GB for the entire dataset
- Runs with a chosen algorithm.

```./scripts/8-puzzle_benchmark.sh astar```

### 15-Puzzle script
- Time limit: 30 seconds for each state
- Memory limit: 8 GB for each state
- Runs with A*

```./scripts/15-puzzle_benchmark.sh```

---

## Future Work
- Make heuristic modular and add:
  - Euclidean distance
  - Linear conflict
  - Pattern databases
- Implement parallel solvers for large puzzles
- Add visualization of the state space
- Improve memory management for very large instances

