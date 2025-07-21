/**
 * Escribid el nombre y usuario del juez los miembros de la pareja:
 * Nombre y usuario:Daniela Valentina Valera Fuentes FAL-E65
 * Nombre y usuario:David Dominguez Gutierrez FAL-E20
 *
 * Explica brevemente el algoritmo:
 *
 *
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// No olvides escribir la especificación y justificar adecuadamente el coste
//Predicados
//1. predicado llano_acotado (w: v<int>, p:int, q:int)
// requieres 0<=p<q<|w|
//{ forall i:: p<=i<q==>w[i]==w[p] &&w[q]>w[p]
//2. Funcion que utiliza el predicado anterior
//requieres |v|>0 && c>=1
// result == (exits p::0 <= p <= |v|-c-1 && llano_acotado(v,p,p+c)
//4. El coste asintotico de este algoritmo O(n), siendo n el tamaño del vector.

// Implementa la función pedida


bool terreno_llano(const vector<int>& v, int p )
{
    bool encontrado = false;
    int i = 1;
    int j = 1;
    while (!encontrado && i < v.size())
    {
        if (j < p)
        {
            if (v[i] == v[i - 1])
            {
                j++;
            }
            else {
                j = 1;
            }
        }
        else
        {
            if (v[i] > v[i -1]) {
                encontrado = true;

            }
            else if (v[i] == v[i - 1])
            {
                j++;
            }
            else {
                j = 1;
            }
        }

        i++;
    }
    
    return encontrado;
   
}





bool resuelveCaso() {
    // leer los datos de la entrada
    int N, C; //número de datos, número de castores
    cin >> N >> C;
    if (N == 0 && C == 0)
        return false;
    vector<int> valores(N);
    for (int i = 0; i < N; ++i) {
        int e;  cin >> e;
        valores[i] = e;
    }

    //Llama a tu función
    if (terreno_llano(valores,C))
    {
        cout << "SI" << endl;
   }
    else
    {
        cout << "NO" << endl;
    }

    // escribe el resultado


    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt"); //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}