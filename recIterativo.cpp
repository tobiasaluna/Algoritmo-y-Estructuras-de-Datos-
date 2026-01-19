#include <iostream>
#include <vector>
using namespace std;
/*
buscar el elemento mas grande del arreglo de manera iterativa
Ventajas de la versión iterativa:
- Memoria constante: O(1) en lugar de O(n)
- Mayor velocidad: Sin overhead de llamadas a funciones
- Sin límite de profundidad: No hay riesgo de stack overflow
*/

int maxArray(const vector<int> &a) {
    int m = a[0];

    for (int i = 1; i < a.size(); ++i) {
        m = max(m, a[i]);
    }

    return m;
}

int main() {
    vector<int> arr = {3, 7, 2, 10, 4};

    cout << maxArray(arr);

    return 0;
}
