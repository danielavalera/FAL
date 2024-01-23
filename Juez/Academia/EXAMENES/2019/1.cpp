#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

/*
 * Coste: O(n) siendo n el número de elementos del vector
 * 
 * Justificación del coste: el coste es lineal debido a que se recorren todos los elementos
 * del vector con todas las operaciones constantes.
 * 
 * Especificación:
 * 
 *      P:{n >= 0 ^ k >= 0 ^ v.size() == n}
 *      int resolver(int n, int k, const vector<bool> & v) return minimo
 *      Q:{
 *          minimo = (
 *              Sea i, f : 0 <= i <= f < n :
 *              Si existe (contar(v, i, f) == k) => min(contar(v, i, f))
 *              Si no existe => n + 1
 *          )
 *      }
 *      
 *      contar(v, i, f) = contar(Para todo e : i <= e <= f : v[e] == true)
 *      
 *      I:{
 *          0 <= inicio <= fin <= n ^
 *          0 <= actual <= k ^
 *          minimo = (
 *              Sea i, f : 0 <= i <= f <= fin :
 *              Si existe (contar(v, i, f) == k) => min(contar(v, i, f))
 *              Si no existe => n + 1
 *          )
 *      }
 *      
 *      Función cota: t = (n - fin) + (fin - ini)
 *
 */


int resolver(int n, int k, const vector<bool> & v) {
    int inicio = 0, fin = 0, actual = 0, minimo = n + 1;

    while (fin < n) {
        if (!v[inicio]) {
            if (inicio == fin) fin++;
            inicio++;
        } else if (actual < k) {
            if (v[fin]) actual++;

            if (actual == k) minimo = min(minimo, fin - inicio + 1);

            fin++;
        } else if (actual == k) {
            actual--;
            inicio++;
        }
    }
    
    return minimo;
}

bool resuelveCaso() {
    int n, k, aux;
    cin >> n;
    if (n == -1) return false;

    vector<bool> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> aux;
        v[i] = (bool) aux;
    }
    cin >> k;

    cout << resolver(n, k, v) << '\n';

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