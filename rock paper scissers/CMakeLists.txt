cmake_minimum_required(VERSION 3.22)

project (ROCK_PAPER_SCISSOR CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(rock_paper_scissor 

"src/main.cxx"
"src/random_select_player_move.cxx" 
"src/rock_paper_scissor.cxx"
)


target_include_directories(rock_paper_scissor PRIVATE ${CMAKE_SOURCE_DIR}/hpp/)