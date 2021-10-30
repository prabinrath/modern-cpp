project(cmake_proj)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

message(STATUS  "Project Path : ${PROJECT_SOURCE_DIR}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)