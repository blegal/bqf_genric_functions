cmake_minimum_required(VERSION 3.7)

project(test_asm)

SET(CMAKE_BUILD_TYPE Release)

#SET (CMAKE_C_COMPILER   /usr/bin/clang++-17)
#SET (CMAKE_CXX_COMPILER /usr/bin/clang++-17)
SET (CMAKE_CXX_STANDARD 17)
SET (CMAKE_CXX_FLAGS "")
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -Wall -march=native -mtune=native --std=c++17")
SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -I. -L/usr/local/lib")

# Generate the source files list
file (GLOB_RECURSE source_files src/*)

# Add includes
include_directories (src)

# Object
add_library (dec-obj OBJECT ${source_files})


add_executable(test_asm $<TARGET_OBJECTS:dec-obj>)

