
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;



int main()
{

    // Inicializar la semilla para generar números aleatorios
    srand(time(NULL));
    // Generar un número aleatorio entre 1 y 20
    int aleatorio_10_50 = 10 + rand() % 50;


    int* arr = new int[aleatorio_10_50];
    int busqueda = 0;
    int aleatorio_1_20;
    vector<int*> posiciones;


    cout << aleatorio_10_50 << endl;


    for (int i = 0; i < aleatorio_10_50; i++) {
        aleatorio_1_20 = 1 + rand() % 20;
        arr[i] = aleatorio_1_20;
    }


    int* arregloPuntero = arr;
    for (int i = 0; i < aleatorio_10_50; i++) {
        cout << i << ".- " << arregloPuntero << ": ";
        cout << *arregloPuntero << endl;
        arregloPuntero++;
    }

    do {
        cout << "Ingrese el número a buscar (entre 1 y 20): ";
        cin >> busqueda;
    } while (busqueda < 1 || busqueda > 20);


    arregloPuntero = arr;
    int acumulador = 0;
    for (int i = 0; i < aleatorio_10_50; i++) {
        if (busqueda == *arregloPuntero) {
            acumulador++;
            posiciones.push_back(arregloPuntero);
        }
        else {
        }
        arregloPuntero++;
    }


    if (acumulador > 0) {
        cout << "el numero" << busqueda << " SI se encontro" << endl;
        for (int i = 0; i < posiciones.size(); i++) {
            cout << " la(s) posiciones de mempria son: " <<endl<< posiciones[i] << endl;
        }
    }
    else {
        cout << "el numero" << busqueda << " NO se encontro" << endl;
    }


    arregloPuntero = arr;
    int suma = 0;
    for (int i = 0; i < aleatorio_10_50; i++) {
        suma += *arregloPuntero;
    }


    cout << "la suma de los " << aleatorio_10_50 << " elementos es: " << suma << endl;
}


