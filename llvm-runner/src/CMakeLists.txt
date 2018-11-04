CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(LLVM_Runner)

set(CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(ast AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/common AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/literals AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/expr AST_SOURCE)
AUX_SOURCE_DIRECTORY(ast/stmt AST_SOURCE)
AUX_SOURCE_DIRECTORY(visitor VISITOR_SOURCE)
AUX_SOURCE_DIRECTORY(llvm LLVM_SOURCE)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} MAIN_SOURCE)


SET(SOURCE_FILES
        ${SOURCE_FILES}
        ${AST_SOURCE}
        ${VISITOR_SOURCE}
        ${LLVM_SOURCE}
        ${MAIN_SOURCE})

message(STATUS ${SOURCE_FILES})

add_executable(LLVM_Runner ${SOURCE_FILES})

# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)

# target link lib
TARGET_LINK_LIBRARIES(LLVM_Runner UnitCppLib ${llvm_libs})