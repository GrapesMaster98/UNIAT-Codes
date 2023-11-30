#include <iostream>
#include <string>

#ifndef UNIAT_CODES_LIBRERIA_H
#define UNIAT_CODES_LIBRERIA_H

class Poliza {
public:
    std::string nombre;
    int edad;
    int nacimiento;
    std::string curp;
    int maximo;
    int deducible;

    int CalcAge(int currentYear, int bornYear) {
        int res = currentYear - bornYear;

        return res;
    }

    void StartQuestionare() {
        std::string name;
        int fechaNac;
        std::string CURP;
        int max;
        int ded;

        std::cout << "Porfavor ingresa el nombre del usuario: " << std::endl;
        std::cin >> name;

        std::cout << "Porfavor ingresa el anio de nacimiento: " << std::endl;
        std::cin >> fechaNac;

        std::cout << "Porfavor ingresa el CURP del usuario: " << std::endl;
        std::cin >> CURP;

        std::cout << "Porfavor ingresa el maximo de poliza del usuario: " << std::endl;
        std::cin >> max;

        std::cout << "Porfavor ingresa el deducible del usuario: " << std::endl;
        std::cin >> ded;

        nombre = name;
        nacimiento = fechaNac;
        curp = CURP;
        maximo = max;
        deducible = ded;

        edad = CalcAge(2023, nacimiento);

        std::cout << "Los datos ingresados son: " << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "CURP: " << curp << std::endl;
        std::cout << "Maximo: " << maximo << std::endl;
        std::cout << "Deducible: " << ded << std::endl;
    }
};

//TODO: Fill with data
class Casa : public Poliza {
};
class Carro : public Poliza {
private:
    int kilometros;
    std::string modelo;
    int numeroSerie;
    std::string marca;
    int year;
};
class Vida : public Poliza {};

#endif //UNIAT_CODES_LIBRERIA_H
