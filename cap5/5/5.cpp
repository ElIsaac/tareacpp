#include <iostream>
using namespace std;

class Pastelero {
public:
    Pastelero(int cantidadPasteles, int buenasResenas) 
        : cantidadPasteles(cantidadPasteles), buenasResenas(buenasResenas) {
            
        }
    friend class Vendedor;
    int getCantidadPasteles() {
        return cantidadPasteles;
    }
    int buenasResenas;
private:
    int cantidadPasteles;
};

class Vendedor {
public:
    Vendedor(Pastelero& pastelero) : pastelero(pastelero) {}
    void vender() {
        pastelero.cantidadPasteles--;
    }
private:
    Pastelero& pastelero;
};

class Comprador {
public:
    Comprador(Pastelero& pastelero) : pastelero(pastelero) {}
    void satisfecho() {
        pastelero.buenasResenas++;
    }
private:
    Pastelero& pastelero;
};

int main() {
    Pastelero bolo(10, 0);
    Vendedor fredy(bolo);
    Comprador lolo(bolo);

    cout << bolo.getCantidadPasteles() << " " << bolo.buenasResenas << endl;

    fredy.vender();
    lolo.satisfecho();

    cout << bolo.getCantidadPasteles() << " " << bolo.buenasResenas << endl;

    return 0;
}
