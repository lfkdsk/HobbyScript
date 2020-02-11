project(unit_tests)

add_definitions(-DPROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR})
configure_file(test_config.h.in ${CMAKE_BINARY_DIR}/generated/test_config.h)
include_directories(${CMAKE_BINARY_DIR}/generated/)

find_package(Qt5 COMPONENTS Core Test REQUIRED)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} MAIN_SOURCE)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

get_filename_component(PARENT_DIR ../ ABSOLUTE)
include_directories(${PARENT_DIR}/src)

git_clone(
        PROJECT_NAME llvmcppapi
        GIT_URL git@github.com:zhangjiantao/llvm-cxxapi.git
        GIT_BRANCH master
)

AUX_SOURCE_DIRECTORY(${llvmcppapi_SOURCE_DIR} CPP_END_SOURCE)
SET(CPPEND ${CPP_END_SOURCE})
LIST(REMOVE_ITEM CPPEND ${llvmcppapi_SOURCE_DIR}/llvm-cxxapi.cpp)
INCLUDE_DIRECTORIES(${llvmcppapi_SOURCE_DIR})

add_executable(
        unit_tests
        ${MAIN_SOURCE}
        ${CPPEND}
)

target_link_libraries(
        unit_tests
        PUBLIC
        gtest
        HobbyLib
        Qt5::Core
        ${LLVM_AVAILABLE_LIBS}
)

target_include_directories(unit_tests PUBLIC ${llvm_libs})

add_test(
        NAME
        unit
        COMMAND
        unit_tests
)
