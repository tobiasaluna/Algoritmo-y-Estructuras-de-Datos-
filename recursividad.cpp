#include <iostream>
using namespace std;
/* Un stack frame (marco de pila) en C es un bloque de memoria temporal que se crea en la pila (stack) 
cada vez que se llama a una función, conteniendo sus parámetros, variables locales y la dirección de retorno
para saber dónde continuar tras su ejecución; se apila con cada llamada y se desapila al finalizar, 
gestionando la ejecución de funciones de forma organizada y recursiva.

Componentes de un Stack Frame:
- Puntero de retorno: Dirección de la instrucción donde debe continuar la ejecución
- Parámetros: Todos los argumentos pasados a la función
- Variables locales: Variables declaradas dentro del ámbito de la función
- Espacio para valor de retorno: Memoria reservada para el resultado de la función

Implicaciones para la recursión:
- Cada llamada recursiva crea un nuevo Stack Frame
- La memoria se acumula hasta llegar al caso base
- Si la recursión es muy profunda, puede causar stack overflow
- La liberación de memoria ocurre en orden LIFO (Last In, First Out)
*/

// recursividad simple: funcion factorial
int factorial(int n){
    if (n == 1) return 1;      // caso base 
    return n * factorial(n-1); // llamado a si misma 
}

int main() {

    cout << factorial(5) << endl;

    return 0;
}
