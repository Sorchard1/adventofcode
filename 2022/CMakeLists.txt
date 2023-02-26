add_subdirectory(01)
add_subdirectory(02)

add_library(
        adventofcode_2022_lib SHARED
        01/day_2022_01.h
        01/day_2022_01.cpp
        02/day_2022_02.h
        02/day_2022_02.cpp
)

target_include_directories(adventofcode_2022_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/01")
target_include_directories(adventofcode_2022_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/02")