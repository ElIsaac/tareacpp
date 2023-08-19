//isaac ramirez velez y andrez almanza quezada

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main()
{
    int N, M, multi, busqueda;
    vector<int *> posiciones;
    cout << "Ingrese la cantidad de filas: ";
    cin >> N;

    cout << "Ingrese la cantidad de columnas: ";
    cin >> M;

    // Crear un arreglo bidimensional utilizando asignación dinámica de memoria
    // arreglo de punteros
    int **arreglo = new int *[N]; // Crear un puntero a puntero para las filas
    int **transpuesta = new int *[M];

    // Asignar memoria para cada fila individual
    // asignar un puntero a arreglo entero en cada fila*
    for (int i = 0; i < N; ++i)
    {
        arreglo[i] = new int[M]; // Asignar memoria para la fila 'i'
    }
    for (int i = 0; i < M; ++i)
    {
        transpuesta[i] = new int[N];
    }
    // Inicializar la semilla para generar números aleatorios
    srand(time(NULL));

    // Llenar el arreglo con números aleatorios en el rango de 10 a 50
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            arreglo[i][j] = 10 + rand() % 50; // Generar número aleatorio en el rango [10, 50]
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            transpuesta[j][i] = arreglo[i][j]; // Generar número aleatorio en el rango [10, 50]
        }
    }

    // Imprimir los valores del arreglo
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << *(*(arreglo + i) + j) << " ";
        }
        cout << endl;
    }

    cout << "Ingrese la cantidad que va a multiplicar a la matriz: ";
    cin >> multi;

    int **resultado = arreglo;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            *(*(resultado + i) + j) *= multi;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << *(*(resultado + i) + j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            transpuesta[j][i] = resultado[i][j];
        }
    }
    cout << "la matriz transpuesta es: " << endl;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << *(*(transpuesta + i) + j) << " ";
        }
        cout << endl;
    }

    do {
        cout << "Ingrese el número a buscar en la matriz 2 (entre "<<1*multi <<" y "<<50*multi <<"):  ";
        cin >> busqueda;
    } while (busqueda < 1*multi || busqueda > 50*multi);

    int acumulador = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {

            if (busqueda == *(*(resultado + i) + j))
            {
                acumulador++;
                posiciones.push_back(&resultado[i][j]);
            }
        }
    }

    if (acumulador > 0)
    {
        cout << "el numero: " << busqueda << " SI se encontro" << endl;
        cout << " la(s) posiciones de memoria son: " << endl;
        for (int i = 0; i < posiciones.size(); i++)
        {
            cout << posiciones[i] << endl;
        }
    }
    else
    {
        cout << "el numero" << busqueda << " NO se encontro" << endl;
    }

    // Liberar la memoria asignada para el arreglo
    for (int i = 0; i < N; ++i)
    {
        delete[] arreglo[i]; // Liberar memoria de cada fila
    }
    delete[] arreglo; // Liberar memoria del arreglo de punteros

    return 0;
}