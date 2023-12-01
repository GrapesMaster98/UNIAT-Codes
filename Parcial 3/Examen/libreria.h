#include <iostream>
#include <string>

#ifndef UNIAT_CODES_LIBRERIA_H
#define UNIAT_CODES_LIBRERIA_H

class Poliza { ;

public:
    std::string nombre;
    int edad;
    int nacimiento;
    std::string curp;
    int maximo;
    int deducible;


    Poliza(){};

    Poliza(std::string nombre, int edad, int nacimiento, std::string curp, int maximo, int deducible) {
        this->nombre = nombre;
        this->edad = edad;
        this->nacimiento = nacimiento;
        this->curp = curp;
        this->maximo = maximo;
        this->deducible = deducible;
    };

    //Setters
    void setName(std::string nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setNac(int nacimiento) {
        this->nacimiento = nacimiento;
    }

    void setCurp(std::string curp) {
        this->curp = curp;
    }

    void setMax(int maximo) {
        this->maximo = maximo;
    }

    void setDeducible(int deducible) {
        this->deducible = deducible;
    }

    //Getters
    std::string getName() {
        return this->nombre;
    }

    int getAge() {
        return this->edad;
    }

    int getBirthDate() {
        return this->nacimiento;
    }

    std::string getCURP() {
        return this->curp;
    }

    int getMax() {
        return this->maximo;
    }

    int getDeducible() {
        return this->deducible;
    }
};

//Funcs

int CalcAge(int currentYear, int birthDate) {
    Poliza poliza;

    //Rest the current year minus the current age of the client. We save that on the res variable.
    int res = currentYear - poliza.getAge();
    return res; //Return cus ofc we need to return that.
}
void StartQuestionare() {

    Poliza basePolicy;

    std::string name;
    int birthDate;
    std::string CURP;
    int max;
    int ded;

    //Ask for the data...
    std::cout << "Bienvenido al sistema de polizas" << std::endl;
    std::cout << "El mejor sistema, no acepto criticas" << std::endl;
    std::cout << "Ingresa el nombre del cliente: " << std::endl;
    std::cin >> name;
    std::cout << "Ingresa el año de nacimiento del cliente: " << std::endl;
    std::cin >> birthDate;
    std::cout << "Ingresa el CURP del cliente: " << std::endl;
    std::cin >> CURP;
    std::cout << "Ingresa el maximo de poliza del cliente: " << std::endl;
    std::cin >> max;
    std::cout << "Ingresa el deducible del cliente: " << std::endl;
    std::cin >> ded;

    //Convert the age
    int age = CalcAge(2023, birthDate);

    //Set stuff
    basePolicy.setName(name);
    basePolicy.setEdad(age);
    basePolicy.setCurp(CURP);
    basePolicy.setMax(max);
    basePolicy.setDeducible(ded);
    basePolicy.setNac(birthDate);

}
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
