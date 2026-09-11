cmake_minimum_required(VERSION 3.10)
project(MemorySpace3D)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/MemorySpace3D.cpp
)

# Create executable
add_executable(memory-space-3d ${SOURCES})

# Link libraries
target_link_libraries(memory-space-3d 
    OpenGL::OpenGL
    glfw
    glm::glm
)

# Compiler flags
if(UNIX AND NOT APPLE)
    target_compile_options(memory-space-3d PRIVATE -Wall -Wextra -O2)
endif()
