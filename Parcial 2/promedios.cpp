#include <iostream>
#include <string>

//Definir funciones

int pedida() {
    
    int cals;
    
    std::cout << "Porfavor ingresa las calificaciones (separadas por comas):" << std::endl;
    std::cin >> cals;
    
    return cals;
}

int suma(int cal1, int cal2, int cal3, int cal4, int cal5) {
    
    int results;
    
    results = (cal1 + cal2 + cal3 + cal4 + cal5) / 5;
    
    return results;
}

int main()
{
    int a,b,c,d,e = pedida();
    
    int prom = suma(a,b,c,d,e);
    
    std::cout << "Tu promedio es:" << " " << prom << std::endl;
    
    
    return 0;
}