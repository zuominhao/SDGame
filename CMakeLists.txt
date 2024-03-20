cmake_minimum_required(VERSION 3.15)

project(MyProject)

file(GLOB SOURCES "src/*.cpp" "src/*.hpp")
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)


add_executable(MyExecutable ${SOURCES})
target_link_libraries(MyExecutable PRIVATE sfml-system sfml-network sfml-graphics sfml-window)