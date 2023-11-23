#include <iostream>
#include <string>

int main() {
    const char* message = "hello world";

    for(int i = 0; i < 11; i++) {
        std::cout << *message;
        message++;
    }

    return 0;
}