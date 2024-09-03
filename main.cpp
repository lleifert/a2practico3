#include <cassert>
#include <iostream>
#include "Table.h"
#include "HashCerrado.cpp"
using namespace std;

int hash1(string key) {
    int h = 0;
    for (int i=0; i<key.length(); i++)
        h = h + key[i];
    return h;
}

int main()
{
    cout << "Practico 3" << endl;

    int N;           // N es la cantidad de palabras a leer, viene en la primera linea del archivo de prueba
    string palabra;  // Es la key leida del archivo de prueba
    int cantPalabrasRepetidas = 0;  // Cantidad final de palabras repetidas
    cin >> N;        // Leo la primera linea del archivo

    cout << "Son " << N << " palabras, ";

    Table<string, int> * tabla = new HashCerrado<string, int>(N, hash1);

    for (int i=0; i<N; i++)
    {
        cin >> palabra;
        tabla->insert(palabra, 0);
    }

    // Recorro la tabla para identificar los repetidos 2 veces O(n)?
    for (int i=0; i<N; i++) {
        if (tabla->getBucketNumRepeticiones(i) == 2)
        {
            cantPalabrasRepetidas = cantPalabrasRepetidas + 1;
        }
    }
    
    if (cantPalabrasRepetidas == 1)
    {
        cout << cantPalabrasRepetidas << " repetida." << endl;
    }
    else
    {
        cout << cantPalabrasRepetidas << " repetidas." << endl;
    }
    

    return 0;
}