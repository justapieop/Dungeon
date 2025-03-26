# Dungeon
Game submission for 2425II_INT2215_6 class.

Author: Đỗ Trần Thái An (24021349)

# References

Most of the codebase is referenced from [Let's Make Games](https://www.youtube.com/@CarlBirch). Especially the entity component system (`ECS, ComponentManager, Entity`)

# Get started

First you will have to install GCC and CMake for your system to start building this project. For this project, it is recommended to use MinGW on Windows.

After cloning this repository, run `git submodule update --init --recursive` to download the dependencies.

## On CLion

Open the project and right click on `CMakeLists.txt` and click `Load CMake Project`. The IDE will automatically configure the project and generate config for your development environment.

Build the project by clicking the `Build` icon on the configuration bar for the first time for the dependencies to generate header files.

Create a Release CMake profile if you want to build the game in `Release` mode using the menu beside the configuration list.

## On other IDEs

**Note**: Replace `Debug` with `Release` if you need to build in `Release` mode

Configure the project using `cmake -DCMAKE_BUILD_TYPE=Debug -S . -B ./cmake-build-debug`

Build the project using `cmake --build ./cmake-build-debug --target Dungeon -j 14`
