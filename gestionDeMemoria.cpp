#include <iostream>
using namespace std;

class MiClase {
public:
    int valor;
    MiClase(int v) : valor(v) {
        std::cout << "Constructor llamado, valor: " << valor << std::endl;
    }
    ~MiClase() {
        std::cout << "Destructor llamado, valor: " << valor << std::endl;
    }
};

int main(){
    int* p = new int(20);   // asigna memoria y valor 
    //*p = 10;              // otra forma de asignar valor 

    cout << &p << endl;
    cout << *p << endl;

    delete p;

    double* r = new double;             // contiene un valor residual
    double* q = new double(3.14159);    // asigna un valor especifico

    cout << &r << endl;      
    cout << *r << endl; //valor basura

    cout << &q << endl;
    cout << *q << endl; //valor asignado 

    delete r;
    delete q;

    MiClase* obj = new MiClase(100);   // 1. Solicita memoria
                                       // 2. Verifica disponibilidad  
                                       // 3. Llama constructor MiClase(100)
                                       // 4. Retorna dirección
    
    std::cout << "Despues de new, valor: " << obj->valor << std::endl;
    
    delete obj;

    int* numero = new int(42);         // Asignación individual
    delete numero;                     // Liberación individual
    numero = nullptr;                  // Evitar puntero colgante
    
    int* array = new int[100];         // Asignación de array para 100 elementos del tipo int 
    delete[] array;                    // Liberación de array
    array = nullptr;                   // Evitar puntero colgante


    return 0;
}
