#include <iostream>
using namespace std;

class Persona{
    private:
        string name;
        int edad;
    public:
        Persona(string _name, int _edad) 
        : name(_name), edad( _edad) {}
                
        void getNombre() {
            cout << "Nombre: " << this->name << endl;
        }
        void setNombre(string _name) {
            name = _name;
        }
        void getEdad(){
            cout << "Edad: " << this->edad << endl;
        }
        void setEdad(int _edad){
            edad = _edad;
        }
        void mostrarPersona(){
            getNombre();
            getEdad();
        }
};    

class Perro {
    private:
        string nombre;
        int edad;
        bool paseado;
    
    public:
        Perro(string _nombre, int _edad, bool _paseado) 
        : nombre(_nombre), edad(_edad), paseado( _paseado) {}

        void setNombre (string _nombre) {
            nombre = _nombre;
        }
        void getNombre() {
            cout << nombre << endl;
        }
        void getEdad(){
            cout << "Edad: " << edad << endl;
        } 
        void setEdad(int _edad){
            edad = _edad;
        }
        void getPaseado (){
            if (paseado == true) {
                cout << this->nombre << " fue paseado. "<< endl;
            } else {
                cout << "Sacar a pasear a: " << this->nombre << endl;
            }
        }
        void setPaseado(bool _paseado){
            paseado = _paseado;
        }
};

void swp(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x, y;
    x = 10; y = 5;
    swp(&x,&y);
    cout << x << ", " << y << endl;

    Perro p("Firu", 10, true);
    p.setNombre("Panchito");
    p.getNombre();
    p.setEdad(11);
    p.getEdad();
    p.setPaseado(false);
    p.getPaseado();
    
    Persona per("Manu", 27);
    per.mostrarPersona();

    return 0;
}
