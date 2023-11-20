#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n) (siendo n el número de edificios)
 * Justificación del coste: el coste de la función resolver es lineal siendo n el
 * número de elementos del vector. Esto es así porque todas las operaciones tienen
 * un coste constante y el bucle se ejectura n veces..
 *
 * Especificación:
 *      P:{0 < v.size() ^ (Existe k : 0 <= k < v.size() : v[k] > t)}
 *      tIntervalo resolver(vector<int> const& v, int t) return sol
 *      Q:{
 *          0 <= sol.inicio <= sol.fin < v.size() ^
 *          (Para todo i : sol.inicio <= i <= sol.fin : v[i] > t) ^
 *          (
 *              No existe i, e : 0 <= i <= e < v.size() : (Para todo u : i <= u <= e : v[u] > t) ^
 *                                                          e - i > sol.fin - sol.inicio
 *          )
 *      }
 *
 *      I:{
 *          0 <= i <= v.size() ^
 *          -1 <= sol.inicio <= sol.fin < v.size() ^
 *          (primeraPos = -1 || (Para todo e : primerPos <= e <= i : v[e] > t)) ^
 *          (Para todo e : sol.inicio <= e <= sol.fin : v[e] > t)
 *      }
 *      Función cota: v.size() - i
 */

struct tIntervalo {
    int inicio;
    int fin;
};

tIntervalo resolver(vector<int> const& v, int t) {
    tIntervalo sol;
    sol.inicio = -1;
    sol.fin = -1;
    int primeraPos = -1;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > t) { // El elemento actual es mayor estricto que t
            if (i < v.size() - 1) { // El elemento v[i] no es el último de v
                if (sol.inicio == -1) { // Le mejor solución hasta el momento (sol) no existía
                    sol.inicio = i;
                } else if (primeraPos == -1) {
                    primeraPos = i;
                }
            } else { // El elemento v[i] es el último de v
                if (sol.fin == -1) { // Le mejor solución hasta el momento (sol) no existía
                    if (sol.inicio == -1) sol.inicio = i;
                    sol.fin = i;
                } else if (primeraPos != -1) { // Le mejor solución hasta el momento (sol) sí existía pero se compara con la actual
                    if (sol.fin - sol.inicio < i - primeraPos) {
                        sol.inicio = primeraPos;
                        sol.fin = i;
                    }
                }
            }
        } else { // El elemento actual no es mayor estricto que t
            if (sol.inicio != -1 && sol.fin == -1) {
                sol.fin = i - 1;
            } else if (primeraPos != -1) {
                if (sol.fin - sol.inicio < (i - 1) - primeraPos) {
                    sol.inicio = primeraPos;
                    sol.fin = i - 1;
                }

                primeraPos = -1;
            }
        }
    }

    return sol;
}

void resuelveCaso() {
    int nEdificios, t;
    cin >> nEdificios >> t;
    vector<int> v(nEdificios);

    for (int i = 0; i < nEdificios; ++i) {
        cin >> v[i];
    }

    tIntervalo sol = resolver(v, t);
    cout << sol.inicio << ' ' << sol.fin << '\n';
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