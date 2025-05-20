add_library(GameObjects
                Constants.h
                PlayerSea.cpp PlayerSea_output.cpp PlayerSea.h
                Ship.cpp Ship.h
                Missile.cpp Missile.h
                TumblingMissile.cpp TumblingMissile.h
                Output.h)

target_include_directories(GameObjects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(GameObjects Sea)
