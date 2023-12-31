cmake_minimum_required(VERSION 3.11.0)
project(T2-list VERSION 0.1.0)

enable_language(CXX)


message(STATUS "BUILD directory is ${CMAKE_BINARY_DIR}")
message(STATUS "SRC directory is ${CMAKE_SOURCE_DIR}")
#include(CTest)
#enable_testing()

# Add all .cpp, - files under src/ directory
# Add all .cpp, - files under src/ directory
file(GLOB SOURCES_C "src/*.c")
file(GLOB SOURCES_CPP "src/*.cpp")
set(SOURCES ${SOURCES_C} ${SOURCES_CPP})
message(STATUS "SRC directory source code files: \n\t-- C SOURCES: ${SOURCES_C}\n\t-- CPP SOURCE:${SOURCES_CPP}\n\t-- ALL:${SOURCES}")
# add the executable target
add_executable(T2-list)
set(CMAKE_BUILD_TYPE Debug)

target_sources(T2-list PUBLIC ${SOURCES})
target_include_directories(T2-list PUBLIC .)

set_source_files_properties(SOURCES_CPP PROPERTIES COMPILE_FLAGS -std-c++17)
target_compile_options (T2-list PRIVATE -Wall -Wextra -pedantic -g -Wno-missing-field-initializers)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options("-stdlib=libc++")
else()
    # nothing special for gcc at the moment
endif()
