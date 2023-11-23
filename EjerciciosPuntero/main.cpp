#include <iostream>

int main() {

    int EnteroNormal = 10;
    int * EnteroPuntero = &EnteroNormal; // -> Los punteros llevan un * al inicio para reconocerlo.

    *EnteroPuntero = 24;

    std::cout << EnteroNormal;

    return 0;

}