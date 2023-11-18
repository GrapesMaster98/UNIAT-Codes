#include <iostream>
#include <string>

class Persona {
    public:
        Persona(std::string nombre, int edad, float peso) {
            this->nombre = nombre;
            this->edad = edad;
            this->peso = peso;
        }

        std::string getNombre() {
            return this->nombre;
        }

        int getEdad() {
            return this->edad;
        }

        float getPeso(){
            return this->peso;
        }

        void setNombre(std::string nombre) {
            this->nombre = nombre;
        }

        void setEdad(int edad){
            this->edad = edad;
        }

        void setPeso(float peso){
            this->peso = peso;
        }

    private:
        std::string nombre;
        int edad;
        float peso;

    protected:
        friend class Amigo;
        virtual std::string getNombreCompleto() {
            return this->nombre;
        }
};

// Herencia
class Estudiante : public Persona {
    public:
        Estudiante(std::string nombre, int edad,float peso, std::string carrera) : Persona(nombre, edad, peso) {
            this->carrera = carrera;
        }
        std::string getCarrera() {
            return this->carrera;
        }
        void setCarrera(std::string carrera) {
            this->carrera = carrera;
        }
    private:
        std::string carrera;

    friend class Maestro;
};

class Maestro : public Persona {
    public:
        Maestro(std::string nombre, int edad, std::string carrera):Persona(nombre, edad) {
            this->carrera = carrera;
        }
        std::string getCarrera() {
            return this->carrera;
        }
        void setCarrera(std::string carrera) {
            this->carrera = carrera;
        }
        std::string getNombreCompleto(Estudiante estudiante) {
            return estudiante.getNombreCompleto();
        }
    private:
        std::string carrera;
};

//Encapsulamiento
class Amigo {
    public:
        std::string getNombreCompleto(Persona persona) {
            return persona.getNombreCompleto();
        }
};

//Polimorfismo
class Animal {
    public:
        void sonido() {
            std::cout << "Sonido de animal" << std::endl;
        }
};

class Perro : public Animal {
    public:
        void sonido() {
            std::cout << "Guau" << std::endl;
        }
};

class Gato : public Animal {
    public:
        void sonido() {
            std::cout << "Miau" << std::endl;
        }
};

// Sobrecarga de Funciones
class Operaciones {
    public:
        int suma(int a, int b) {
            return a + b;
        }
        int suma(int a, int b, int c) {
            return a + b + c;
        }
        int suma(int a, int b, int c, int d) {
            return a + b + c + d;
        }
        int suma(int a, int b, int c, int d, int e) {
            return a + b + c + d + e;
        }
};

//Sobrecarga de Operadores
class Vector {
    public:
        Vector(int x, int y) {
            this->x = x;
            this->y = y;
        }

        Vector operator+(Vector v) {
            return Vector(this->x + v.x, this->y + v.y);
        }

        Vector operator-(Vector v) {
            return Vector(this->x - v.x, this->y - v.y);
        }
        Vector operator*(Vector v) {
            return Vector(this->x * v.x, this->y * v.y);
        }
        Vector operator/(Vector v) {
            return Vector(this->x / v.x, this->y / v.y);
        }

    private:
        int x;
        int y;
};


int main(){
    Persona Juan("Juan", 20,45.5);
    std::cout << Juan.getNombre() << std::endl;
    std::cout << Juan.getEdad() << std::endl;

    Juan.setNombre("Juanito");
    Juan.setEdad(18);
    std::cout << Juan.getNombre() << std::endl;
    std::cout << Juan.getEdad() << std::endl;

    Estudiante Paco("Paco", 20,60.7, "Ing. Sistemas");
    std::cout << Paco.getNombre() << std::endl;
    std::cout << Paco.getEdad() << std::endl;
    std::cout << Paco.getCarrera() << std::endl;
    Paco.setCarrera("Ing. En Programacion de Videojuegos");

    Maestro Zucco("Zucco",22,"Ing. En Programacion de Videojuegos");
    std::cout << Zucco.getNombre() << std::endl;
    Zucco.setCarrera("Cine");

    Amigo Pepe;
    std::cout << Pepe.getNombreCompleto(Juan) << std::endl;
    std::cout << Zucco.getNombreCompleto(Paco) << std::endl;

    Animal animal;
    animal.sonido();
    Gato gato;
    gato.sonido();
    Perro perro;
    perro.sonido();

    Operaciones operaciones;
    std::cout << operaciones.suma(1,2) << std::endl;
    std::cout << operaciones.suma(1,2,3) << std::endl;
    std::cout << operaciones.suma(1,2,3,4) << std::endl;
    std::cout << operaciones.suma(1,2,3,4,5) << std::endl;

    Vector v1(1,2);
    Vector v2(3,4);

    Vector r = v1+v2;
    return 0;
}