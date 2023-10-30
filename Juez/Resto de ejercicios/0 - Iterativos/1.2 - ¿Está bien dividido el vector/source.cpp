/*
*  AUTOR: Daniela Valentina Valera Fuentes (F94)
* 
*
*
* Precondición: El vector v no debe estar vacio
*               posVector debe estar dentro de los límites de tamVector (0 <= posVector < tamVector)
* 
* Postcondición:
* 
* Invariante: 
* 
* Función de cota:
* 
* Coste: Hemos conseguido un coste lineal respecto al tamanno del vector (O(n)).
*/



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits> //necesitamos esta libreria para INT_MAX
using namespace std;



// función que resuelve el problema
bool resolver(vector<int>& v, int posVector, int tamVector) {
    int numMax = v[0], numMin = INT_MAX;

    for (int i = 1; i <= posVector; i++) {
        if (numMax < v[i]) {
            numMax = v[i];
        }
    }

    for (int i = posVector +1; i < tamVector; i++) {
        if (numMin > v[i]) {
            numMin = v[i];
        }
    }

    return numMax < numMin;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int tamVector, posVector;
    // leer los datos de la entrada
    cin >> tamVector >> posVector;

    vector<int> v(tamVector); //declaras un vector de enteros con tamanno tamVector.
    for (int i = 0; i < tamVector; i++) {
        cin >> v[i]; //rellenar el vector
    }

    bool sol = resolver(v, posVector, tamVector);

    // escribir sol
    if(sol) cout << "SI" << endl;
    else cout << "NO" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("datos1.2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}