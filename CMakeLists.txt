cmake_minimum_required(VERSION 3.10)
project(puzzle_solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Ofast")

# === GOOGLE TEST ===
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# === FONTES DO PROJETO PRINCIPAL ===
set(SOURCES
    src/puzzle_parser.cpp
    src/solver_factory.cpp
    src/solvers/bfs_solver.cpp
    src/solvers/astar_solver.cpp
    src/solvers/idastar_solver.cpp
    src/solvers/gbfs_solver.cpp
    src/solvers/idfs_solver.cpp
    src/puzzle_state.cpp
)

# Cria biblioteca interna com o core do projeto
add_library(puzzle ${SOURCES})
target_include_directories(puzzle PUBLIC
    include
    include/solvers
)

# Executável principal
add_executable(main src/main.cpp)
target_link_libraries(main puzzle)

# === TESTES UNITÁRIOS ===
set(TEST_SOURCES
    tests/puzzle_state_tests.cpp
    tests/bfs_solver_tests.cpp
    tests/idfs_solver_tests.cpp
    tests/gbfs_solver_tests.cpp
    tests/astar_solver_tests.cpp
    tests/idastar_solver_tests.cpp
    tests/astar15_solver_tests.cpp
)

add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests puzzle GTest::gtest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)
