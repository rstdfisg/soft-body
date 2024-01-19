cmake_minimum_required(VERSION 3.19)
project(cpp VERSION 1.0)

set(PROJECT_NAME soft-body)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(PINE_SRC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SFML_STATIC_LIBRARIES true)
set(SFML_USE_STATIC_STD_LIBS true)
set(SFML_HEADER_DIR "C:/SFML-2.5.1/include")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g -ggdb" )
set(CMAKE_CXX_FLAGS_RELEASE "-mwindows -O2 -static -static-libgcc -static-libstdc++")

project(${PROJECT_NAME})

set(${PROJECT_NAME}_VERSION_MAJOR 1)
set(${PROJECT_NAME}_VERSION_MINOR 0)

find_package(SFML 2.5.1 REQUIRED COMPONENTS audio graphics window system REQUIRED)

include_directories(${PINE_SRC_INCLUDE_DIR} ${SFML_HEADER_DIR})

file( GLOB LIB_SOURCES src/*.cpp )
file( GLOB LIB_HEADERS include/*.hpp )

add_executable(${PROJECT_NAME} ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(
    ${PROJECT_NAME} 
    sfml-graphics
    sfml-window
    sfml-system
)