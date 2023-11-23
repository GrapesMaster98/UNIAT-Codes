#include <iostream>

int main() {
    int Arreglo[] = {2, 1, 5, 29, 0};
    int * PTR = Arreglo;

    for(int i = 0; i < 5; i++) {
        std::cout << * PTR;
        PTR++;
    }
}