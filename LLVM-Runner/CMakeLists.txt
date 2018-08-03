CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(LLVM_Runner)

set(CMAKE_CXX_STANDARD 17)

# import llvm

find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Set your project compile flags.
# E.g. if using the C++ header files
# you will need to enable C++11 support
# for your compiler.

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})


# include src
include_directories(includes)
add_subdirectory(includes)
add_subdirectory(src)

message(STATUS ${SOURCE_FILES})

add_executable(LLVM_Runner ${SOURCE_FILES})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# target link lib
TARGET_LINK_LIBRARIES(LLVM_Runner UnitCppLib ${llvm_libs})
