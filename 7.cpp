#include <iostream>
using namespace std;

class Gallina;

class Huevo {
public:
    Huevo(bool vivo){
        this->vivo=vivo;
    }
    void mostrar() {
        cout << "Esta vivo: " << vivo << endl;
    }
    bool getEstadoHuevo(){
        return vivo;
    }
    friend class Gallina;
private:
    bool vivo;
};

class Nido {
public:
    Nido(int huevos){
        this->huevos=huevos;
    }
    void mostrar() {
        cout << "Este es un nido con " << huevos << " huevos" << endl;
    }
    int getHuevos(){
        return huevos;
    }
    friend class Gallina;
private:
    int huevos;
};

class Gallina {
public:
    Gallina(){}
    void alternarVida(Huevo& huevo) {
        huevo.vivo = !huevo.vivo;
    }
    void poner(Nido& nido) {
        nido.huevos++;
    }
};


string vivo_o_muerto(bool vivo){
    if(vivo){
        return "vivo";
    }else{
        return "muerto";
    }
}

int main() {
    Huevo huevo(true);
    Nido nido(2);
    Gallina gallina;

    cout << "El huevo esta:  " << vivo_o_muerto(huevo.getEstadoHuevo()) << endl;
    cout << "Este es un nido con " << nido.getHuevos() << " huevos" << endl;

    gallina.poner(nido);
    gallina.alternarVida(huevo);

    cout << "El huevo esta:  " << vivo_o_muerto(huevo.getEstadoHuevo()) << endl;
    cout << "Este es un nido con " << nido.getHuevos() << " huevos" << endl;

    return 0;
}
