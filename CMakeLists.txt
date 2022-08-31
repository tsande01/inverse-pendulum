cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(inverse-pendulum)

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

set(SOURCE_FILES main.cpp src/InversePendulum.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} Catch2 ApprovalTests fmt )
target_link_libraries(${CMAKE_PROJECT_NAME} sfml-graphics sfml-window sfml-system )
