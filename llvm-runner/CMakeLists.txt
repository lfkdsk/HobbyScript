CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(LLVM_Runner)
set(CMAKE_CXX_STANDARD 17)

# include src
include_directories(includes)
add_subdirectory(includes)
add_subdirectory(src)