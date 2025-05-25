# C++ Sanity Template

A good template for starting out with C++ with a build system that doesn't make you sad :)

## Requirments
- CMake
- Ninja Build System
- A good c++ compiler for your prefered OS (I use MSVC/Clang most of the time, but anything will do as long as cmake can find it)

### Works best with VSCode with the following extensions
- CMake Highlight
- CMake Tools
- C/C++ (Microsoft)
- C/C++ Extension Pack (Microsoft)

## Building (WIP)

### With VSCode
- Have the cmake extension build the project files in the /bin directory
- Run the "cmake build debug" task to generate the binaries from the project files
- If you hit F5, it will rebuild the binnaries with the "cmake build debug" and then launch the vscode debugger for easy debug env.

### With just CMake
This "should" generate the same file structure in bin/ as the vscode extension.
``` bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE --no-warn-unused-cli -SC:/<PATH_TO_PROJECT>/template_cpp -Bc:/<PATH_TO_PROJECT>/template_cpp/bin
``` 

## TODO
- add testing libraries and frameworks
- abstract away an SDL engine for fun that can be removed by the user?