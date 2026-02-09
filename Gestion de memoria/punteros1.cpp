#include <iostream>
using namespace std;

void cambiar(int* x, int* y){
    if(x == nullptr || y == nullptr) {      //comprobacion de puntero vacío
        cout << "Puntero nulo." << endl;
        return;
    }
    
    int temp = *x;      //intercambio de valores
    *x = *y;
    *y = temp;
}

int main() {
    int* z = nullptr;
    int* p = nullptr;        // C++11: puntero nulo tipo-seguro
    double* q = nullptr;     // Preferible sobre NULL
    char* r = nullptr;       
    
    cambiar(p, z);

    cout << &p << endl;
    cout << &q << endl;
    cout << &r << endl;
    
    int a;
    double b;
    char c;
    
    cout << "ingresa un entero, un double y un caracter:" << endl; 
    cin >> a;
    p = &a;     //notar que para guardar una direccion en un puntero
    cin >> b;   //por definicion se le pasa la direccion de la variable 
    q = &b;     //NO EL VALOR -> *p = a ❌ MAL
    cin >> c;   
    r = &c;
    
    cout << endl;

    cout << *p << endl;
    cout << *q << endl;
    cout << *r << endl;
    
    cout << endl;
    
    int t = 7;
    z = &t;
        
    cambiar(p,z);

    cout << *p << endl;
    cout << *z << endl;

    return 0;
}
