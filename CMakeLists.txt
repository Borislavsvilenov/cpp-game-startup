cmake_minimum_required(VERSION 3.27)
project(Engine VERSION 0.1.0 LANGUAGES C CXX)

find_package(raylib REQUIRED)

include_directories(Engine PRIVATE engine Objects)

include(CTest)
enable_testing()

add_executable(Engine main.cpp 
               engine/Game.hpp 
               engine/Game.cpp 
               engine/Game.hpp 
               engine/Player.hpp 
               engine/Player.cpp 
               engine/Collider.cpp 
               engine/Collider.hpp
               engine/Empty.cpp
               engine/Empty.hpp
               )
target_link_libraries(Engine PRIVATE raylib)
target_compile_features(Engine PRIVATE cxx_std_11)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
