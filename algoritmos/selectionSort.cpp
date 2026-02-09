#include <iostream>
#include <vector>
using namespace std;

/*
En cada pasada, buscar el elemento más pequeño de la parte no ordenada y 
colocarlo en su posición correcta.
Características:
- Complejidad temporal: O(n²) en todos los casos
- Complejidad espacial: O(1) - ordenamiento in-place
- Estabilidad: No estable (puede cambiar el orden de elementos iguales)
*/

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    vector<int> numeros = {64, 25, 12, 22, 11};

    cout << "Vector original: ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;

    selectionSort(numeros);

    cout << "Vector ordenado: ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
