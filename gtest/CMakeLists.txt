# Build tests

find_package(GTest REQUIRED)

set(TEST_SRCS
        src/main.cpp
        src/EngineTest.cpp
)

include_directories(
        include
)

add_executable(calc_test
        ${TEST_SRCS}
)

target_link_libraries(calc_test
        calc
        ${GTEST_BOTH_LIBRARIES}
)
