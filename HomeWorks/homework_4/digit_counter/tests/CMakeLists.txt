# If you are not on Linux, you will need to download the source of the
# googletest framework manually and provide the folder to which you have
# - downloaded it by copying this link into your browser:
#   https://github.com/google/googletest/archive/release-1.8.0.zip
# - unpack it into some <FOLDER>
# - use this <FOLDER> instead of /usr/src/gtest in the line below.
add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)

##################### Create your tests below this line ########################
#add_executable(unit_test unit_test.cpp) # This is an executable that runs the tests.
#target_link_libraries(unit_test gtest gtest_main) # Image and GTest libraries

# add_test(
#   NAME unit_test
#   COMMAND ${EXECUTABLE_OUTPUT_PATH}/unit_test)