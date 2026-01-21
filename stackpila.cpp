#include <iostream>
using namespace std;

/*
  implementacion para entender como funciona una estructura stack(pila)
  LIFO(last in, first out) "primero en entrar, ultimo en salir"
  no se puede acceder a cualquier posicion 
*/

template<typename T>
class StackArray {
private:
    T* datos;
    int capacidad;
    int tope;
    
public:
    StackArray(int cap = 100) : capacidad(cap), tope(-1) {
        datos = new T[capacidad];
    }
    
    ~StackArray() {
        delete[] datos;
    }
    
    void push(const T& elemento) {
        if (tope >= capacidad - 1) {
            throw std::overflow_error("Stack overflow");
        }
        datos[++tope] = elemento;
    }
    
    T pop() {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }
        return datos[tope--];
    }
    
    T& top() {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return datos[tope];
    }
    
    bool empty() const {
        return tope == -1;
    }
    
    size_t size() const {
        return tope + 1;
    }
};

int main (){
    StackArray<int> pila(5);

    pila.push(10);
    pila.push(20);
    pila.push(30);
    
    cout << "Elemento en el tope: " << pila.top() << endl;
    cout << "Tamanio de la pila: " << pila.size() << endl;
    cout << "Pop: " << pila.pop() << endl;
    cout << "Pop: " << pila.pop() << endl;
    cout << "Elemento en el tope: " << pila.top() << endl;
    cout << "Tamanio actual: " << pila.size() << endl;
    
    return 0; 
}
