#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n)
 * Justificación del coste: el coste de la función resolver es lineal siendo n el
 * número de elementos del vector. Esto es así porque todas las operaciones tienen
 * un coste constante y el bucle se ejecuta n veces.
 *
 * Especificación:
 *      P:{v.size() >= 0}
 *      void resolver(vector<int> & v)
 *      Q:{
 *          0 <= v.size() <= v2.size() ^
 *          (Para todo i : 0 <= i < v.size() : v[i] % 2 == 0 ^ Existe e : 0 <= e < v2.size() : v[i] = v2[e])
 *      }
 *      v2 = v en el momento de llamar a la función
 *
 *      I:{
 *          0 <= i <= v.size() ^
 *          0 <= contador <= i ^
 *          Para todo e : 0 <= e < contador : v[e] % 2 == 0 ^ Existe u : 0 <= u < v2.size() : v[e] = v2[u]
 *      }
 *      Función cota: v.size() - i
 */

void resolver(vector<int> & v) {
    int contador = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) {
            v[contador] = v[i];
            contador++;
        }
    }

    v.resize(contador);
}

void resuelveCaso() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    resolver(v);

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << '\n';
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