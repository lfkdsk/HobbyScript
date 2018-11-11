CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

project(llvm-runner)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(ast AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/common AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/literals AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/expr AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/stmt AST_SOURCE)

AUX_SOURCE_DIRECTORY(gen GEN_SOURCE)
AUX_SOURCE_DIRECTORY(gen/value GEN_SOURCE)
AUX_SOURCE_DIRECTORY(gen/expr GEN_SOURCE)
AUX_SOURCE_DIRECTORY(gen/literals GEN_SOURCE)

AUX_SOURCE_DIRECTORY(visitor VISITOR_SOURCE)
AUX_SOURCE_DIRECTORY(test TEST_SOURCE)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} MAIN_SOURCE)

SET(SOURCE_FILES
        ${AST_SOURCE}
        ${VISITOR_SOURCE}
        ${GEN_SOURCE}
        ${TEST_SOURCE})

message(STATUS ${SOURCE_FILES})

#add_library(source ${SOURCE_FILES})
#target_include_directories(source PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(llvm-runner main.cpp ${SOURCE_FILES})
# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# target link lib
TARGET_LINK_LIBRARIES(llvm-runner ${llvm_libs} gtest_main)