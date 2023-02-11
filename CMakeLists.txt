cmake_minimum_required (VERSION 3.5)
project(udacity_pid_controller)

add_definitions(-std=c++11)

add_compile_options(-Wall -Wextra -pedantic -Werror)

set(sources src/PID.cpp src/main.cpp)

include_directories(
  include
  /usr/include
)

add_executable(pid_controller
  src/main.cpp
  src/pid_controller.cpp
)

target_link_libraries(pid_controller z ssl uv uWS)
