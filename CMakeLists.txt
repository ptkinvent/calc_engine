cmake_minimum_required(VERSION 3.2)
project(calc VERSION 1.0)



# Build options
option(BUILD_GTEST "Build GTests" ON)
option(BUILD_DOC "Build Doxygen" ON)


# Set up environment (have to include -pthread to make gtest compile in Ubuntu)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# Build .so
add_subdirectory(calc_lib)


# Build example
add_subdirectory(calc_example)


# Build Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND AND BUILD_DOC)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen" VERBATIM
            )
endif(DOXYGEN_FOUND AND BUILD_DOC)


# Build GTest
find_package(GTest)
if (GTEST_FOUND AND BUILD_GTEST)

    message(STATUS "GTest found, building test framework.")
    add_subdirectory(gtest)

else(GTEST_FOUND AND BUILD_GTEST)

    message(STATUS "GTest not found, Skipping build for test framework.")

endif(GTEST_FOUND AND BUILD_GTEST)
