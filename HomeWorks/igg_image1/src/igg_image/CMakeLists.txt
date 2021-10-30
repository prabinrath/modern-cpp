#################### Import the 'io_tools' library here ########################
find_library(IO_TOOLS
			 NAMES io_tools
			 PATHS ${LIBRARY_OUTPUT_PATH})
#################### Create a library 'image' below this line ##################
add_library(image image.cpp)
target_link_libraries(image ${IO_TOOLS})