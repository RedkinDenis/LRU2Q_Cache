# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

project(caches)
cmake_minimum_required(VERSION 3.10)

set(INCLUDE_DIR2 ${CMAKE_SOURCE_DIR}/include PUBLIC)

add_subdirectory(${CMAKE_SOURCE_DIR}/lru2q)
add_subdirectory(${CMAKE_SOURCE_DIR}/idcache) 