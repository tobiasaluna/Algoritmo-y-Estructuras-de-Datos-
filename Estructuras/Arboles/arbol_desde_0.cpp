#include <iostream>
using namespace std;
/*
codigo de arbol binario:
- nodo tipo struct
- implementacion de metodos insertar, inorder y buscar
funcion main probando el arbol
*/
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) : dato(val), izq(nullptr), der(nullptr) {}
};

class ABB {
private: 
    Nodo* raiz;
    void inOrdenRec(Nodo* nodo);

public:
    ABB() : raiz(nullptr) {}

    void getRaiz() {
        if (raiz != nullptr) {
            cout << "Raiz: " << raiz->dato << endl;
        } else {
            cout << "El arbol esta vacio." << endl;
        }
    }

    void setRaiz(int val) {
        raiz = new Nodo(val);
    }

    Nodo* insertarRec(Nodo* nodo, int val);
    void insertar(int val) {
        raiz = insertarRec(raiz, val);
    }

    void inOrden() {
        cout << "Recorrido inorden: ";
        inOrdenRec(raiz);
        cout << endl;
    }
    
    void buscar(int val) {
        Nodo* actual = raiz;
        while (actual != nullptr) {
            if (val == actual->dato) {
                cout << "Valor " << val << " encontrado en el arbol." << endl;
                return;
            } else if (val < actual->dato) {
                actual = actual->izq;
            } else {
                actual = actual->der;
            }
        }
        cout << "Valor " << val << " no encontrado en el arbol." << endl;
    }
};

Nodo* ABB::insertarRec(Nodo* nodo, int val) {
    if (nodo == nullptr) {
        return new Nodo(val);
    }
    if (val < nodo->dato) {
        nodo->izq = insertarRec(nodo->izq, val);
    } else {
        nodo->der = insertarRec(nodo->der, val);
    }
    return nodo;
} 

void ABB::inOrdenRec(Nodo* nodo) {
    if (nodo != nullptr) {
        inOrdenRec(nodo->izq);
        cout << nodo->dato << " ";
        inOrdenRec(nodo->der);
    }
}

// ------------------------------
// FUNCION MAIN DE PRUEBA
// ------------------------------
int main() {
    ABB arbol;

    cout << "Prueba de setRaiz():" << endl;
    arbol.setRaiz(10);
    arbol.getRaiz();
    cout << endl;

    cout << "Insertando valores..." << endl;
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(12);
    arbol.insertar(20);

    cout << endl;
    arbol.getRaiz();

    cout << endl;
    arbol.inOrden();  // Debe mostrar: 3 5 7 10 12 15 20

    cout << endl << "Buscando valores:" << endl;
    arbol.buscar(7);   // Existe
    arbol.buscar(10);  // Raíz
    arbol.buscar(25);  // No existe

    cout << endl << "Fin de las pruebas." << endl;

    return 0;
}

