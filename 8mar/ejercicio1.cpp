#include <iostream>
using namespace std;

class Pastel {
  public:
    // Atributos públicos
    string sabor;
    int porciones;

    // Constructor
    Pastel(string sabor, int porciones) {
      this->sabor = sabor;
      this->porciones = porciones;
    }

    // Método público
    void mostrarInfo() {
      cout << "Este pastel es de sabor " << sabor << " y tiene " << porciones << " porciones." << endl;
    }

  private:
    // Atributo privado
    float precio = 25.99;

    // Método privado
    void imprimirPrecio() {
      cout << "El precio de este pastel es: $" << precio << endl;
    }

  protected:
    // Atributo protegido
    string ingredientes = "Harina, azúcar, huevos, mantequilla";

};

class Dona: public Pastel{
	public:
		Dona(string sabor) : Pastel(sabor, 1){}
		void mostrarIngredientes(){
			cout << "los ingredientes de la dona son: " <<ingredientes<<", "<<sabor<<endl;
		}
};

int main() {
  // Crear objeto de la clase Pastel
  Pastel pastelDeChocolate("Chocolate", 12);

  // Acceder a los atributos públicos
  cout << "Este pastel es de sabor " << pastelDeChocolate.sabor << " y tiene " << pastelDeChocolate.porciones << " porciones." << endl;

  // Llamar al método público e imprimir exactamente lo de arriba
  pastelDeChocolate.mostrarInfo();



  Dona DonaAzucar("azucar");
  DonaAzucar.mostrarIngredientes(); // Esto funciona porque estamos dentro de la clase hija
}

