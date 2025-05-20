add_library(Sea Coordinates.cpp Coordinates.h Object.cpp Object.h)

target_include_directories(Sea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
