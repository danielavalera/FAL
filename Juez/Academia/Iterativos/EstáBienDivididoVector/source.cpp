#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n)
 * Justificación del coste: el coste de la función resolver es lineal siendo n el
 * número de elementos del vector. Esto es así porque todas las operaciones tienen
 * un coste constante y entre ambos bucles se ejecutan n veces.
 *
 * Especificación:
 *      P:{1 <= v.size() <= 10000 ^ 0 <= p < v.size()}
 *      bool resolver(vector<int> & v, int p) return bienDividido
 *      Q:{
 *          bienDividido es
 *          true si max(v, 0, p) < min(v, p + 1, v.size() - 1)
 *          false en caso contrario
 *      }
 *      max(v, i, e) return m = Para todo a : i <= a <= e : m >= v[a] ^ Existe a : i <= a <= e : m = v[a]
 *      min(v, i, e) return m = Para todo a : i <= a <= e : m <= v[a] ^ Existe a : i <= a <=  : m = v[a]
 *
 *      I1:{ 0 <= i <= p + 1 ^ mayorIzq = max(v, i, e) }
 *      I2:{ p + 1 <= i <= v.size() ^ binDividido es
 *                                          true si max(v, 0, p) < min(v, p+ 1, i)
 *                                          false si caso contrario
 *      }
 *      Función cota (1): (p + 1) - i
 *      Función cota (2): v.size() - i
 */

bool resolver(vector<int> & v, int p) {
    bool bienDividido = true;
    int mayorIzq = 0, i;

    for (i = 0; i <= p; ++i) {
        if (mayorIzq < v[i]) mayorIzq = v[i];
    }

    while (bienDividido && i < v.size()) {
        bienDividido = v[i] > mayorIzq;
        ++i;
    }

    return bienDividido;
}

void resuelveCaso() {
    int n, p;
    cin >> n >> p;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (p == n - 1 || resolver(v, p)) cout << "SI\n";
    else cout << "NO\n";
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int nCasos;
    cin >> nCasos;
    for (int i = 0; i < nCasos; ++i) {
        resuelveCaso();
    }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}