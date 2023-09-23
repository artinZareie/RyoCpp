cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(Ryo VERSION 0.0.1 LANGUAGES CXX)

# TODO: somehow make include files available trough #include <>

# Add GoogleTest to this project.
enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB SOURCES "src/*.cpp" "headers/*.hpp")
file(GLOB TEST_SOURCES "tests/*.cc")

option(RYO_WITH_TERMINAL "Enable the Terminal sub-library" ON)
option(RYO_WITH_WEB "Enable the Web sub-library" OFF)
option(RYO_WITH_GUI "Enable the GUI sub-library" OFF)

if(UNIX)

    file(GLOB BASE_HEADERS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers/*.hpp")
    set(TERMINAL_HEADERS_DEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/ryo)
    file(COPY ${TERMINAL_HEADERS_SOURCE_DIR} DESTINATION ${TERMINAL_HEADERS_DEST_DIR})

    add_library(Ryo SHARED ${SOURCES})
    add_executable(RyoTests ${TEST_SOURCES} ${SOURCES})

    target_include_directories(RyoTests PRIVATE "${PROJECT_SOURCE_DIR}/src")
    target_link_libraries(RyoTests GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(RyoTests)

    install(DIRECTORY include/ DESTINATION include/ryo)
endif(UNIX)

if(RYO_WITH_TERMINAL)
    add_subdirectory(terminal)
    target_link_libraries(Ryo RyoTerminal)
    file(GLOB TERMINAL_HEADERS_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/terminal/headers/*.hpp")
    set(TERMINAL_HEADERS_DEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/ryo/terminal)
    file(COPY ${TERMINAL_HEADERS_SOURCE_DIR} DESTINATION ${TERMINAL_HEADERS_DEST_DIR})
endif()

if(RYO_WITH_WEB)
    add_subdirectory(web)
    target_link_libraries(Ryo web)
endif()

if(RYO_WITH_GUI)
    add_subdirectory(gui)
    target_link_libraries(Ryo gui)
endif()
