#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(k^10) -> O(k) siendo k el número de cifras necesarias
 *
 * Justificación del coste: el algoritmo tiene un coste lineal puesto que para formar un número
 * de k cifras, para cada cifra, se prueba con los valores 0-9 y el resto, son valores constantes
 *
 */

bool esValida(int n, int k) {
    return n % k == 0;
}

void resolver(long long int d, int n, int cifras, int k, int & sumDivisibles) {
    d *= 10;
    for (int i = 0; i < 10; ++i) {
        d += i;
        n += i;

        if (esValida(n, k + 1)) {
            if (k + 1 == cifras) {
                cout << d << '\n';
                sumDivisibles++;
            } else resolver(d, n, cifras, k + 1, sumDivisibles);
        }

        d -= i;
        n -= i;
    }
}

bool resuelveCaso() {
    int d, cifras;
    cin >> d >> cifras;
    if (d == 0) return false;

    int sumDivisibles = 0;
    resolver(d, d, cifras, 1, sumDivisibles);

    cout << sumDivisibles << "\n\n\n";

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