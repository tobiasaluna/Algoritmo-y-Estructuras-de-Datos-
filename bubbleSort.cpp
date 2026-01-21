#include <iostream>
#include <vector>
using namespace std;
/* 
int const N = 8;

void swap (int &a, int &b){                 
    int temp = a;                           
    a = b;                                  
    b = temp;
}

void imprimir (int b[N]){
    for (int i = 0; i < N; i++){
        cout << b[i] << " ";
    }
}
int main() {
    int a[N] = {34, 7, 23, 32, 5, 62, 32, 7};

    for (int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            if(a[i] < a[k]){
                swap(a[i], a[k]);
            }
        }
    }

    imprimir(a);

    return 0;
}
    */

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Realizar n-1 pasadas
    for (int i = 0; i < n - 1; i++) {
        bool intercambio = false;
        
        // En cada pasada, comparar elementos adyacentes
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar si están en orden incorrecto
                std::swap(arr[j], arr[j + 1]);
                intercambio = true;
            }
        }
        
        // Si no hubo intercambios, el arreglo ya está ordenado
        if (!intercambio) {
            break;
        }
    }
}

int main() {

    vector<int> array ={10, 41, 1, 2, 8, 99, 9, 77, 7, 4, 5};

    bubbleSort(array);

    for (int i = 0; i < 11; i++){
        cout << array[i] << ", ";
    }

    return 0;
}
