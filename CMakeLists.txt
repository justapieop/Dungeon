cmake_minimum_required(VERSION 3.25)
project(Dungeon)

set(CMAKE_CXX_STANDARD 26)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(SDL2MIXER_VENDORED ON CACHE BOOL "" FORCE)
set(SDL2MIXER_OPUS ON CACHE BOOL "" FORCE)
set(SDL2TTF_VENDORED ON CACHE BOOL "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_ttf EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_image EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_mixer EXCLUDE_FROM_ALL)

add_executable(
        ${PROJECT_NAME}
        src/main.cpp
        src/Game.cpp
        include/Game.hpp
        src/Utils.cpp
        include/Utils.hpp
        src/TextureManager.cpp
        include/TextureManager.hpp
        include/Map.hpp
        src/Map.cpp
        include/Vec2D.hpp
        src/Vec2D.cpp
        include/ECS.hpp
        include/SpriteComponent.hpp
        src/SpriteComponent.cpp
        include/TransformComponent.hpp
        src/TransformComponent.cpp
        include/Constants.hpp
        include/CollisionComponent.hpp
        src/CollisionComponent.cpp
        include/InputHandler.hpp
        src/InputHandler.cpp
        include/InventoryComponent.hpp
        src/InventoryComponent.cpp
)

if (CMAKE_BUILD_TYPE MATCHES Release)
    if (WIN32)
        if (MSVC)
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
        else()
            set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
        endif()
    endif ()
endif ()

target_include_directories(
        ${PROJECT_NAME} PRIVATE
        include
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        SDL2_ttf::SDL2_ttf
        SDL2::SDL2main
        SDL2::SDL2
)

target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        SDL2_ttf::SDL2_ttf
        SDL2::SDL2main
        SDL2::SDL2
)

add_custom_target(copy_assets
        COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=$<CONFIGURATION> -P ${CMAKE_CURRENT_LIST_DIR}/copy-assets.cmake
)
add_dependencies(${PROJECT_NAME} copy_assets)
