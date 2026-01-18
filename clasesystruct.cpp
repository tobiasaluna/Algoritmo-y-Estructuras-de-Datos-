#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct infoPersona {
    int edad;
    int DNI;
};

class Persona{
    private:
        string nombre;
        infoPersona datos;
    public:
        Persona(string n, infoPersona d) : nombre(n), datos(d) {
            datos.edad = d.edad;
            datos.DNI = d.DNI;
        }
        void setNombre(string n){
            nombre = n;
        }
        void setEdad(int e) {
            datos.edad = e;
        }
        void setDNI(int dni){
            datos.DNI = dni;
        }

        string getNombre() {
            return nombre;
        }
        int getEdad(){
            return datos.edad;
        }
        int getDNI(){
            return datos.DNI;
        }
        
        virtual void hablar() {
            cout << "Estoy hablando" << endl;
        }

        void mostrarPersona(){
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << datos.edad << endl;
            cout << "DNI: " << datos.DNI << endl;
        }
};

class Perro{
    private:
        string nombre;
        int edad;
        bool paseado;
    public:
        Perro(string n, int e, bool p) : nombre(n), edad(e), paseado(p) {}

        void setPaseado(bool p){
            paseado = p;
        }

        void mostrarPerro() {
            cout << "Nombre: " << nombre << endl;
            cout << "Edad: " << edad << endl;
            cout << "Paseado: " << paseado << endl;
        }
};

class Empleado : public Persona {
    private:
        string puesto;
        int codigoDeEmpleado;
        double sueldo;
    public:
        Empleado(const Persona &per, string p, int cod, double s) 
        : Persona(per), puesto(p), codigoDeEmpleado(cod), sueldo(s) {}
        
        void setSueldo (int s) {
            sueldo = s;
        }
        
        void hablar() override {
            cout << "soy empleado" << endl;
        }

        void mostrarEmpl(){
            mostrarPersona();
            cout << "Puesto: " << puesto << endl;
            cout << "Codigo de empleado: " << codigoDeEmpleado << endl;
            cout << fixed << setprecision(2);
            cout << "Sueldo: $" << sueldo << endl;
            hablar();
        }   
};

class Jugador : public Persona {
    private:
        string dorsal;
        int tiro;
        int ritmo;
        int defensa;
    public:
        Jugador(const Persona& per,string num, int t, int r, int d) 
        : Persona(per), dorsal(num), tiro(t), ritmo(r), defensa(d) {}
        
        void setDorsal(string dor) {
            dorsal = dor;
        }
        
        void hablar() override {
            cout << "soy jugador" << endl;
        }

        void mostrarJugador() {
            mostrarPersona();
            cout << "Jugador numero: " << dorsal << endl;
            cout << "Tiro: " << tiro << endl;
            cout << "Ritmo: " << ritmo << endl;
            cout << "Defensa: " << defensa << endl;
            hablar();
        }
};

int main() {
    Persona p1("Tobias A. Luna", {27, 41520621});
    Perro perro1("Firu", 5, false);

    Empleado crack(p1, "ingeniero", 10, 1200000.00);
    Jugador eldiez(p1, "32", 80, 83, 78);
    
    perro1.mostrarPerro();
    
    crack.mostrarEmpl();

    cout << "---------------------" << endl;

    eldiez.mostrarJugador();
    
    

    return 0;
}
