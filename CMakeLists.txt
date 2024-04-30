cmake_minimum_required(VERSION 3.5)
project(advent_of_code_2023)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -Wpedantic)

# Set-up GoogleTest v1.14.0
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
option(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)

# Add libraries
add_library(
  common_utils
  src/common/utils.cpp
)

add_library(
  day_1_utils
  src/day_1/utils.cpp
)
add_library(
  day_1_calibration_tool
  src/day_1/calibration_tool.cpp
)
target_include_directories(
  day_1_calibration_tool
  PRIVATE src
)
target_link_libraries(
  day_1_calibration_tool
  day_1_utils 
  common_utils
)

add_library(
  day_2_cubes_set
  src/day_2/cubes_set.cpp
)
add_library(
  day_2_game
  src/day_2/game.cpp
)
add_library(
  day_2_game_helper
  src/day_2/game_helper.cpp
)
target_include_directories(
  day_2_cubes_set
  PRIVATE src
)
target_include_directories(
  day_2_game
  PRIVATE src
)
target_include_directories(
  day_2_game_helper
  PRIVATE src
)
target_link_libraries(
  day_2_cubes_set
  common_utils
)
target_link_libraries(
  day_2_game
  common_utils
)
target_link_libraries(
  day_2_game_helper
  day_2_cubes_set
  day_2_game
  common_utils
)

add_library(
  day_3_engine_schematic
  src/day_3/engine_schematic.cpp
)
add_library(
  day_3_engine_checker
  src/day_3/engine_checker.cpp
)
target_link_libraries(
  day_3_engine_checker
  day_3_engine_schematic
)

add_library(
  day_4_scratch_card
  src/day_4/scratch_card.cpp
)
add_library(
  day_4_prize_checker
  src/day_4/prize_checker.cpp
)
add_library(
  day_4_utils
  src/day_4/utils.cpp
)
target_include_directories(
  day_4_scratch_card
  PRIVATE src
)
target_link_libraries(
  day_4_scratch_card
  common_utils
)
target_link_libraries(
  day_4_prize_checker
  day_4_scratch_card
)
target_link_libraries(
  day_4_utils
  day_4_scratch_card
)

# Add executables
add_executable(
  day_1
  src/day_1/day_1.cpp
)
target_link_libraries(
  day_1
  day_1_calibration_tool
)

add_executable(
  day_2
  src/day_2/day_2.cpp
)
target_link_libraries(
  day_2
  day_2_game_helper
  day_2_cubes_set
)

add_executable(
  day_3
  src/day_3/day_3.cpp
)
target_include_directories(
  day_3
  PRIVATE src
)
target_link_libraries(
  day_3
  day_3_engine_checker
  day_3_engine_schematic
  common_utils
)

add_executable(
  day_4
  src/day_4/day_4.cpp
)
target_include_directories(
  day_4
  PRIVATE src
)
target_link_libraries(
  day_4
  day_4_prize_checker
  day_4_scratch_card
  day_4_utils
  common_utils
)

# Add test files
add_executable(
  day_1_tests
  tests/day_1_tests.cpp
)
target_include_directories(
  day_1_tests
  PRIVATE src
)
target_link_libraries(
  day_1_tests
  day_1_calibration_tool
  GTest::gtest_main
)

add_executable(
  day_2_tests
  tests/day_2_tests.cpp
)
target_include_directories(
  day_2_tests
  PRIVATE src
)
target_link_libraries(
  day_2_tests
  day_2_cubes_set
  day_2_game
  day_2_game_helper
  GTest::gtest_main
)

add_executable(
  day_3_tests
  tests/day_3_tests.cpp
)
target_include_directories(
  day_3_tests
  PRIVATE src
)
target_link_libraries(
  day_3_tests
  day_3_engine_checker
  day_3_engine_schematic
  GTest::gtest_main
)

add_executable(
  day_4_tests
  tests/day_4_tests.cpp
)
target_include_directories(
  day_4_tests
  PRIVATE src
)
target_link_libraries(
  day_4_tests
  day_4_scratch_card
  day_4_prize_checker
  day_4_utils
  GTest::gtest_main
)

# Copy puzzle inputs
install(DIRECTORY
  data
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)