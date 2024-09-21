#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(n) siendo n el número de elementos visibles
 *
 * Justificación del coste:
 *      - Función de recurrencia:
 *          T(n) = c0           si n = 1
 *          T(n) = c1           si elementos en mitad de n es el máximo
 *          T(n) = T(n/2) + n   si n > 1 y el elemento en mitad de n no es el máximo
 *          (Siendo en el número de elementos visibles)
 *          
 *      - Desplegado:
 *          T(n) = T(n/2) + n = T(n/4) + n/2 + n = T(n/8) + n/4 + n/2 + n =
 *          = ... = T(n/2^k) + n
 *          
 *      - Postulado:
 *          n/2^k = 1 -> n = 2^k -> k = log(n)
 *          T(n/2^k) + n = T(1) + n = n
 *
 */

struct tDatos {
    int n;
    vector<int> valores;
    int escalonMasAncho;
};

bool tieneValorMayor(const vector<int> & v, int ini, int fin, int valor) {
    bool mayor = false;
    int i = ini;

    while (i < fin && !mayor) {
        mayor = v[i] > valor;
        i++;
    }

    return mayor;
}

int alturaEscalera(const tDatos & datos, int ini, int fin) {
    if (ini + 1 == fin) return datos.valores[ini];
    else {
        int m = (ini + fin) / 2;
        int posIzq = max(m - datos.escalonMasAncho, ini);
        int posDer = min(m + datos.escalonMasAncho, fin);

        if (tieneValorMayor(datos.valores, posIzq, m, datos.valores[m])) {
            return alturaEscalera(datos, ini, m);
        } else if (tieneValorMayor(datos.valores, m + 1, posDer + 1, datos.valores[m])) {
            return alturaEscalera(datos, m + 1, fin);
        } else return datos.valores[m];
    }
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.n >> datos.escalonMasAncho;
    if (datos.n == -1) return false;

    datos.valores = vector<int>(datos.n);
    for (int i = 0; i < datos.n; ++i) {
        cin >> datos.valores[i];
    }

    cout << alturaEscalera(datos, 0, datos.n) << '\n';

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