#include <iostream>

using namespace std;

void imprimirValores(int a, int /*b*/)
{
    cout << "a = " << a << endl;
    // cout << "b = " << b << endl;  //cambios al main
}
int main()
{
    int _a = 10;
    int _b = 20;

    imprimirValores(_a, _b);

    return 0;
}
