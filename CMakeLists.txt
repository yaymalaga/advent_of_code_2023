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
  day_1_utils
  src/day_1/utils.cpp
)
add_library(
  day_1_calibration_tool
  src/day_1/calibration_tool.cpp
)
target_link_libraries(
  day_1_calibration_tool
  day_1_utils
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

# Copy puzzle inputs
install(DIRECTORY
  data
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)