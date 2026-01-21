#include <iostream>
using namespace std;

template<typename T>
class ColaCircular {
private:
    T* buffer;
    int capacidad;
    int frente;
    int final;
    int tamano;
    
public:
    ColaCircular(int cap) : capacidad(cap), frente(0), final(0), tamano(0) {
        buffer = new T[capacidad];
    }
    
    bool enqueue(const T& elemento) {
        if (tamaño >= capacidad) {
            return false; // Cola llena
        }
        
        buffer[final] = elemento;
        final = (final + 1) % capacidad;
        tamano++;
        return true;
    }
    
    bool dequeue(T& elemento) {
        if (tamano == 0) {
            return false; // Cola vacía
        }
        
        elemento = buffer[frente];
        frente = (frente + 1) % capacidad;
        tamano--;
        return true;
    }
};

int main() {
    ColaCircular<int> cola(5); // Cola de enteros con capacidad 5
    int valor;

    // Insertar elementos
    cout << "Insertando elementos..." << endl;
    for (int i = 1; i <= 5; i++) {
        if (cola.enqueue(i * 10)) {
            cout << "Insertado: " << i * 10 << endl;
        } else {
            cout << "Cola llena, no se pudo insertar " << i * 10 << endl;
        }
    }

    // Extraer elementos
    cout << "\nExtrayendo elementos..." << endl;
    while (cola.dequeue(valor)) {
        cout << "Extraido: " << valor << endl;
    }

    return 0;
}
