cmake_minimum_required(VERSION 3.17)
project(SatelliteSimulator)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES src/main.cpp src/Game.cpp libs/glad/src/gl.c src/utils/ShaderProgram.cpp)
set(HEADER_FILES src/Game.h src/utils/ShaderProgram.h)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir}/build)

#dep
include_directories(libs/glad/include)

file(COPY resources DESTINATION ${dir}/build)
file(COPY shaders DESTINATION ${dir}/build)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(libs/glfw-3.3.4)

add_executable(SatelliteSimulator ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(SatelliteSimulator glfw)