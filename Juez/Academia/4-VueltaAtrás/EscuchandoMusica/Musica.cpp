#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(n^3) =  O(n) siendo n el número de canciones sobre las que decidir si se ponen en el viaje de ida,
 * en el viaje de vuelta o no se ponen.
 *
 */

struct tCancion {
    int duracion;
    int satisfaccion;
    float densidad;
};

struct tDatos {
    int n;
    int tiempoIda;
    int tiempoVuelta;
    vector<tCancion> canciones;
};

struct tSol {
    int durancionTotal;
    int satisfaccionTotal;
};

bool esValida(const tSol & sol, int t) {
    return sol.durancionTotal <= t;
}

bool esMejorSolucion(const tDatos & datos, const tSol & solActualIda, const tSol & solActualVuelta, const tSol & mejorSolIda, const tSol & mejorSolVuelta) {
    bool mejorSolucion;

    mejorSolucion = solActualIda.durancionTotal == datos.tiempoIda && solActualVuelta.durancionTotal == datos.tiempoVuelta;

    if (mejorSolucion) mejorSolucion = solActualIda.satisfaccionTotal + solActualVuelta.satisfaccionTotal > mejorSolIda.satisfaccionTotal + mejorSolVuelta.satisfaccionTotal;

    return mejorSolucion;
}

void resolver(const tDatos & datos, int k, tSol & solActualIda, tSol & solActualVuelta, tSol & mejorSolIda, tSol & mejorSolVuelta, vector<int> & sol, vector<int> & mejorSol) {
    // Se prueba a poner la cancion k en el viaje de ida
    sol[k] = 1;
    solActualIda.durancionTotal += datos.canciones[k].duracion;
    solActualIda.satisfaccionTotal += datos.canciones[k].satisfaccion;
    if (esValida(solActualIda, datos.tiempoIda)) {
        if (k + 1 == datos.n) {
            if (esMejorSolucion(datos, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta)) {
                mejorSolIda = solActualIda;
                mejorSolVuelta = solActualVuelta;
                mejorSol = sol;
            }
        } else resolver(datos, k + 1, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta, sol, mejorSol);
    }
    solActualIda.satisfaccionTotal -= datos.canciones[k].satisfaccion;
    solActualIda.durancionTotal -= datos.canciones[k].duracion;

    // Se prueba a poner la cancion k en el viaje de vuelta
    sol[k] = 2;
    solActualVuelta.durancionTotal += datos.canciones[k].duracion;
    solActualVuelta.satisfaccionTotal += datos.canciones[k].satisfaccion;
    if (esValida(solActualVuelta, datos.tiempoVuelta)) {
        if (k + 1 == datos.n) {
            if (esMejorSolucion(datos, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta)) {
                mejorSolIda = solActualIda;
                mejorSolVuelta = solActualVuelta;
                mejorSol = sol;
            }
        } else resolver(datos, k + 1, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta, sol, mejorSol);
    }
    solActualVuelta.satisfaccionTotal -= datos.canciones[k].satisfaccion;
    solActualVuelta.durancionTotal -= datos.canciones[k].duracion;

    // Se prueba a no poner la cancion k
    sol[k] = 0;
    if (esValida(solActualVuelta, datos.tiempoVuelta)) {
        if (k + 1 == datos.n) {
            if (esMejorSolucion(datos, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta)) {
                mejorSolIda = solActualIda;
                mejorSolVuelta = solActualVuelta;
                mejorSol = sol;
            }
        } else resolver(datos, k + 1, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta, sol, mejorSol);
    }
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.n >> datos.tiempoIda >> datos.tiempoVuelta;
    if (datos.n == 0 && datos.tiempoIda == 0 && datos.tiempoVuelta == 0) return false;

    datos.canciones = vector<tCancion>(datos.n);
    for (int i = 0; i < datos.n; ++i) {
        cin >> datos.canciones[i].duracion >> datos.canciones[i].satisfaccion;
        datos.canciones[i].densidad = ((float) datos.canciones[i].duracion) / datos.canciones[i].satisfaccion;
    }

    sort(datos.canciones.begin(), datos.canciones.end(), [](tCancion a, tCancion b) {
        return a.densidad < b.densidad;
    });

    tSol solActualIda = {0, 0};
    tSol solActualVuelta = {0, 0};
    tSol mejorSolIda = {0, 0};
    tSol mejorSolVuelta = {0, 0};
    vector<int> sol = vector<int>(datos.n);
    vector<int> mejorSol = vector<int>(datos.n);

    resolver(datos, 0, solActualIda, solActualVuelta, mejorSolIda, mejorSolVuelta, sol, mejorSol);

    int satisfaccionTotal = mejorSolIda.satisfaccionTotal + mejorSolVuelta.satisfaccionTotal;

    if (satisfaccionTotal > 0) {
        cout << satisfaccionTotal << '\n';
        cout << "Canciones Ida: ";
        for (int i = 0; i < datos.n; ++i) {
            if (mejorSol[i] == 1) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        cout << "Canciones Vuelta: ";
        for (int i = 0; i < datos.n; ++i) {
            if (mejorSol[i] == 2) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    } else cout << "Imposible\n";

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