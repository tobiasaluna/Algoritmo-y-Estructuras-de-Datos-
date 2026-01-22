#include <iostream>
#include <vector>

using namespace std;

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
