cmake_minimum_required(VERSION 3.5.0)

set(PROJ_NAME openal-vorbis-test)

project(${PROJ_NAME} VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenAL REQUIRED)

add_executable(${PROJ_NAME}
    src/main.cpp
    src/stb_vorbis.c
    src/audiomanager.h
    src/audiomanager.cpp
    src/audio.h
    src/audio.cpp
)

target_link_libraries(${PROJ_NAME} openal)
