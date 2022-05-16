cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(inverse-pendulum)

find_package(OpenGL REQUIRED)

if (MSVC)
    # Enable exceptions for clang-cl
    add_compile_options(/EHsc)
endif ()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Including fetched dependencies
enable_testing()
add_subdirectory(dependencies)
add_subdirectory(src)
add_subdirectory(tests)

# Including GLFW and GLAD
add_subdirectory(glfw)
include_directories(glfw/include)
include_directories(glad/include)

set(SOURCE_FILES glad/src/glad.c src/InversePendulum.cpp src/InversePendulum.h )
add_library(SourcesLib ${SOURCE_FILES})
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} Catch2 ApprovalTests fmt filesystem)
target_link_libraries(${CMAKE_PROJECT_NAME} glfw ${GLFW_LIBRARIES} ${OPENGL_LIBRARY})

