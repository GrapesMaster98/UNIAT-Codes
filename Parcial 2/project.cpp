#include <iostream>
#include <string>
#include <sstream>

// Función para convertir un número decimal a binario
std::string decimalToBinary(int decimal) {
    if (decimal == 0) {
        return "0";
    }
    std::string binary = "";
    while (decimal > 0) {
        binary = std::to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Función para convertir un número binario a decimal
int binaryToDecimal(std::string binary) {
    int decimal = 0;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

// Función para convertir un número decimal a hexadecimal
std::string decimalToHexadecimal(int decimal) {
    std::stringstream ss;
    ss << std::hex << decimal;
    return ss.str();
}

// Función para convertir un número hexadecimal a decimal
int hexadecimalToDecimal(std::string hexadecimal) {
    int decimal;
    std::stringstream ss;
    ss << std::hex << hexadecimal;
    ss >> decimal;
    return decimal;
}

int main() {
    int decimal;
    std::string binary, hexadecimal;

    std::cout << "Ingrese un número decimal: ";
    std::cin >> decimal;

    binary = decimalToBinary(decimal);
    hexadecimal = decimalToHexadecimal(decimal);

    std::cout << "Decimal a Binario: " << binary << std::endl;
    std::cout << "Decimal a Hexadecimal: " << hexadecimal << std::endl;

    std::cout << "Ingrese un número binario: ";
    std::cin >> binary;

    decimal = binaryToDecimal(binary);

    std::cout << "Binario a Decimal: " << decimal << std::endl;

    std::cout << "Ingrese un número hexadecimal: ";
    std::cin >> hexadecimal;

    decimal = hexadecimalToDecimal(hexadecimal);

    std::cout << "Hexadecimal a Decimal: " << decimal << std::endl;

    return 0;
}