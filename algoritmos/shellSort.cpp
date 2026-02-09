#include <iostream>
#include <vector>
using namespace std;

/*
La idea principal es ordenar sub-arreglos más pequeños mediante el ordenamiento por inserción antes de ordenar todo el arreglo.
Características:
-Complejidad temporal: Depende de la secuencia de gaps utilizada
  - Con potencias de 2: O(n²)
  - Con secuencia de Hibbard (2^k - 1): O(n^(3/2))
- Complejidad espacial: O(1)
- Estabilidad: No estable

Paso a Paso del Shell Sort
1. Elegir una secuencia de gaps (intervalos)
2. Para cada gap, realizar un ordenamiento por inserción en los sub-arreglos definidos por ese gap
3. Reducir el gap y repetir hasta que el gap sea 1
4. Realizar un último ordenamiento por inserción para asegurar que el arreglo esté completamente ordenado

*/

// Shell Sort básico
void shellSort(vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Shell Sort con Hibbard
void shellSortHibbard(vector<int>& arr) {
    int n = arr.size();
    vector<int> gaps;

    for (int k = 1; (1 << k) - 1 < n; k++) {
        gaps.push_back((1 << k) - 1);
    }

    for (int i = gaps.size() - 1; i >= 0; i--) {
        int gap = gaps[i];

        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int k;

            for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
                arr[k] = arr[k - gap];
            }
            arr[k] = temp;
        }
    }
}

int main() {
    vector<int> arr1 = {9, 5, 1, 4, 3};
    vector<int> arr2 = arr1;

    shellSort(arr1);
    shellSortHibbard(arr2);

    cout << "Shell Sort basico: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nShell Sort Hibbard: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}
