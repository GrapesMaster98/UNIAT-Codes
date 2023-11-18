#include <iostream>
#include <string>

class Animal {
public:
    Animal(std::string nombre, std::string tipo) : nombre(nombre), tipo(tipo) {
    }

    void nameAnimal() {
        std::cout << "El " << nombre << " es un " << tipo << std::endl;
    }

private:
    std::string nombre;
    std::string tipo;

    friend class Cuadrupedo;
};

class Cuadrupedo : public Animal {
public:
    Cuadrupedo(std::string nombre, std::string tipo, std::string dieta): Animal(nombre, tipo){

        this -> dieta=dieta;
    }

    void mostrarInfo() {
        std::cout << "El " << nombre << " es un " << tipo << " y su dieta es " << dieta << std::endl;
    }

private:
    std::string dieta;
};

int main() {
    Animal lobo("Lobo", "Mamífero");
    lobo.nameAnimal();

    Cuadrupedo tigre("Tigre", "Mamífero", "Carnívora");
    tigre.mostrarInfo();
    
    
    return 0;
}