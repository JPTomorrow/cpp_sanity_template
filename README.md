# C++ Sanity Template

A good template for starting out with C++ with a build system that doesn't make you sad :)

## Requirements
- CMake
- Ninja Build System
- A good c++ compiler for your preferred OS (I use MSVC/Clang most of the time, but anything will do as long as cmake can find it)

### Works best with VSCode with the following extensions
- CMake Highlight
- CMake Tools
- C/C++ (Microsoft)
- C/C++ Extension Pack (Microsoft)

## Building (WIP)

### With VSCode

- Have the cmake extension build the project files in the /bin directory
- Run the "cmake build debug" task to generate the binaries from the project files
- If you hit F5, it will rebuild the binaries with the "cmake build debug" and then launch the vscode debugger for easy debug env.

### With CMake (IDE agnostic)

This "should" generate the same file structure in bin/ as the vscode extension.
``` bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE --no-warn-unused-cli -SC:/<PATH_TO_PROJECT>/template_cpp -Bc:/<PATH_TO_PROJECT>/template_cpp/bin
``` 
## Testing (WIP)

The project uses Google Testing library (GTest) right now. Perhaps more will be added in the future. It builds a test binary with cmake that
outputs to the same directory in bin/ as the main executable.

- Unit tests can be run after a cmake build using the ```ctest``` command

