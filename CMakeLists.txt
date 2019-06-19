cmake_minimum_required (VERSION 2.8)

project (DataStructureForMedian)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(alcatraz tests.cpp)
target_link_libraries(alcatraz ${GTEST_LIBRARIES} pthread)
