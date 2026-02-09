#include <iostream>
#include <queue>
#include <string>
using namespace std;

template<typename T>
struct ElementoPrioridad {
    T dato;
    int prioridad;
    
    bool operator<(const ElementoPrioridad& otro) const {
        return prioridad < otro.prioridad; // Mayor prioridad primero
    }
};

template<typename T>
class ColaPrioridad {
private:
    priority_queue<ElementoPrioridad<T>> heap;
    
public:
    void enqueue(const T& elemento, int prioridad) {
        heap.push({elemento, prioridad});
    }
    
    T dequeue() {
        if (heap.empty()) {
            throw std::underflow_error("Cola vacía");
        }
        
        T elemento = heap.top().dato;
        heap.pop();
        return elemento;
    }
    
    bool empty() const {
        return heap.empty();
    }
};

int main() {
    ColaPrioridad<string> cola;

    cola.enqueue("Tarea baja", 1);
    cola.enqueue("Tarea media", 3);
    cola.enqueue("Tarea urgente", 10);
    cola.enqueue("Tarea normal", 5);

    cout << "Atendiendo tareas por prioridad:\n";

    while (!cola.empty()) {
        cout << cola.dequeue() << endl;
    }

    return 0;
}
