#include <iostream>
#include <string>

//Crear la estructura
struct CREDS {
    std::string user;
    std::string pass;
};

int main() {
    
    struct CREDS login;
    
    //Almacenar valores
    login.user = "rapha";
    login.pass = "pass1234";
    
    //Pedir usuario
    
    std::cout << "Ingresa tu usuario..." << std::endl;
    
    std::string inputus;
    
    std::cin >> inputus;
    
    while(inputus != login.user) {
        std::cout << "Usuario no reconocido, intenta de nuevo." << std::endl;
        
        std::cin >> inputus;
    }
    
    if(inputus == login.user) {
        std::cout << "Usuario valido, porfavor ingresa tu clave..." << std::endl;
        
        std::string inputpass;
        
        std::cin >> inputpass;
        
        while(inputpass != login.pass) {
            std::cout << "Clave no valida, intenta de nuevo." << std::endl;
            
            std::cin >> inputpass;
        }
        
        if(inputpass == login.pass) {
            std::cout << "Clave valida, bienvenido." << std::endl;
        }
    }

}