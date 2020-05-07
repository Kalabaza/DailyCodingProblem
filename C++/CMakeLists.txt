cmake_minimum_required(VERSION 3.15)
project(DailyCodingProblem CXX)

include(GoogleTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

##################################################
# Macro to make a unit test binary for difficulty
##################################################
macro(package_add_test TESTNAME)
   file(GLOB SOURCES "${TESTNAME}/*.cpp")
   add_executable(${TESTNAME} ${SOURCES})
   target_link_libraries(${TESTNAME} gtest gtest_main pthread)
   gtest_discover_tests(${TESTNAME}
      WORKING_DIRECTORY ${PROJECT_DIR}
      PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
   )
   set_target_properties(${TESTNAME} PROPERTIES COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
   add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
endmacro()

########################
# Unit tests by difficulty
########################
package_add_test(Easy)
# package_add_test(Medium)
package_add_test(Hard)

######################################
# Run the tests after the compilation
######################################
add_custom_target(tests ALL COMMAND ${CMAKE_CTEST_COMMAND} --progress)
