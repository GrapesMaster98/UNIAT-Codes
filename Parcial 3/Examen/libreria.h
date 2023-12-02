#ifndef UNIAT_CODES_LIBRERIA_H
#define UNIAT_CODES_LIBRERIA_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>

class Poliza {

public:
    std::string nombre, curp;
    int edad, nacimiento, maximo, deducible, folio;

    Poliza() {}

    Poliza(std::string nombre, int edad, int nacimiento, std::string curp, int maximo, int deducible, int folio)
            : nombre(nombre), edad(edad), nacimiento(nacimiento), curp(curp), maximo(maximo), deducible(deducible), folio(folio) {}

    int GenID(const Poliza& poliza) {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(1000000000, 9999999999);

        int random_number = distribution(generator);

        return random_number;
    }

    int CalcAge(int currentYear) const {
        return currentYear - nacimiento;
    }

    void SetData() {
        std::cout << "Ingresa el nombre del cliente: " << std::endl;
        std::cin >> nombre;
        std::cout << "Ingresa el año de nacimiento del cliente: " << std::endl;
        std::cin >> nacimiento;
        std::cout << "Ingresa el CURP del cliente: " << std::endl;
        std::cin >> curp;
        std::cout << "Ingresa el maximo de poliza del cliente: " << std::endl;
        std::cin >> maximo;
        std::cout << "Ingresa el deducible del cliente: " << std::endl;
        std::cin >> deducible;

        edad = CalcAge(2023);
    }
};

class Casa : public Poliza {
public:
    float size;
    int antiguedad;
    std::string location;

    void SetData() {
        Poliza::SetData();

        std::cout << "Bien, ahora crearemos la poliza de la casa, porfavor llena los sigueintes datos." << std::endl;
        std::cout << "Ingresa el tamanio de la casa en m2: " << std::endl;
        std::cin >> size;
        std::cout << "Ingresa el anio de construccion de la casa: " << std::endl;
        std::cin >> antiguedad;
        if (antiguedad > 2023) {
            std::cout << "El anio de construccion no puede ser mayor al actual." << std::endl;
            exit(1);
        } else {
            std::cout << "Ingresa la ubicacion de la casa: " << std::endl;
            std::cin >> location;

            std::cout << "El cliente " << nombre << " de " << edad << " anios de edad, con CURP " << curp
                      << " fue registrado para una poliza de casa con los siguientes datos:" << std::endl;
            std::cout << "La casa ubicada en " << location << " con un tamanio de " << size << "m2, construida en "
                      << antiguedad << " fue registrada correctamente." << std::endl;
            std::cout << "Poliza generada con el folio: " << GenID(*this) << std::endl;
        }
    }
};

class Carro : public Poliza {
private:
    int kilometros, numeroSerie, year;
    std::string modelo, marca;

public:

    void SetData() {
        Poliza::SetData();

        std::cout << "Bien, ahora crearemos la poliza del carro, porfavor llena los sigueintes datos." << std::endl;
        std::cout << "Ingresa el kilometraje del carro: " << std::endl;
        std::cin >> kilometros;
        std::cout << "Ingresa el numero de serie del carro: " << std::endl;
        std::cin >> numeroSerie;
        std::cout << "Ingresa el anio del carro: " << std::endl;
        std::cin >> year;

        std::cout << "El cliente " << nombre << " de " << edad << " anios de edad, con CURP " << curp
                  << " fue registrado para una poliza de carro con los siguientes datos:" << std::endl;
        std::cout << "El carro modelo " << modelo << " de la marca " << marca << " con " << kilometros
                  << "km, del anio " << year << " con el numero de serie " << numeroSerie
                  << " fue registrado correctamente." << std::endl;
        std::cout << "Poliza generada con el folio: " << GenID(*this) << std::endl;
    }
};

class Vida : Poliza {
private:
    std::string tipoSangre;
    std::string* enfermedades;
    int numEnfermedades;

public:
    Vida() : enfermedades(nullptr), numEnfermedades(0) {}

    ~Vida() {
        delete[] enfermedades;
    }

    void SetEnfermedades() {
        // Se sigue pidiendo hasta que se proporciona un número válido
        while (true) {
            std::cout << "Ingresa el número de enfermedades del cliente:" << std::endl;
            std::string numEnfermedadesStr;
            std::getline(std::cin, numEnfermedadesStr);

            // Verificar si la cadena ingresada es un número positivo
            if (std::all_of(numEnfermedadesStr.begin(), numEnfermedadesStr.end(), ::isdigit) && !numEnfermedadesStr.empty()) {
                // Convertir el número de enfermedades a un entero
                numEnfermedades = std::stoi(numEnfermedadesStr);
                break;
            } else {
                std::cerr << "Por favor, ingresa un número de enfermedades válido." << std::endl;
            }
        }

        // Reservar memoria para el array de enfermedades
        delete[] enfermedades;
        enfermedades = new std::string[numEnfermedades];

        std::cout << "Ingresa las enfermedades una por una:" << std::endl;

        // Pedir las enfermedades al usuario
        for (int i = 0; i < numEnfermedades; ++i) {
            std::cout << "Enfermedad " << i + 1 << ": ";
            std::getline(std::cin, enfermedades[i]);
        }
    }

    /*
     * THIS CHINGADERA TOOK ME WAY TOO MUCH TIME
     *
     * I fcking LOVE STACK OVERFLOW
     */


// Función para ignorar el resto de la línea
    void ignoreLine() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void DisplaySickness() const {
        std::cout << "Enfermedades del paciente: " << std::endl;
        for (int i = 0; i < numEnfermedades; ++i) {
            std::cout << "Enfermedad " << i + 1 << ": " << enfermedades[i] << std::endl;
        }
    }

    void SetData() {
        Poliza::SetData();

        std::cout << "Bien, ahora crearemos la poliza de vida, porfavor llena los sigueintes datos." << std::endl;
        std::cout << "Ingresa el tipo de sangre del cliente: " << std::endl;
        std::cin >> tipoSangre;
        SetEnfermedades();

        std::cout << "El cliente " << nombre << " de " << edad << " anios de edad, con CURP " << curp
                  << " fue registrado para una poliza de vida con los siguientes datos:" << std::endl;
        std::cout << "El cliente con el tipo de sangre " << tipoSangre << " con las siguientes enfermedadees: " << std::endl;
        DisplaySickness();
        std::cout << " fue registrado correctamente." << std::endl;
        std::cout << "Poliza generada con el folio: " << GenID(*this) << std::endl;
    }
};

void Menu() {
    Casa casa;
    Carro carro;
    Vida vida;

    int options;

    std::cout << "Elije la opcion que deseas usar:" << std::endl;
    std::cout << "[1] Poliza para Casa" << std::endl;
    std::cout << "[2] Poliza para Carro" << std::endl;
    std::cout << "[3] Poliza de Vida" << std::endl;
    std::cout << "[0] Salir" << std::endl;
    std::cin >> options;

    if (options == 1) {
        casa.SetData();
    } else if (options == 2) {
        carro.SetData();
    } else if (options == 3) {
        vida.SetData();
    } else if (options == 0) {
        exit(0);
    }
}

#endif //UNIAT_CODES_LIBRERIA_H
