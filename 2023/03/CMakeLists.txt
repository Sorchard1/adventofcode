# Move the data files to the cmake binary directory.
file(COPY "${CMAKE_SOURCE_DIR}/2023/03/data.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
file(COPY "${CMAKE_SOURCE_DIR}/2023/03/example.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
