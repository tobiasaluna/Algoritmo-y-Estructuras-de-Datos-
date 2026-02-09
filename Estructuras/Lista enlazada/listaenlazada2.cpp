#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Nodo {
  T dato;
  Nodo* siguiente;
  
  Nodo(T valor) : dato(valor), siguiente(nullptr) {}
  
  void print() {
    cout << dato << " ";
    if (siguiente != nullptr) {
      siguiente->print();
    }
  }
};

class List {
public:
    List(){
      head = nullptr;
    }                  // Constructor por defecto (lista vacía)
    List(Nodo<int>* h){
      head = h;
    }   // Constructor con nodo inicial
    ~List(){
      while(head!=nullptr){
        Nodo<int>* temp = head;
        head = head->siguiente;
        delete temp;
      }
    }                 // Destructor (libera memoria)

    // Agregar al inicio
    void push(int val){                    
      Nodo<int>* newNode = new Nodo(val);  // Crea nuevo nodo
      newNode->siguiente = head;           // El nuevo nodo apunta al anterior primer nodo
      head = newNode;                      // El nuevo nodo se convierte en la cabeza
    } 
    // Verificar si está vacía
    bool isEmpty(){         
      return head == nullptr;
    }     
    // Obtener valor del primer nodo
    int getHead(){      
      if (isEmpty()) {
        throw runtime_error("Lista vacía");
      }
      return head->dato;
    }
    // Obtener la sublista sin el primer nodo
    List* getTail(){    
      return new List(head->siguiente);
    }    
    // Imprimir la lista
    void print(){
      cout << "Lista: ";
      Nodo<int>* temp = head;
      while (temp != nullptr) {
        cout << temp->dato;
        if (temp->siguiente != nullptr) cout << " -> ";
        temp = temp->siguiente;
      }
      cout << endl;  
    }       

private:
    Nodo<int>* head;         // Puntero al primer nodo
};

int main(){
  Nodo<int> head(10);
  List Lista;

  Lista.push(10);
  Lista.push(10);
  Lista.push(10);
  Lista.push(10);
  
  Lista.print();

  return 0;
}
