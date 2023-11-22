//DANIELA VALENTINA VALERA FUENTES
//F94

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
 *          T(n) = c1 + 2T(n/2)     si n > 1
 *          Siendo n el número de elementos visibles
 *              ** 2T(n/2) : xq hay 2 llamadas recursivas donde el seg visible de cada una de ellas se reduce a la mitad
 *
 *      Por lo tanto, el coste de la solución es n, orden lineal.
 *      (Todos los elementos se visitan una vez).
 * 
 *
 */

bool suficientementeDisperso(const vector<int>& v, int k, int ini, int fin) {
    if (ini + 1 == fin) return true; //caso base: cuando tengamos un único elemento
    else { //caso recursivo
        int mitad = (ini + fin) / 2;
        
        bool izq = suficientementeDisperso(v, k, ini, mitad);
        bool der = suficientementeDisperso(v, k, mitad, fin);

        return izq && der && abs(v[ini] - v[fin - 1]) >= k;
    }
}

bool resuelveCaso() {
    int n, k;
    cin >> n >> k;
    if (!cin) return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (suficientementeDisperso(v, k, 0, n)) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos4.1.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}