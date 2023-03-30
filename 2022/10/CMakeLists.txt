# Move the data files to the cmake binary directory.
file(COPY "${CMAKE_SOURCE_DIR}/2022/10/data.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_SOURCE_DIR}/2022/10/example.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")