#ifndef CALCU_H
#define CALCU_H

#include <iostream>

template<typename T>
void Print(T value) {
    std::cout << value << std::endl;
}

template<typename T>
void Scan(T variable) {
    std::cin << variable;
}

template<typename T>
T suma(T num1, T num2) {
    T resultado = static_cast<int>(std::cout << "Resultado de la suma: " << num1 + num2);

    return resultado;
}

template<typename T>
T resta(T num1, T num2) {
    T resultado = std::cout << "Resultado de la resta: " << num1 - num2;

    return resultado;
}

template<typename T>
T division(T num1, T num2) {
    T resultado = std::cout << "Resultado de la division: " << num1 / num2;

    return resultado;
}

template<typename T>
T multiplicar(T num1, T num2) {
    T resultado = std::cout << "Resultado de la multiplicacion: " << num1 * num2;

    return resultado;
}

#endif //CALCU_H