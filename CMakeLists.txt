cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(Ryo VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)

# Add GoogleTest to this project.
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB SOURCES "src/*.cpp" "include/*.hpp")
file(GLOB TEST_SOURCES "tests/*.cc")

option(RYO_WITH_TERMINAL "Enable the Terminal sub-library" ON)
option(RYO_WITH_WEB "Enable the Web sub-library" OFF)
option(RYO_WITH_GUI "Enable the GUI sub-library" OFF)

if(UNIX)
    add_library(Ryo SHARED ${SOURCES})
    add_executable(RyoTests ${TEST_SOURCES} ${SOURCES})

    target_include_directories(RyoTests PRIVATE "${PROJECT_SOURCE_DIR}/src")
    target_link_libraries(RyoTests GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(RyoTests)
endif(UNIX)

if(RYO_WITH_TERMINAL)
    add_subdirectory(terminal)
    target_link_libraries(Ryo RyoTerminal)
endif()

if(RYO_WITH_WEB)
    add_subdirectory(web)
    target_link_libraries(Ryo web)
    endif()

if(RYO_WITH_GUI)
    add_subdirectory(gui)
    target_link_libraries(Ryo gui)
    endif()
