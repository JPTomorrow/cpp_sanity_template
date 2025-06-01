//
// Created by justi on 6/1/2025.
//

#ifndef PRINT_H
#define PRINT_H

#include <iostream>

namespace UTILS {
        inline void print_os() {
            std::cout << "Current OS: ";
        #ifdef WIN32
            std::cout << "Windows\n";
        #elif LINUX
            std::cout << "Linux\n";
        #elif MACOS
            std::cout << "Mac\n";
        #else
            std::cout << "UNDEFINED\n",
        #endif
    }
}


#endif //PRINT_H
