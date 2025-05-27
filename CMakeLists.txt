cmake_minimum_required(VERSION 3.3)

# title and binary variables
set(ProjectTitle CppTemplate) # change this name for new project
set(BinaryName cpp_template) # change this name for new project
project(${ProjectTitle} VERSION 1.0.0)
# message(${ProjectTitle})
# message(${BinaryName})

# ensures that dlls get copied to the output directory correctly
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# set c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${BinaryName} src/main.cpp)

include(FetchContent)
#Gtest testing framework
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# example of how to include a library directly from git
# it will be pulled and compiled into a lib by cmake
#FetchContent_Declare(
#  SDL3
#  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#  GIT_TAG main # or a specific tag/branch/commit
#)
#FetchContent_MakeAvailable(SDL3)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG docking # or a specific tag/branch/commit
)
FetchContent_MakeAvailable(IMGUI)
# Create ImGui as an interface library
# THIS NEEDS TO BE DONE FOR FETCHES THAT ARE NOT COMPILED
# BECAUSE THEY HAVE NO CMakeLists.txt OF THEIR OWN
# DEFINING HOW THEY SHOULD BE BUILT
add_library(imgui STATIC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})
target_link_libraries(${BinaryName} PRIVATE imgui)
target_include_directories(${BinaryName} PRIVATE ${imgui_SOURCE_DIR})

# linking for main binary
set( # ADD YOUR LIBS TO THIS VARIABLE TO BE LINKED
  LinkLibs 
#  SDL3::SDL3
)
target_link_libraries(${BinaryName} PRIVATE ${LinkLibs})

# add and include all libraries in src folder
file(GLOB_RECURSE ALL_SOURCES 
    "src/*.cpp"
    "src/*.c"
    "src/*.h" 
    "src/*.hpp"
)
list(FILTER ALL_SOURCES EXCLUDE REGEX ".*test.*")
target_sources(${BinaryName} PRIVATE ${ALL_SOURCES})
target_include_directories(${BinaryName} PRIVATE src/)

#
# GTest testing
#
enable_testing()
file(GLOB_RECURSE TEST_SOURCES 
    "src/*test*.cpp"
    "src/*test*.cc"
)
set(PROGRAM_SOURCE_FOR_TEST ${ALL_SOURCES})
list(FILTER PROGRAM_SOURCE_FOR_TEST EXCLUDE REGEX ".*main.cpp.*")
add_executable(program_tests ${TEST_SOURCES} ${PROGRAM_SOURCE_FOR_TEST})

# Link GTest libraries and include directories
target_link_libraries(program_tests PRIVATE 
    GTest::gtest_main 
    GTest::gtest
    ${LinkLibs} # we link all the libs from our main binary as well
)
target_include_directories(program_tests PRIVATE src/)
set_target_properties(program_tests PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
include(GoogleTest)
gtest_discover_tests(program_tests)