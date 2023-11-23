#include <iostream>

void ModifyValue(int * PTR) {
    *PTR = 2;
}


int main() {
    int a = 5;

    ModifyValue(&a);

    std::cout << a;
}