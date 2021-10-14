project(GoogleTests)

add_subdirectory(lib/googletest)

link_directories(C:/Users/arina/CLionProjects/Sorts/GoogleTests/lib)

add_executable(GoogleTests_run Tests.cpp)

target_link_libraries(GoogleTests_run gtest gtest_main)