cmake_minimum_required(VERSION 3.25)
project(Proj6)

set(CMAKE_CXX_STANDARD 23)

add_executable(Proj6 deck.h player.h go_fish.cpp deck.cpp card.cpp player.cpp)
