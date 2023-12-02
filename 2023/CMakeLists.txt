add_subdirectory(01)
add_subdirectory(02)
add_subdirectory(03)
add_subdirectory(04)
add_subdirectory(05)
add_subdirectory(06)
add_subdirectory(07)
add_subdirectory(08)
add_subdirectory(09)
add_subdirectory(10)
add_subdirectory(11)
add_subdirectory(12)
add_subdirectory(13)
add_subdirectory(14)
add_subdirectory(15)
add_subdirectory(16)
add_subdirectory(17)
add_subdirectory(18)
add_subdirectory(19)
add_subdirectory(20)
add_subdirectory(21)
add_subdirectory(22)
add_subdirectory(23)
add_subdirectory(24)
add_subdirectory(25)

add_library(
        adventofcode_2023_lib SHARED
        01/day_2023_01.h
        01/day_2023_01.cpp
        02/day_2023_02.h
        02/day_2023_02.cpp
        03/day_2023_03.h
        03/day_2023_03.cpp
        04/day_2023_04.h
        04/day_2023_04.cpp
        05/day_2023_05.h
        05/day_2023_05.cpp
        06/day_2023_06.h
        06/day_2023_06.cpp
        07/day_2023_07.h
        07/day_2023_07.cpp
        08/day_2023_08.h
        08/day_2023_08.cpp
        09/day_2023_09.h
        09/day_2023_09.cpp
        10/day_2023_10.h
        10/day_2023_10.cpp
        11/day_2023_11.h
        11/day_2023_11.cpp
        12/day_2023_12.h
        12/day_2023_12.cpp
        13/day_2023_13.h
        13/day_2023_13.cpp
        14/day_2023_14.h
        14/day_2023_14.cpp
        15/day_2023_15.h
        15/day_2023_15.cpp
        16/day_2023_16.h
        16/day_2023_16.cpp
        17/day_2023_17.h
        17/day_2023_17.cpp
        18/day_2023_18.h
        18/day_2023_18.cpp
        19/day_2023_19.h
        19/day_2023_19.cpp
        20/day_2023_20.h
        20/day_2023_20.cpp
        21/day_2023_21.h
        21/day_2023_21.cpp
        22/day_2023_22.h
        22/day_2023_22.cpp
        23/day_2023_23.h
        23/day_2023_23.cpp
        24/day_2023_24.h
        24/day_2023_24.cpp
        25/day_2023_25.h
        25/day_2023_25.cpp
)

target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/01")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/02")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/03")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/04")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/05")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/06")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/07")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/08")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/09")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/10")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/11")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/12")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/13")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/14")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/15")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/16")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/17")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/18")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/19")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/20")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/21")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/22")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/23")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/24")
target_include_directories(adventofcode_2023_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/25")
