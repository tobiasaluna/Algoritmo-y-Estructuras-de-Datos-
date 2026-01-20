#include <iostream>
using namespace std;
/*
struct nodo 
class list
implementacion de algunas funciones comunes 
*/

// Definición de la estructura del nodo
struct Nodo {
    int value;     // Valor del nodo
    Nodo* next;    // Puntero al siguiente nodo
    
    Nodo(int val); // Constructor
    void print();  // Método para imprimir el nodo
};

// Implementación del constructor
// Inicializa el valor y establece el puntero a nullptr por seguridad
Nodo::Nodo(int val) : value(val), next(nullptr) {}

// Implementación del método print
// Muestra tanto el valor como la dirección del siguiente nodo
void Nodo::print() {
    std::cout << "[NODO] valor: " << value << ", siguiente: " << next << std::endl;
}

// Definición de la clase Lista
class List {
public:
    List();             // Constructor por defecto (lista vacía)
    List(Nodo* head);   // Constructor con nodo inicial
    ~List();            // Destructor (libera memoria)
    void push(int val); // Agregar al inicio
    bool isEmpty();     // Verificar si está vacía
    int getHead();      // Obtener valor del primer nodo
    List* getTail();    // Obtener la sublista sin el primer nodo
    void print();       // Imprimir la lista

private:
    Nodo* head;         // Puntero al primer nodo
};

// Constructor por defecto - crea lista vacía
List::List() : head(nullptr) {}

// Constructor con nodo inicial - permite inicializar con un nodo existente
List::List(Nodo* head) : head(head) {}

// Destructor - implementa RAII (Resource Acquisition Is Initialization)
List::~List() {
    std::cout << "Destruyendo lista..." << std::endl;

    // Liberación iterativa de todos los nodos
    while (!isEmpty()) {
        Nodo* temp = head;    // Guarda referencia al nodo actual
        head = head->next;    // Avanza al siguiente nodo
        delete temp;          // Libera el nodo actual
    }
}

// Inserción al inicio - O(1) complejidad temporal
void List::push(int val) {
    Nodo* newNode = new Nodo(val);  // Crea nuevo nodo
    newNode->next = head;           // El nuevo nodo apunta al anterior primer nodo
    head = newNode;                 // El nuevo nodo se convierte en la cabeza
}

// Verificación de lista vacía - O(1) complejidad temporal
bool List::isEmpty() {
    return head == nullptr;
}

// Acceso al primer elemento - O(1) complejidad temporal
int List::getHead() {
    if (isEmpty()) 
        throw std::runtime_error("La lista está vacía");
    
    return head->value;
}

// Obtener sublista (cola) - O(1) complejidad temporal
// Nota: Crea una nueva lista que comparte nodos con la original
List* List::getTail() {
    if (isEmpty()) 
        throw std::runtime_error("La lista está vacía");
    
    return new List(head->next);
}

// Impresión recursiva de la lista
void List::print() {
    std::cout << "[LISTA] ";

    if (isEmpty()) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    head->print();           // Imprime el primer nodo
    getTail()->print();      // Llamada recursiva para el resto
}

int main() {

    // Crear lista vacía
    List lista;
    cout << "¿Lista vacia? " << (lista.isEmpty() ? "Si" : "No") << endl;

    // Insertar elementos
    lista.push(10);
    lista.push(20);
    lista.push(30);

    cout << "\nDespues de insertar 30, 20, 10:" << endl;
    cout << "¿Lista vacia? " << (lista.isEmpty() ? "Si" : "No") << endl;

    // Obtener cabeza
    cout << "Head de la lista: " << lista.getHead() << endl;

    // Imprimir lista completa
    cout << "\nImpresion de la lista:" << endl;
    lista.print();

    // Obtener cola
    cout << "\nImpresion de la cola (sin el primer nodo):" << endl;
    List* tail = lista.getTail();
    tail->print();

    // Liberar memoria de la cola creada con new
    delete tail;

    cout << "\nFin del programa" << endl;
    return 0;
}
