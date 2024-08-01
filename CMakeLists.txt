cmake_minimum_required(VERSION 3.30)
project(titato)

set(CMAKE_CXX_STANDARD 23)

link_libraries(SDL2)

add_executable(titato src/main.cpp
#        src/board.hpp
#        src/board.cpp
#        src/player.hpp
#        src/player.cpp
        src/game.cpp
        src/game.hpp
        src/player.cpp
        src/player.hpp
)
