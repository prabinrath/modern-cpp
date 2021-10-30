find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
add_library(strategies png_strategy.cpp ppm_strategy.cpp)
target_link_libraries(strategies ${PNG_LIBRARY})