#include <iostream>
#include "calcu.h"

int main()
{

    int a, b;

    Print("Ingresa el primer numero: ");
    std::cin >> a;
    Print("Ingresa el segundo numero: ");
    std::cin >> b;
    int res = suma<int>(a, b);

    return 0;
}
