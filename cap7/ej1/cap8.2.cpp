#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Leer
{
private:
    string contenido = "";

public:
    Leer() {}
    Leer(string& archivo)
    {
        string linea;
        ifstream lectura(archivo);
        if (lectura.is_open()) // Verifica si el archivo se abre con éxito
        {
            while (getline(lectura, linea)) // Lee el archivo línea por línea
            {
                contenido += linea + '\n'; // Concatena cada línea leída a la cadena 'contenido'
            }
            lectura.close(); // Cierra el archivo
        }
        else
        {
            cout << "archivo inexistente\n"; // Muestra un mensaje de error en la consola
            contenido = "";
        }
    }
    string getContenido()
    {
        return contenido;
    }

};

int main()
{
    string x="";
    cout << "ingrese el nombre de archivo: ejemplo.txt\n";
    cin >> x;
    Leer lector(x);
    cout << lector.getContenido();
    return 0;
}
