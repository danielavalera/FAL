#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n) (siendo n el número de edificios)
 * Justificación del coste: el coste de la función resolver es lineal siendo n el
 * número de elementos del vector. Esto es así porque todas las operaciones tienen
 * un coste constante y el bucle se ejectura n veces.
 *
 * Especificación:
 *      P:{
 *          v.size() > 0 ^
 *          Para todo e : 0 <= e < v.size() : v[e].altura >= 0 ^
 *          Para todo e : 0 <= e < v.size() : -1 <= v[e].piso <= v[e].altura ^
 *          0 <= i v.size()
 *      }
 *      tieneVistas(v, i)
 *      Q:{
 *          devuelve true si Para todo e : i < e < v.size() : v[i].piso > v[e].altura
 *          devuelve falso en caso contrario
 *      }
 *
 *      P:{
 *          v.size() > 0 ^
 *          Para todo e : 0 <= e < v.size() : v[e].altura >= 0 ^
 *          Para todo e : 0 <= e < v.size() : -1 <= v[e].piso <= v[e].altura
 *      }
 *      vector<string> resolver(vector<tEdificio> const& v) return sol
 *      Q:{
 *          0 <= sol.size() <= v.size() ^
 *          Para todo i : 0 <= i < sol.size() : Existe e : 0 <= e < v.size() : v[i] = v[e].identificador ^ tieneVistas(v, i)
 *      }
 *
 *      I:{
 *          0 <= i <= v.size() ^
 *          alturaMaxima = Para todo e : i <= e < v.size() : max(v[e].altura) ^
 *          Para todo e : 0 <= e < sol.size() : Existe u : i <= u < v.size() : v[e] = v[u].identificador ^ tieneVistas(v, e)
 *      }
 *      Función cota: i + 1
 */

struct tEdificio {
    string identificador;
    int altura;
    int piso;
};

vector<string> resolver(vector<tEdificio> const& v) {
    vector<string> sol;
    int alturaMaxima = -1;

    for (int i = v.size() - 1; i >= 0; --i) {
        if (v[i].piso > alturaMaxima) sol.push_back(v[i].identificador);

        if (v[i].altura > alturaMaxima) alturaMaxima = v[i].altura;
    }

    return sol;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!cin) return false;

    vector<tEdificio> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].identificador >> v[i].altura >> v[i].piso;
    }

    vector<string> sol = resolver(v);

    if (sol.size() == 0) cout << "Ninguno\n";
    else {
        cout << sol.size() << '\n';
        for (int i = 0; i < sol.size(); ++i) {
            cout << sol[i] << ' ';
        }
        cout << '\n';
    }

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