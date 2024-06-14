cmake_minimum_required (VERSION 2.6)  
project(matrix)  
  
set(cmatrixsrc src/libs/matrix/matrix.c)

include_directories(./src/libs/)  

add_library(cmatrix SHARED ${cmatrixsrc})

add_executable(  
    matrix   
    src/matrix.c
)  

target_link_libraries(matrix cmatrix)
