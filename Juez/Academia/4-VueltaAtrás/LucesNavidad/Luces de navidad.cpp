#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(l^b) siendo l la longitud de la tira y b el número de bombillas
 *
 * Justificación del coste: dada una longitud l, podemos combinar todas las bombillas b de cualquier manera
 * para conseguir esa longitud y cumplir las restricciones. Para cada hueco de la tira, se prueba a poner
 * cada tipo de bombilla.
 *
 */

struct tDatos {
    int longitud;
    int bombillas;
    vector<int> consumos;
    int consumoMaximo;
};

struct tSol {
    int consumoActual;
    vector<int> sol;
};

bool esValida(const tDatos & datos, int k, const tSol & sol, vector<int> & marcas) {
    if (sol.consumoActual > datos.consumoMaximo) return false;
    if ((k >= 2) && sol.sol[k] == sol.sol[k - 1] && sol.sol[k - 1] == sol.sol[k - 2]) return false;
    if (marcas[sol.sol[k]] > (k + 1) - marcas[sol.sol[k]] + 1) return false;
    return true;
}

int resolver(const tDatos & datos, int k, tSol & sol, vector<int> & marcas) {
    int soluciones = 0;

    for (int i = 0; i < datos.bombillas; ++i) {
        sol.sol[k] = i;
        sol.consumoActual += datos.consumos[i];
        marcas[i]++;

        if (esValida(datos, k, sol, marcas)) {
            if (k + 1 == datos.longitud) {
                soluciones++;

                for (int j = 0; j < datos.longitud; ++j) {
                    cout << sol.sol[j] << ' ';
                }
                cout << '\n';
            } else soluciones += resolver(datos, k + 1, sol, marcas);
        }

        marcas[i]--;
        sol.consumoActual -= datos.consumos[i];
    }

    return soluciones;
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.longitud >> datos.bombillas >> datos.consumoMaximo;
    if (datos.longitud == 0) return false;

    int aux;
    for (int i = 0; i < datos.bombillas; ++i) {
        cin >> aux;
        datos.consumos.push_back(aux);
    }

    tSol sol;
    sol.sol = vector<int>(datos.longitud);
    sol.consumoActual = 0;
    vector<int> marcas = vector<int>(datos.bombillas, 0);

    cout << '\n' << resolver(datos, 0, sol, marcas) << '\n' << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}