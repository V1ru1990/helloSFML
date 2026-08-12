cmake_minimum_required(VERSION 3.10.0)
project(helloSFML VERSION 0.1.0 LANGUAGES C CXX)

add_executable(helloSFML
    src/main.cpp
    src/Platform.cpp
    include/Engine/Platform.h
    include/Engine/World.h)

target_include_directories(helloSFML PRIVATE include)

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)
target_link_libraries(helloSFML sfml-graphics sfml-window sfml-system)

include(CTest)
enable_testing()

add_custom_command(
    TARGET helloSFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/images
        ${CMAKE_CURRENT_BINARY_DIR}/images
)