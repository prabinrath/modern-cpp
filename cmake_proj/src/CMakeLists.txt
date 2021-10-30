add_library(multiply multiply.cpp)
add_library(division division.cpp)

add_executable(main_prog main_prog.cpp)
target_link_libraries(main_prog multiply division)