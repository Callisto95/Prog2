add_executable(battleship main.cpp init.cpp init.h game.cpp game.h utils.cpp utils.h)

target_link_libraries(battleship GameObjects Sea)
