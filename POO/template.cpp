#include <iostream>
using namespace std;

template<typename T>                // No definas el tipo de dato ahora, si no cuando te lo pase 
class Numero {                      // "T" es un molde, cuando se instancia el obj *Numero<int>*
    private:                        // le pasa a la clase el tipo que va a usar
        T dato;                     // placeholder 
    public:
        Numero(T d) : dato(d) {}
        T obtener(){
            return dato;
        }
};

int main() {
    Numero<int> num(10);
    Numero<double> num1(3.14);
    Numero<string> name("chinits");

    cout << num.obtener() << endl;
    cout << num1.obtener() << endl;
    cout << name.obtener() << endl;

    return 0;
}
