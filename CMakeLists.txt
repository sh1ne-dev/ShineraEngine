
if(WIN32)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "VCPKG toolchain file")
    set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "VCPKG Triplet")
    set(VCPKG_FEATURE_FLAGS manifest-mode)
endif()

cmake_minimum_required(VERSION 3.29)
project(Shinera)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_TESTS ON)

set(LIBS glfw GLEW::GLEW glm::glm nlohmann_json::nlohmann_json OpenGL::GL)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

if(WIN32)
    find_package(Stb REQUIRED)
else()
    include_directories(/usr/include/stb)
endif()

file(GLOB_RECURSE SOURCES_ENGINE src/*.cpp)

include_directories(include)

add_library(${PROJECT_NAME} SHARED ${SOURCES_ENGINE})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})

target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})

# Tests

if(BUILD_TESTS)

    find_package(Catch2 3 REQUIRED)

    file(GLOB_RECURSE SOURCES_TESTS tests/src/*.cpp)

    add_executable(tests ${SOURCES_TESTS})

    target_link_libraries(tests PRIVATE ${PROJECT_NAME} Catch2::Catch2)

    target_include_directories(tests PRIVATE tests/include)

    add_custom_command(TARGET tests POST_BUILD
            COMMAND echo Updating game resources...
            COMMAND ${CMAKE_COMMAND} -E remove_directory
            ${CMAKE_CURRENT_BINARY_DIR}/res
            COMMAND echo Old resources are deleted!
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/res
            ${CMAKE_CURRENT_BINARY_DIR}/res
            COMMAND echo New resources are copied!
    )

endif()