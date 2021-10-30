add_subdirectory(io_strategies)

add_library(image image.cpp)
target_link_libraries(image strategies)