#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(nEscalones ^ nColores) siendo nEscalones el número de escalones y nColores el número de colores
 *
 * Justificación del coste: esto es así porque se prueba a poner cada color en cada uno de los escalones.
 *
 */

struct tColor {
    int cantidad;
    int precio;
};

struct tDatos {
    int nEscalones;
    int nColores;
    vector<int> escalones;
    vector<tColor> colores;
};

struct tSol {
    int coste;
    vector<int> asignacionColores;
};

bool esValida(const tDatos & datos, int k, int i, const tSol & solActual) {
    return datos.colores[i].cantidad >= 0 && (k == 0 || solActual.asignacionColores[k - 1] != solActual.asignacionColores[k]);
}

void resolver(tDatos & datos, int k, tSol & solMejor, tSol & solActual) {
    for (int i = 0; i < datos.nColores; ++i) {
        datos.colores[i].cantidad -= datos.escalones[k];
        solActual.coste += datos.colores[i].precio * datos.escalones[k];
        solActual.asignacionColores[k] = i;

        if (esValida(datos, k, i, solActual)) {
            if (k + 1 == datos.nEscalones) {
                if (solActual.coste < solMejor.coste || solMejor.coste == 0) {
                    solMejor = solActual;
                }
            } else resolver(datos, k + 1, solMejor, solActual);
        }

        solActual.coste -= datos.colores[i].precio * datos.escalones[k];
        datos.colores[i].cantidad += datos.escalones[k];
    }
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.nEscalones >> datos.nColores;
    if (datos.nEscalones == -1) return false;

    datos.escalones = vector<int>(datos.nEscalones);
    for (int i = 0; i < datos.nEscalones; ++i) {
        cin >> datos.escalones[i];
    }

    datos.colores = vector<tColor>(datos.nColores);
    for (int i = 0; i < datos.nColores; ++i) {
        cin >> datos.colores[i].cantidad;
        cin >> datos.colores[i].precio;
    }

    tSol solActual = { 0, vector<int>(datos.nEscalones) };
    tSol solMejor = { 0, vector<int>(datos.nEscalones) };

    resolver(datos, 0, solMejor, solActual);

    if (solMejor.coste == 0) cout << "NO\n";
    else {
        cout << solMejor.coste << '\n';
        for (int i = 0; i < datos.nEscalones; ++i) {
            cout << solMejor.asignacionColores[i] <<  ' ';
        }
        cout << '\n';
    }

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