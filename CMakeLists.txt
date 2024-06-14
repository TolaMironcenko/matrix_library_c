cmake_minimum_required (VERSION 2.6)  
project(matrix)  
  
set(cmatrixsrc src/libs/libcmatrix/matrix.c)

include_directories(./src/libs/)  

add_library(cmatrix SHARED ${cmatrixsrc})
set_target_properties(cmatrix PROPERTIES PUBLIC_HEADER "./src/libs/libcmatrix/matrix.h")

add_executable(  
    matrix   
    src/matrix.c
)  

target_link_libraries(matrix cmatrix)

install(TARGETS matrix DESTINATION bin)
install(TARGETS cmatrix 
        LIBRARY DESTINATION lib 
        PUBLIC_HEADER DESTINATION include/libcmatrix
)
