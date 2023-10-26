#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n) (siendo n el número de partidos)
 * Justificación del coste: el coste de la función resolver es lineal siendo n el
 * número de elementos del vector. Esto es así porque todas las operaciones tienen
 * un coste constante y el bucle se ejectura n veces..
 *
 * Especificación:
 *      P:{v.size() >= 0}
 *      tRacha resolver(vector<int> const& v) return sol
 *      Q:{
 *          0 <= sol.nPartidos <= v.size() ^
 *          sol.nPartidos = max(Existe i, e : 0 <= i <= e < v.size() : (Para todo u : i <= u <= e : v[u] > 0 ) : e - i ) ^
 *          sol.nVeces = contar(max(Existe i, e : 0 <= i <= e < v.size() : (Para todo u : i <= u <= e : v[u] > 0 ) : e - i )) ^
 *          sol.haceCuanto = v.size() - (Existe i, e : 0 <= i <= e < v.size() : e - i = sol.nPartidos ^ (Para todo u : i <= u <= e : v[u] > 0 ) : max(e))
 *      }
 *
 *      I:{
 *          0 <= i <= v.size() ^
 *          0 <= rachaActual <= i ^
 *          Para todo e : i - rachaActual <= e <= i : v[e] > 0 ^
 *          0 <= racha.nPartidos <= i ^
 *          0 <= racha.nVeces <= (i / 2) + 1 ^
 *          0 <= racha.haceCuanto <= i
 *      }
 *      Función cota: v.size() - i
 */

struct tRacha {
    int nPartidos;
    int nVeces;
    int haceCuanto;
};

tRacha resolver(vector<int> const& v) {
    tRacha racha;
    racha.nPartidos = 0;
    racha.nVeces = 0;
    racha.haceCuanto = 0;

    int rachaActual = 0;

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] > 0) {
            rachaActual++;
            racha.haceCuanto++;
        } else {
            if (rachaActual > racha.nPartidos) {
                racha.nPartidos = rachaActual;
                racha.nVeces = 1;
                racha.haceCuanto = 1;
            } else if (rachaActual == racha.nPartidos && rachaActual > 0) {
                racha.nVeces++;
                racha.haceCuanto = 1;
            } else {
                racha.haceCuanto++;
            }

            rachaActual = 0;
        }
    }

    if (rachaActual > racha.nPartidos) {
        racha.nPartidos = rachaActual;
        racha.nVeces = 1;
        racha.haceCuanto = 0;
    } else if (rachaActual == racha.nPartidos && rachaActual > 0) {
        racha.nVeces++;
        racha.haceCuanto = 0;
    }

    return racha;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin) return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    tRacha racha = resolver(v);

    cout << racha.nPartidos << ' ' << racha.nVeces << ' ' << racha.haceCuanto << '\n';

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