CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(LLVM_Runner)

set(CMAKE_CXX_STANDARD 17)

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
    MESSAGE(STARUS "****")
    # Part of the main project
    add_library(spdlog::spdlog ALIAS spdlog)
endif ()

INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

AUX_SOURCE_DIRECTORY(test TEST_SOURCE)

AUX_SOURCE_DIRECTORY(ast AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/common AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/literals AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/expr AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/stmt AST_SOURCE)

AUX_SOURCE_DIRECTORY(visitor VISITOR_SOURCE)
AUX_SOURCE_DIRECTORY(llvm LLVM_SOURCE)

AUX_SOURCE_DIRECTORY(gen GEN_SOURCE)
AUX_SOURCE_DIRECTORY(gen/value GEN_SOURCE)
AUX_SOURCE_DIRECTORY(gen/expr GEN_SOURCE)
AUX_SOURCE_DIRECTORY(gen/literals GEN_SOURCE)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} MAIN_SOURCE)
INCLUDE_DIRECTORIES(utils)

SET(SOURCE_FILES
        ${AST_SOURCE}
        ${VISITOR_SOURCE}
        ${LLVM_SOURCE}
        ${GEN_SOURCE}
        ${TEST_SOURCE}
        ${MAIN_SOURCE})

message(STATUS ${SOURCE_FILES})

add_executable(LLVM_Runner ${SOURCE_FILES})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# target link lib
TARGET_LINK_LIBRARIES(LLVM_Runner UnitCppLib ${llvm_libs})