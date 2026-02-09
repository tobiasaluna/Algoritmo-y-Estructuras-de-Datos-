#include <iostream>
#include <cmath>
using namespace std;

struct Punto {
    double x;
    double y;

    Punto() : x(0.0), y(0.0) {}
    
    Punto(double _x, double _y) : x(_x), y(_y) {}
};

class Punto2D_Clase {
    private:                                   // Por defecto privado
        double x, y;

    public:
        // Constructores
        Punto2D_Clase() : x(0.0), y(0.0) {}
        Punto2D_Clase(double x_val, double y_val) : x(x_val), y(y_val) {}

        // Getters (acceso controlado)
        double getX() const { return x; }
        double getY() const { return y; }

        // Setters (modificación controlada)
        void setX(double x_val) { 
            if (x_val >= -1000 && x_val <= 1000) {    // Validación
                x = x_val; 
            }
        }
        void setY(double y_val) { 
            if (y_val >= -1000 && y_val <= 1000) {    // Validación
                y = y_val; 
            }
        }

        // Métodos públicos
        double distanciaAlOrigen() const {
            return std::sqrt(x * x + y * y);
        }

        void imprimir() const {
            std::cout << "(" << x << ", " << y << ")" << std::endl;
        }
};

int main(){
    Punto punto;

    Punto otropunto(5.5, 6.6);

    Punto2D_Clase puntoconclase(1.1, 2.2);

    punto.x = 3.14;
    punto.y = 2.54;

    cout << punto.x << endl;
    cout << punto.y << endl; 

    cout << otropunto.x << ", " << otropunto.y << endl;

    puntoconclase.imprimir();
    
    cout << puntoconclase.distanciaAlOrigen() << endl;

    

    return 0;

}
