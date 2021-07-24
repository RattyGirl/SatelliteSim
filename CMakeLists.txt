cmake_minimum_required(VERSION 3.3)
project(SatelliteSim)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Including GLFW
add_subdirectory(glfw)
include_directories(glfw/include)

# Including GLAD
include_directories(glad/include)

#add glm
add_subdirectory(glm)
include_directories(glm)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/gfx/*.cpp glad/src/glad.c)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

# Linking GLFW and OGL
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY} glm::glm)
file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${PROJECT_BUILD_DIR}/)