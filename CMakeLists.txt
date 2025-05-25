cmake_minimum_required(VERSION 4.0.2)

# title and exe name variables
set(ProjectTitle CppTemplate) # change this name for new project
set(ExeName cpp_template) # change this name for new project
project(${ProjectTitle} VERSION 1.0.0)
# message(${ProjectTitle})
# message(${ExeName})

# ensures that dlls get copied to the output directory correctly
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_executable(${ExeName} src/main.cpp)

include(FetchContent)
# example of how to include a library directly from git
# it will be pulled and compiled into a lib by cmake
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main # or a specific tag/branch/commit
)
FetchContent_MakeAvailable(SDL3)

target_link_libraries(${ExeName} PRIVATE SDL3::SDL3)

# add and include all libraries in src folder
file(GLOB_RECURSE ALL_SOURCES 
    "src/*.cpp"
    "src/*.c"
    "src/*.h" 
    "src/*.hpp"
)
target_sources(${ExeName} PRIVATE ${ALL_SOURCES})
target_include_directories(${ExeName} PRIVATE src/)
