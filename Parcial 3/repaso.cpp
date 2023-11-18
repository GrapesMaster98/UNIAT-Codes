#include <iostream>
#include <string>

//Estructuras

struct PERSON {
    int edad;
    std::string name;
    std::string ocupacion;
    int sueldo;
};

//Calcular la edad faltante para jubilación
int edadFalt(int edadActual) {
    int edadJubilacion = 65;

    int resultado = edadJubilacion - edadActual;

    return resultado;
}

//Calcular que tan jodido estás al mes... digo su salario.
int calcSueldo(int sueldo, int edad) { // Añadimos un segundo parametro llamado edad, la cuál usaremos para calcular el total.
    int results = sueldo * 12 * edad * 0.10;

    return results;
}

int main()
{

    //Llamar al strcut de persona
    struct PERSON persona;

    //Pedimos la edad
    std::cout << "Ingresa tu edad:" << std::endl;
    std::cin >> persona.edad;

    //Si ya tiene 65 años (o más) se le indica y termina el programa.
    if (persona.edad >= 65) {
        std::cout << "Ya tendrias que estar jubilado." << std::endl;
        return 0;
    }

    //Pedida de datos coomo nombre, ocupación, etc.
    std::cout << "Ingresa tu sueldo mensual" << std::endl;
    std::cin >> persona.sueldo;

    std::cout << "Ingresa tu ocupacion" << std::endl;
    std::cin >> persona.ocupacion;

    std::cout << "Ingresa tu nombre" << std::endl;
    std::cin >> persona.name;

    //Llamamos a las funciones para el sueldo y la edad.
    int edadFinal = edadFalt(persona.edad);
    int sueldoFinal = calcSueldo(persona.sueldo, edadFinal); //Usamos lo arrogado por edadFinal y finalizamos el calculo.

    //Imprimimos los datos finales.
    std::cout << "Nombre: " << persona.name << std::endl;
    std::cout << "Ocupacion: " << persona.ocupacion << std::endl;
    std::cout << "Te faltan: " << edadFinal << " anos para jubilarte." << std::endl;
    std::cout << "Tendrias: " << sueldoFinal << " pesos ahorrados." << std::endl;



    return 0;
}