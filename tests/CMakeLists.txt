
add_executable(tests main.cpp InversePendulumTest.cpp)
target_link_libraries(tests SourcesLib Catch2::Catch2 ApprovalTests fmt)
