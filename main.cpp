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

int hash2(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++)
        h = h + key[i] * (i + 1);
    return h;
}

int hash3(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++)
        h = 31 * h + int(key[i]);
    return h;
}

int main()
{
    cout << "Practico 3" << endl;

    int N;                           // N es la cantidad de palabras a leer, viene en la primera linea
    string palabra;                  // Es la key leida del archivo de prueba
    int cantPalabrasRepetidas = 0;   // Cantidad final de palabras repetidas
    cin >> N;                        // Leo la primera linea del archivo

    cout << "Son " << N << " palabras, ";

    Table<string, int> * tabla = new HashCerrado<string, int>(N, hash3);

    for (int i=0; i<N; i++)
    {
        cin >> palabra;
        tabla->insert(palabra, 0);
    }
    
    /*
    Recorro la tabla e identifico los repetidos 2 veces.
    Los sumo a la variable cantPalabrasRepetidas.
    Es O(N) caso promedio en tiempo de ejecución?.
    */
    for (int i=0; i<N; i++)
    {
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