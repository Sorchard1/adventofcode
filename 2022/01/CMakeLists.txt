#add_library(day202201 day_2022_01.cpp day_2022_01.h)
#target_include_directories(day202201 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Move the data files to the cmake binary directory.
file(COPY "${CMAKE_SOURCE_DIR}/2022/01/data.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")