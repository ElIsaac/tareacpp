//: C06:Stack3Test.cpp
//{L} Stack3
//{T} Stack3Test.cpp
// Constructors/destructors
#include "Stack3.h"
#include "../require.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
    requireArgs(argc, 1); // File name is argument
    ifstream in(argv[1]);
    assure(in, argv[1]);
    Stack textlines;
    string line;
    
    int size = 0;
    int cont=0;
    // Read file and store lines in the stack:
    while (getline(in, line))
        size+=1;
        textlines.push(new string(line));
    // Pop the lines from the stack and print them:
    string* arr[size];
    string *s;
    while ((s = (string *)textlines.pop()) != 0)
    {
        cont += 1;
        arr[cont]= s;
        
        delete s;
    }
    for(int i=0;i<=cont;i++){
        cout << *arr[i] << endl;
    }
} ///:~