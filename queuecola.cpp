#include <iostream>
using namespace std;

/*
  implementacion de una estructura queue/cola
  estructura tipo FIFO(first in, first out) "primero en entrar, primero en salir"
  algunas funciones comunes 
*/

template<typename T>
class QueueLinked {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& d) : dato(d), siguiente(nullptr) {}
    };
    
    Nodo* frente;
    Nodo* final;
    size_t tamaño;
    
public:
    QueueLinked() : frente(nullptr), final(nullptr), tamaño(0) {}
    
    ~QueueLinked() {
        while (!empty()) {
            dequeue();
        }
    }
    
    void enqueue(const T& elemento) {
        Nodo* nuevo = new Nodo(elemento);
        if (empty()) {
            frente = final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        tamaño++;
    }
    
    T dequeue() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        
        T valor = frente->dato;
        Nodo* temp = frente;
        frente = frente->siguiente;
        
        if (frente == nullptr) {
            final = nullptr;
        }
        
        delete temp;
        tamaño--;
        return valor;
    }
    
    T& front() {
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }
        return frente->dato;
    }
    
    bool empty() const {
        return frente == nullptr;
    }
    
    size_t size() const {
        return tamaño;
    }
};

int main(){
    QueueLinked<int> cola;

    cout << "La cola esta vacia? " 
         << (cola.empty() ? "Si" : "No") << endl;

    // Insertamos elementos
    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    cout << "Tamanio de la cola: " << cola.size() << endl;
    cout << "Elemento al frente: " << cola.front() << endl;

    // Quitamos elementos
    cout << "Sale de la cola: " << cola.dequeue() << endl;
    cout << "Sale de la cola: " << cola.dequeue() << endl;

    cout << "Elemento al frente ahora: " << cola.front() << endl;
    cout << "Tamanio actual: " << cola.size() << endl;

    // Último elemento
    cout << "Sale de la cola: " << cola.dequeue() << endl;

    cout << "La cola esta vacia? " << (cola.empty() ? "Si" : "No") << endl;

    return 0;
}
