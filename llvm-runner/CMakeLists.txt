CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

project(LLVM_Runner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${CMAKE_SOURCE_DIR}/cmake
)

# import llvm
find_package(LLVM REQUIRED CONFIG)
find_package(RapidJSON)
find_package(Qt5 COMPONENTS Core REQUIRED)

message(STATUS "Found LLVM! ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Found LLVM_AVAILABLE_LIBS as: ${LLVM_AVAILABLE_LIBS}")

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

include(cmake/GitUtils.cmake)

#git_clone(
#        PROJECT_NAME rapidjson
#        GIT_URL https://github.com/Tencent/rapidjson
#        GIT_TAG v1.1.0
#)
#include_directories(${rapidjson_SOURCE_DIR}/include)

#git_clone(
#        PROJECT_NAME imgui
#        GIT_URL https://github.com/ocornut/imgui
#        GIT_TAG v1.74
#)

# include src
include_directories(includes)
add_subdirectory(includes)
add_subdirectory(src)

add_subdirectory(tests)
enable_testing()
