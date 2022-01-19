cmake_minimum_required(VERSION 3.20)
project(lab7)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab7 main.cpp student.cpp student.h StudentAfter1session.cpp StudentAfter1session.h StudentAfter2session.cpp StudentAfter2session.h tests.cpp)
target_link_libraries(lab7 gtest_main)