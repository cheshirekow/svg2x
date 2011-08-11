cmake_minimum_required(VERSION 2.8)

# defines the project name
project (svg2x)

# adds the project-specific cmake module directory cmake/Modules to the cmake
# search path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# finds pkg-config
find_package(PkgConfig REQUIRED)

# add the src/ subdirectory to the list of directories cmake processes
add_subdirectory(src)

# use Jan Woetzel's doxygen doc target
include("${CMAKE_MODULE_PATH}/TargetDoc.cmake" OPTIONAL)
