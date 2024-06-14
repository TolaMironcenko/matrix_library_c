cmake_minimum_required (VERSION 2.6)  
project(matrix)  
  
include_directories(./src/libs/)  
  
add_executable(  
    matrix   
    src/matrix.c
    src/libs/matrix/matrix.c
)  
