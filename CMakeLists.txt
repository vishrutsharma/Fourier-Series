cmake_minimum_required(VERSION 3.16)

project(fourier_series LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    src/main.cpp
    src/Application.cpp
    src/Window.cpp
    src/Graph.cpp
)

target_include_directories(main PRIVATE
    include
    "C:/Vishrut/Paths/SDL2/include"
)

target_compile_definitions(main PRIVATE
    SDL_MAIN_HANDLED
)

target_link_directories(main PRIVATE
    "C:/Vishrut/Paths/SDL2/lib"
)

target_link_libraries(main PRIVATE
    SDL2
)