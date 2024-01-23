#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(n^n) =  O(n) siendo n el número de funcionarios y trabajos
 *
 * Justificación del coste: por cada funcionario se prueba a asignarle cada uno de los n trabajos
 *
 */

struct tDatos {
    int n;
    vector<vector<int>> tiempos;
    vector<int> estimacion;
};

void resolver(const tDatos & datos, int k, int & tiempoMejor, int tiempoActual, vector<int> & sol, vector<int> & solMejor, vector<bool> marcas) {
    for (int i = 0; i < datos.n; ++i) {
        if (!marcas[i]) {
            tiempoActual += datos.tiempos[k][i];
            sol[k] = i;
            marcas[i] = true;

            if (k + 1 == datos.n) {
                if (tiempoActual < tiempoMejor) {
                    tiempoMejor = tiempoActual;
                    solMejor = sol;
                }
            } else if (tiempoActual + datos.estimacion[k + 1] < tiempoMejor) resolver(datos, k + 1, tiempoMejor, tiempoActual, sol, solMejor, marcas);

            marcas[i] = false;
            tiempoActual -= datos.tiempos[k][i];
        }
    }
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.n;

    if (datos.n == 0) return false;
    datos.tiempos = vector<vector<int>>(datos.n, vector<int>(datos.n));
    datos.estimacion = vector<int>(datos.n);

    for (int i = 0; i < datos.n; ++i) {
        datos.estimacion[i] = 10000;
        for (int j = 0; j < datos.n; ++j) {
            cin >> datos.tiempos[i][j];
            datos.estimacion[i] = min(datos.estimacion[i], datos.tiempos[i][j]);
        }
    }

    for (int i = datos.n - 1; i > 0; --i) {
        datos.estimacion[i - 1] += datos.estimacion[i];
    }

    vector<int> sol(datos.n);
    vector<int> solMejor(datos.n);
    vector<bool> marcas(datos.n, false);
    int tiempoMejor = 0;
    for (int i = 0; i < datos.n; ++i) {
        tiempoMejor += datos.tiempos[i][i];
    }

    resolver(datos, 0, tiempoMejor, 0, sol, solMejor, marcas);

    cout << tiempoMejor << '\n';
    for (int i = 0; i < datos.n; ++i) {
        cout << solMejor[i] << ' ';
    }
    cout << '\n';

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