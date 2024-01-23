#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n^3) =  O(n) siendo n la altura de la torre
 * 
 * Justificación del coste: por cada elemento del vector solución (pieza de la torre) se prueba a poner las 3
 * posibles piezas (azul, rojo, verde).
 *
 */

enum tPieza {
    AZUL,
    ROJA,
    VERDE
};

struct tDatos {
    int n;
    int a;
    int r;
    int v;
};

void mostrarSol(const vector<tPieza> & sol) {
    for (int i = 0; i < sol.size(); ++i) {
        switch (sol[i]) {
            case AZUL:
                cout << "azul ";
                break;
            case ROJA:
                cout << "rojo ";
                break;
            case VERDE:
                cout << "verde ";
                break;
        }
    }

    cout << '\n';
}

bool esValida(const tDatos & datos, const vector<tPieza> & sol, int k, const vector<int> & marcas) {
    if (sol[k - 1] == VERDE && sol[k] == VERDE) return false;
    if (marcas[0] < marcas[2]) return false;
    if (sol[k] == AZUL && marcas[0] > datos.a) return false;
    if (sol[k] == ROJA && marcas[1] > datos.r) return false;
    if (sol[k] == VERDE && marcas[2] > datos.v) return false;

    return true;
}

int resolver(const tDatos & datos, vector<tPieza> & sol, int k, vector<int> & marcas) {
    int soluciones = 0;

    for (int i = 0; i < 3; ++i) {
        sol[k] = (tPieza) i;
        ++marcas[i];

        if (esValida(datos, sol, k, marcas)) {
            if (k + 1 == datos.n) {
                if (marcas[1] > marcas[0] + marcas[2]) {
                    ++soluciones;
                    mostrarSol(sol);
                }
            } else soluciones += resolver(datos, sol, k + 1, marcas);
        }

        --marcas[i];
    }

    return soluciones;
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.n >> datos.a >> datos.r >> datos.v;
    if (datos.n == 0 && datos.a == 0 && datos.r == 0 && datos.v == 0) return false;

    vector<tPieza> sol(datos.n);
    sol[0] = ROJA;
    vector<int> marcas(3, 0);
    marcas[1] = 1;
    int nSoluciones = resolver(datos, sol, 1, marcas);
    if (nSoluciones == 0) cout << "SIN SOLUCION\n";

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