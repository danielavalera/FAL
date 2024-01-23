#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(n)
 *
 * Justificación del coste:
 *      -Función de recurrencia:
 *          T(n) = c0               si n = 1
 *          T(n) = T(n - 1) + c1    si n > 1
 *
 *      -Desplegado:
 *          T(n) = T(n - 1) + c1 = T(n - 2) + c1 + c1 = T(n-3) + 3c1 = ...
 *          = ... = T(n - k) + k
 *
 *      -Postulado;
 *          n - k = 1 -> k = n - 1
 *          T(n - (n - 1)) + n - 1 = T(1) + n - 1 = n -> O(n)
 *
 */

struct tSol {
    bool cumple;
    int suma;
    int cifras;
};

tSol sumDivisible(int n) {
    if (n < 10) return { true, n, 1 };
    else {
        tSol sol = sumDivisible(n / 10);
        sol.suma += n % 10;
        sol.cifras++;
        sol.cumple = sol.cumple && sol.suma % sol.cifras == 0;
        return sol;
    }
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;

    tSol sol = sumDivisible(n);
    if (sol.cumple) cout << "SI\n";
    else cout << "NO\n";

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