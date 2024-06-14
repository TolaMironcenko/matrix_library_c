cmake_minimum_required (VERSION 2.6)  
project(matrix)  
  
set(libcmatrixsrc src/libs/matrix/matrix.c)

include_directories(./src/libs/)  
  
add_library(libcmatrix ${libcmatrixsrc})

add_executable(  
    matrix   
    src/matrix.c
    # src/libs/matrix/matrix.c
)  

target_link_libraries(matrix libcmatrix)
