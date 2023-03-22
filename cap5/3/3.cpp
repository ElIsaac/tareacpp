#include <iostream>
using namespace std;

class Borracho {
private:
    string nombre;
    int caguamas;
public:
    Borracho(string nombre, int caguamas) {
        this->nombre = nombre;
        this->caguamas = caguamas;
    }
    friend void robarGuamas(Borracho& b);
    
};


void robarGuamas(Borracho& b) {
    b.caguamas--;
    cout << "quedan " << b.caguamas << " caguamas." << endl;
}

int main() {
    Borracho juan("Juan", 25);
    robarGuamas(juan); // Llamada a la función robarGuamas
    return 0;
}
