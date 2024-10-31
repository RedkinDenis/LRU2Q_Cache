# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

cmake_minimum_required(VERSION 3.10)
project(idCache)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR1 ${CMAKE_SOURCE_DIR}/include)

set(INCLUDE_DIR2 ${CMAKE_SOURCE_DIR}/../include)

find_package(GTest REQUIRED)

SET(SRCS1
    src/ideal_cache.cpp
)

add_library(idCache STATIC ${SRCS1})

target_include_directories(idCache PUBLIC ${INCLUDE_DIR1})
target_include_directories(idCache PUBLIC ${INCLUDE_DIR2})

add_executable(idCache.x mainId.cpp)        

target_link_libraries(idCache.x idCache)



add_library(test STATIC ${SRCS1})

target_include_directories(test PUBLIC ${INCLUDE_DIR1})
target_include_directories(test PUBLIC ${INCLUDE_DIR2})
target_include_directories(test PUBLIC ${GTEST_INCLUDE_DIRS})

add_executable(idCache.test mainId.cpp)

target_link_libraries(idCache.test test)
target_link_libraries(idCache.test ${GTEST_LIBRARIES} pthread)

target_compile_definitions(idCache.test PRIVATE TESTING)