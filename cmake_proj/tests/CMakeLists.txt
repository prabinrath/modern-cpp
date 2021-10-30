add_subdirectory(/usr/src/gtest ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.

set(TEST_BINARY ${PROJECT_NAME}_test) # Set binary name for convenience.

add_executable(${TEST_BINARY} unit_test.cpp) # This is an executable that runs the tests.
target_link_libraries(${TEST_BINARY} division multiply gtest gtest_main) # GTest libraries

add_test(
  NAME ${TEST_BINARY}
  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})