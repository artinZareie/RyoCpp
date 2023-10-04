project(RyoTerminal LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB SOURCES "resources/*.cpp" "headers/*.hpp" "templates/*.tpp")
file(GLOB HEADER_FILES "headers/*.hpp")

add_library(RyoUtilsStatic STATIC ${SOURCES})
add_library(RyoUtils SHARED ${SOURCES})
target_include_directories(RyoUtilsStatic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")
target_include_directories(RyoUtils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")

file(GLOB TEST_SOURCES "tests/*.cc")

if(UNIX)
    target_link_libraries(Ryo RyoUtils)
    add_executable(RyoUtilsTests ${TEST_SOURCES} ${SOURCES})
    target_include_directories(RyoUtilsTests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/headers")
    target_link_libraries(RyoUtilsTests GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(RyoUtilsTests)
    set_target_properties(RyoUtilsStatic PROPERTIES LINKER_LANGUAGE CXX)
    set_target_properties(RyoUtils PROPERTIES LINKER_LANGUAGE CXX)
endif()