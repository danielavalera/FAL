/*
 * Plantilla para la práctica 4
 * Escribid vuestro nombre y usuarios:
 *   - CRISTIAN GARCIA MORUNO F42
 *   - DANIELA VALENTINA VALERA FUENTES F94
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

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

void mostrarSol(const vector<tPieza>& sol) {
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

/*
 * Explica el espacio de búsqueda, solución y marcadores utilizados
 * 
 * El marcador marcas es el indicativo del número de piezas que hay de cada color. Se va actualizando según va cambiando el vector de soluciones.
 * marcador: Para todo i : 0 <= i < numero_colores : marcador[i] = numero_piezas del color i
 */
bool esValida(const tDatos& datos, const vector<tPieza>& sol, int k, const vector<int>& marcas) {
    if (sol[k - 1] == VERDE && sol[k] == VERDE) return false;
    if (marcas[0] < marcas[2]) return false;
    if (sol[k] == AZUL && marcas[0] > datos.a) return false;
    if (sol[k] == ROJA && marcas[1] > datos.r) return false;
    if (sol[k] == VERDE && marcas[2] > datos.v) return false;

    return true;
}

int resolver(const tDatos& datos, vector<tPieza>& sol, int k, vector<int>& marcas) {
    int soluciones = 0;

    for (int i = 0; i < 3; ++i) {
        sol[k] = (tPieza)i;
        ++marcas[i];

        if (esValida(datos, sol, k, marcas)) {
            if (k + 1 == datos.n) {
                if (marcas[1] > marcas[0] + marcas[2]) {
                    ++soluciones;
                    mostrarSol(sol);
                }
            }
            else soluciones += resolver(datos, sol, k + 1, marcas);
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

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}