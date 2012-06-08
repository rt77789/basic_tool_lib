#SET(CMAKE_VERBOSE_MAKEFILE on)

set(project_name "main")

project(${project_name})

cmake_minimum_required(VERSION 2.6)

add_subdirectory(src)
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(test)

message("current project source dir: ${${project_name}_SOURCE_DIR}")
message("current project source dir: ${${project_name}_BINARY_DIR}")

#SET(CMAKE_LIBRARY_PATH ${PROJECT_SOURCE_DIR}/lib)
#SET(CMAKE_INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include/)
#SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)


#INCLUDE_DIRECTORIES(/Users/rt77789/code/tmp/gtest/gtest-1.6.0/include/)

# add_definitions();
# EXECUTABLE_OUTPUT_PATH
# LIBRARY_OUTPUT_PATH
# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#SET(CMAKE_INSTALL_PREFIX /Users/rt77789/code/tmp)
#把握一个简单的原则,在哪里 ADD_EXECUTABLE 或 ADD_LIBRARY, 如果需要改变目标存放路径,就在哪里加入上述的定义。
# CMAKE_INSTALL_PREFIX 的默认定义是/usr/local
#add_executable(a.out main.cpp src/util.h) 
