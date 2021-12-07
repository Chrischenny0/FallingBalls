cmake_minimum_required(VERSION 3.20)
project(FallingBalls)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES      main.cpp
        SDL_Plotter.h SDL_Plotter.cpp
        Ball.h        Ball.cpp
        Coordinate.h  Coordinate.cpp
        BMPImage.h    BMPImage.cpp
        SDLWrapper.h  SDLWrapper.cpp
        Force.h Force.cpp
        Brick.h Brick.cpp Font.cpp Font.h)
add_executable(FallingBalls ${SOURCE_FILES})

target_link_libraries(FallingBalls mingw32 SDL2main SDL2 SDL2_mixer)