CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} COMMON_SOURCE)

SET(COMMON_SOURCE ${COMMON_SOURCE} PARENT_SCOPE)
