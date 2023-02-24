add_executable(01 main.cpp)
# Move the data files to the cmake binary directory.

file(COPY "${CMAKE_SOURCE_DIR}/2022/01/data.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")