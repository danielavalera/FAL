#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n) siendo n el número de elementos visibles
 *
 * Especificación:
 *
 *      -Ecuacion de recurrencia:
 *          T(n) = c0               si n = 1
 *          T(n) = c1 + 2T(n/2)      si n > 1
 *          Siendo n el número de elementos visibles
 *
 *          Por ello, el coste es lineal respecto al número de elementos visibles del vector.
 *          (Cada elemento se visita una vez).
 *
 */

struct tJugador {
    string nombre;
    int canicas;
};

tJugador resolver(const vector<tJugador>& v, int ini, int fin) {
    if (ini + 1 == fin) return v[ini];
    else {
        int m = (ini + fin) / 2;
        tJugador izq = resolver(v, ini, m);
        tJugador der = resolver(v, m, fin);

        tJugador sol;
        if (izq.canicas >= der.canicas) {
            sol.nombre = izq.nombre;
            sol.canicas = izq.canicas + der.canicas / 2;
        }
        else {
            sol.nombre = der.nombre;
            sol.canicas = der.canicas + izq.canicas / 2;
        }
        return sol;
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin) return false;

    vector<tJugador> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].nombre >> v[i].canicas;
    }

    tJugador sol = resolver(v, 0, n);
    cout << sol.nombre << ' ' << sol.canicas << '\n';

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("canicas.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
