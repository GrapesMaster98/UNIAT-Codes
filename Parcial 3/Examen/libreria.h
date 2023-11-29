#include <iostream>
#include <string>

#ifndef UNIAT_CODES_LIBRERIA_H
#define UNIAT_CODES_LIBRERIA_H

class Poliza {
public:
    std::string nombre;
    int edad;
    std::string nacimiento;
    std::string curp;
};

//TODO: Fill with data
class Casa : Poliza {};
class Carro : Poliza {};
class Vida : Poliza {};

#endif //UNIAT_CODES_LIBRERIA_H
