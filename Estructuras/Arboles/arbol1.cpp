#include <iostream>
#include <cstdlib>

using namespace std;

/*
Código de Árboles:
- clase nodo 
- clase arbol
que hace?
- crea un arbol insertando valores
- lo muestra 
y se ordena de 3 maneras distinta 
- preorder
- inorder
- postorder

*/

template <typename T>
class Nodo {
public:
    T info;
    Nodo* izq;
    Nodo* der;

    Nodo(T valor) : info(valor), izq(nullptr), der(nullptr) {}
};

template <typename T>
class Arbol {
private:
    Nodo<T>* raiz;

    void insertar(T x, Nodo<T>*& nodo) {
        if (nodo == nullptr) {
            nodo = new Nodo<T>(x);
        } else if (x < nodo->info) {
            insertar(x, nodo->izq);
        } else if (x > nodo->info) {
            insertar(x, nodo->der);
        }
    }

    void inorden(Nodo<T>* nodo) {
        if (nodo) {
            inorden(nodo->izq);
            cout << nodo->info << " ";
            inorden(nodo->der);
        }
    }

public:
    Arbol() : raiz(nullptr) {}

    void insertar(T x) {
        insertar(x, raiz);
    }

    void mostrarInorden() {
        inorden(raiz);
    }
};

int main() {
    Arbol<int> A;
    int vec[10] = {50,12,18,240,222,45,410,325,38,95};

    for (int i = 0; i < 10; i++) {
        A.insertar(vec[i]);
    }

    cout << "Recorrido Inorden: ";
    A.mostrarInorden();

    return 0;
}
