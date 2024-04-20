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

# Add test files
set(TEST_FILES
)

foreach(TEST_FILE ${TEST_FILES})
  add_executable(
    ${TEST_FILE}
    tests/${TEST_FILE}.cpp
  )
  target_link_libraries(
    ${TEST_FILE}
    GTest::gtest_main
  )
endforeach()

# Copy puzzle inputs
install(DIRECTORY
  ${CMAKE_CURRENT_SOURCE_DIR}/data
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)