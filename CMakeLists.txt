cmake_minimum_required(VERSION 3.15)
project(WindowsTcpDlp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4 /permissive-)
endif()

add_executable(day01_raii src/main.cpp)
target_link_libraries(day01_raii PRIVATE ws2_32)
