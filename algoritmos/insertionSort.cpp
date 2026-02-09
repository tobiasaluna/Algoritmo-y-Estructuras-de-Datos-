#include <iostream>
#include <vector>
using namespace std;

/*
Idea principal: Similar a ordenar cartas en la mano
Características:
- Complejidad temporal: O(n²) en el peor caso, O(n) en el mejor caso
- Complejidad espacial: O(1) - ordenamiento in-place
- Estabilidad: Estable
se toma el segundo elemento y se compara con el que tiene a la izquierda
si es mas chico swap y sigo comparando si es que hay mas numeros a la izq 
*/

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = clave;
    }
}

int main() {
    vector<int> datos = {8, 3, 5, 2, 9, 1};

    cout << "Vector original: ";
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i] << " ";
    }

    insertionSort(datos);

    cout << "\nVector ordenado: ";
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i] << " ";
    }

    return 0;
}
