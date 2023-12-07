project(RyoTerminal LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB SOURCES "resources/*.cpp" "headers/*.hpp")
file(GLOB HEADER_FILES "headers/*.hpp")

add_library(RyoTerminalStatic STATIC ${SOURCES})
add_library(RyoTerminal SHARED ${SOURCES})
target_include_directories(RyoTerminalStatic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")
target_include_directories(RyoTerminal PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")

file(GLOB TEST_SOURCES "tests/*.cc")

if(UNIX)
    target_link_libraries(Ryo RyoTerminal)
    add_executable(RyoTerminalTests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(RyoTerminalTests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/headers")
    target_link_libraries(RyoTerminalTests GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(RyoTerminalTests)
    set_target_properties(RyoTerminalStatic PROPERTIES LINKER_LANGUAGE CXX)
    set_target_properties(RyoTerminal PROPERTIES LINKER_LANGUAGE CXX)
endif()