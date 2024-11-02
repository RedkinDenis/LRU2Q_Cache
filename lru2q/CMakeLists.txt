# cmake -DCMAKE_BUILD_TYPE=Release -S . -B build

cmake_minimum_required(VERSION 3.10)
project(lru2q)

set(CMAKE_CXX_STANDARD 17)

set(INCLUDE_DIR1 ${CMAKE_SOURCE_DIR}/include)

set(INCLUDE_DIR2 ${CMAKE_SOURCE_DIR}/../include)

find_package(GTest REQUIRED)

SET(SRCS1
    src/LRU2Q.cpp
)

add_library(lru2Q STATIC ${SRCS1})

target_include_directories(lru2Q PUBLIC ${INCLUDE_DIR1})
target_include_directories(lru2Q PUBLIC ${INCLUDE_DIR2})

add_executable(lru2q.x main2Q.cpp)        

target_link_libraries(lru2q.x lru2Q)



add_library(test STATIC ${SRCS1})

target_include_directories(test PUBLIC ${INCLUDE_DIR1})
target_include_directories(test PUBLIC ${INCLUDE_DIR2})
target_include_directories(test PUBLIC ${GTEST_INCLUDE_DIRS})

add_executable(lru2q.test main2Q.cpp)

target_link_libraries(lru2q.test test)
target_link_libraries(lru2q.test ${GTEST_LIBRARIES} pthread)

target_compile_definitions(lru2q.test PRIVATE TESTING)