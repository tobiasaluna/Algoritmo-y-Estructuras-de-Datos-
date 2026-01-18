#include <iostream>
using namespace std;
/*
    ESTRUCTURA LISTA ENLAZADA:
        - Struct del tipo de dato para linkedlist (dato + siguiente)
        - Metodos comunes insertar al inicio, al final, en una posicion conocida,
        desencolar
*/
struct Nodo{
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};  

void insertar_al_inicio(Nodo** cabeza, int valor) {
    Nodo* nuevo_nodo = new Nodo(valor);
    nuevo_nodo->siguiente = *cabeza;     // El nuevo nodo apunta a la cabeza actual
    *cabeza = nuevo_nodo;                // La cabeza ahora apunta al nuevo nodo
}

void insertar_al_final(Nodo** cabeza, int valor){
    Nodo* nuevo_nodo = new Nodo(valor); 
    
    // Si la lista está vacía, el nuevo nodo es la cabeza
    if (cabeza == nullptr) return;
    
    // Si no está vacía, recorrer hasta el último nodo
    Nodo* temp = *cabeza;
    while(temp->siguiente != nullptr){
        temp = temp->siguiente;
    }

    // Enlazar el último nodo con el nuevo nodo
    temp->siguiente = nuevo_nodo;
}

void insertarEnPosicion (Nodo** cabeza, int valor, int posicion){
    //creamos un espacio en la memoria
    Nodo* nuevo_nodo = new Nodo(valor);

    //insertar al inicio
    if (posicion == 0){
        nuevo_nodo->siguiente = *cabeza;
        *cabeza = nuevo_nodo;
        return;
    }

    Nodo* temp = *cabeza;
    //recorrer hasta el nodo anterior a la posicion
    for(int i = 0; temp != nullptr && i < posicion - 1; i++){
        temp = temp->siguiente;
    }

    //si la posicion es mayor al numero de nodos 
    if(temp == nullptr) return;

    //enlazar punteros 
    nuevo_nodo->siguiente = temp->siguiente;
    temp->siguiente = nuevo_nodo;
}

void imprimir_lista(Nodo* cabeza) {
    while (cabeza != nullptr) {
        cout << cabeza->dato << " -> ";
        cabeza = cabeza->siguiente;
    }
    cout << "NULL" << std::endl;
}


int main(){
    Nodo* lista = nullptr;              // Lista inicialmente vacía
    
    insertar_al_inicio(&lista, 10);
    insertar_al_inicio(&lista, 20);
    insertar_al_inicio(&lista, 30);
    
    imprimir_lista(lista);              // 30 -> 20 -> 10 -> NULL
    
    // Limpieza de memoria
    while (lista != nullptr) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    Nodo* lista2 = nullptr;

    insertar_al_inicio(&lista2, 1);
    insertar_al_inicio(&lista2, 2);
    insertar_al_inicio(&lista2, 3);
    insertar_al_inicio(&lista2, 4);
    insertar_al_inicio(&lista2, 5);
    insertar_al_final(&lista2, 0);
    insertar_al_final(&lista2, -1);

    insertarEnPosicion(&lista2, 10, 4);

    imprimir_lista(lista2);

    while (lista2 != nullptr) {
        Nodo* temp = lista2;
        lista2 = lista2->siguiente;
        delete temp;
    }

    return 0;
}
