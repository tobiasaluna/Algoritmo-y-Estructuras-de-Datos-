#include <iostream>
using namespace std;

class Animal {
    public:
        virtual void hablar(){
            cout << "hablando" << endl;
        }
};

class Perro : public Animal {
    public:
        void hablar() override {
            cout << "Guau" << endl;
        }
};

class Gato : public Animal {
    public:
        void hablar() override {
            cout << "miau" << endl;
        }
};



int main() {
    Animal* p1 = new Perro();
    Animal* g1 = new Gato();

    p1->hablar();
    g1->hablar();

    delete p1;
    delete g1;
    
    return 0;
}
