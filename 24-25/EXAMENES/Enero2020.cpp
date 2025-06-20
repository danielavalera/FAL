﻿// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v) {
    int resetVentana = 0, maxi=0;
    for (int i = 0; i < v.size(); i++){
        if(i>=2 && v[i-2] < v[i-1] && v[i-1] < v[i])
            resetVentana = i - 1;
        maxi = max(maxi,i - resetVentana+1);
    }
    return maxi;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, elem; cin >> tam;
    vector<int> v;
    for (int i = 0; i < tam; i++)
    {
        cin >> elem;
        v.push_back(elem);
    }

    cout << resolver(v) << "\n";
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}