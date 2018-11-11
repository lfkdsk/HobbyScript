CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(LLVM_Runner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# import llvm
find_package(LLVM REQUIRED CONFIG)
find_package(RapidJSON)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

if (TARGET spdlog)
    # Part of the main project
    add_library(spdlog::spdlog ALIAS spdlog)
endif ()

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)

# include src
include_directories(includes)
add_subdirectory(includes)
add_subdirectory(src)
#enable_testing()
#add_subdirectory(tests)
