cmake_minimum_required(VERSION 3.12)

# title and exe name variables
set(ProjectTitle CppTemplate) # change this name for new project
set(ExeName cpp_template) # change this name for new project
# message(${ProjectTitle})
# message(${ExeName})

project(${ProjectTitle} VERSION 1.0.0)

add_executable(${ExeName} src/main.cpp)

include(FetchContent)
# set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/vendor")

# example of how to include a library directly from git
# it will be pulled and compiled into a lib by cmake
# your IDE will need to point at the include dir
FetchContent_Declare(
  SDL3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG main # or a specific tag/branch/commit
)
FetchContent_MakeAvailable(SDL3)

target_link_libraries(${ExeName} PRIVATE SDL3::SDL3)

# example of adding and including a library in the
# source directory. I am keeping everything in
# relevant sub folders inside of src
file(GLOB TEST_SOURCES "src/test/*.cpp")
file(GLOB TEST_HEADERS "src/test/*.h")
target_sources(${ExeName} PRIVATE
    ${TEST_SOURCES}
    ${TEST_HEADERS}
)
target_include_directories(${ExeName} PRIVATE
    src/test
)
