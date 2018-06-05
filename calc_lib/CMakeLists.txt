# Build and install instructions for shared object library

set(LIB_SRCS
        src/IntStreamer.cpp
        src/BaseEngine.cpp
        src/MultiplierEngine.cpp
        src/DividerEngine.cpp
)

set(LIB_HEADERS
        include
)

# Install all headers into subdirectory
set(INSTALL_SUBDIRECTORY libcalc)

include_directories(
        ${LIB_HEADERS}
)

add_library(calc SHARED ${LIB_SRCS})

# Include standard irectories
target_include_directories(calc PUBLIC
        include
)
