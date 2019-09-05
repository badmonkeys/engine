cmake_minimum_required(VERSION 3.14)

project(evo)

add_definitions(
  # We're explicitly using C++17
  -std=c++17

  # Warn all the things!
  -Wall
  -Wextra
)

add_subdirectory(engine)

add_executable(evo app.cpp)
target_link_libraries(evo evoengine)
