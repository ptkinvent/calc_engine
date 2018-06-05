# Build instructions for example executable using libcalc

find_path(CALCLIB_INCLUDE_DIR BaseEngine.h ${CMAKE_CURRENT_SOURCE_DIR}/../calc_lib/include)

set(CALC_EXAMPLE_SRCS
        src/main.cpp
)

include_directories(
        include
)

add_executable(calc_example ${CALC_EXAMPLE_SRCS})


target_include_directories(calc_example PRIVATE
        ${CALCLIB_INCLUDE_DIR}
)

target_link_libraries(calc_example calc)
