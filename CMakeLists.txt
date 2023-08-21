cmake_minimum_required(VERSION 3.19)
project(cpp VERSION 1.0)

set(PROJECT_NAME soft-body)
set(PINE_SRC_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(PINE_SRC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb" )
# set(CMAKE_CXX_FLAGS_RELEASE "-O2" )
set(CMAKE_CXX_FLAGS_RELEASE "-mwindows -O3" )

project(${PROJECT_NAME})

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

include_directories(${PINE_SRC_INCLUDE_DIR})

file( GLOB LIB_SOURCES src/*.cpp )
file( GLOB LIB_HEADERS ${PINE_SRC_INCLUDE_DIR}/*.hpp )

add_executable(${PROJECT_NAME} ${LIB_SOURCES} ${LIB_HEADERS})

# add_library(test src/test.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
)