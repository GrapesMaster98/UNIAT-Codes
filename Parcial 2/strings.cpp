#include <iostream>
#include <string>

int main()
{
    //Definir contraseña
    std::string pass = "pass1234";
    
    //Pedir dato
    std::cout << "Ingresa tu clave..." << std::endl;
    
    std::string inputpass;
    
    std::cin >> inputpass;
    
    //Verificar si la contraseña es igual a la declarada, si es incorrecta, preguntar nuevamente.
    
    while(inputpass != pass) {
        std::cout << "Clave invalida, intenta de nuevo" << std::endl;
        std::cin >> inputpass;
    }
    
    if(inputpass.size() < 8) {
        std::cout << "Tu clave es muy corta..." << std::endl;
    }
    
    //Si la clave es correcta, el usuario "ingresa".
    if(inputpass == pass) {
        std::cout << "Clave valida." << std::endl;
    }

    return 0;
}