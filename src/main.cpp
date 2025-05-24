#include <iostream>
#include <SDL3/SDL.h>

#include "test.h"

using namespace std;

int main()
{
    cout << test_add(1, 2) << endl;
    cout << "hello, world! SDL VERSION: " << SDL_VERSION << endl;
    return 0;
}