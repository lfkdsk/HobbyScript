project(unit_tests)

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} MAIN_SOURCE)

add_executable(
        unit_tests
        ${MAIN_SOURCE}
)

target_link_libraries(
        unit_tests
        gtest_main
        ${LLVM_AVAILABLE_LIBS}
        Qt5::Core
)

target_include_directories(unit_tests PUBLIC ${llvm_libs})

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
