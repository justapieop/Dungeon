cmake_minimum_required(VERSION 3.30)
project(Dungeon)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(SDL2MIXER_VENDORED ON CACHE BOOL "" FORCE)
set(SDL2MIXER_OPUS ON CACHE BOOL "" FORCE)
set(SDL2TTF_VENDORED ON CACHE BOOL "" FORCE)

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_ttf EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_image EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_mixer EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/Game.cpp
        include/Game.hpp
        src/Utils.cpp
        include/Utils.hpp
        src/TextureManager.cpp
        include/TextureManager.hpp
)

if (CMAKE_BUILD_TYPE MATCHES Release)
    if (MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
    else()
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
endif ()

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image SDL2_mixer::SDL2_mixer SDL2_ttf::SDL2_ttf SDL2::SDL2main SDL2::SDL2)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory assets "${CMAKE_BINARY_DIR}/$<CONFIGURATION>/assets"
)