﻿// Nombre del alumno .....
// Usuario del Juez ......
using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(vector<int> const& v, int const& k) {
    int count = -1, cantidad = 0;
    for (int i = 0; i < k-2; i++)
    {
        if (v[i] < v[i + 1] && v[i + 1] < v[i + 2]) {
            count = i;
        }
        
    }

    if (count == -1)
        cantidad++;

    for (int i = k+1; i <= v.size(); i++)
    {
        if (v[i-3] < v[i -2] && v[i -2] < v[i -1]) {
            count = i-3;
        }
        if (count < (i - k)) {
            cantidad++;
        }
    }

    return cantidad;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    int k, elem;
    vector<int> v;
    if (n == 0)
        return false;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        v.push_back(elem);
    }
    
    cout << resolver(v, k) << "\n";

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
