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
 *      - Funciones escaleraAscendente y escaleraDescendente: O(n) siendo n el número de elementos del vector.
 *          El coste es lineal respecto al número de elementos del vector, esto es así porque se recorren todos los
 *          elementos del vector en el caso peor (es posible que un tramo sea todo el vector entero) y todas las operaciones
 *          son constantes.
 *
 *      - Función resolver: O(n) siendo n el número de elementos del vector.
 *          El coste es lineal respecto al número de elementos del vector por llamar a escaleraAscendente y
 *          escaleraDescendente cuyos costes son O(n). El resto de operaciones son de coste constante.
 *          O(2n) -> O(n)
 *
 * Especificación:
 *      P:{datos.n > 0 && datos.n == datos.valores.size()}
 *      tSolEscalera escaleraAscendente(const tDatos & datos) return sol
 *      Q:{
 *          (Para todo i : 0 < i < sol.elementos : datos.valores[i - 1] <= datos.valores[i])
 *          ^
 *          (sol.escalonMasAncho = max( # (Para todo i : 0 < i < sol.elementos : datos.valores[i - 1] == datos.valores[i]) ))
 *      }
 *
 *      I:{
 *         1 <= i <= datos.n ^
 *         sol.elementos = i ^
 *         (longitudEscalonActual = # (Para todo e : i - longitudEscalorActual < e < i : datos.valores[e - 1] == datos.valores[e]) )) ^
 *         1 <= sol.escalonMasAncho <= longitudEscalonActual
 *      }
 *      Función cota: n - i
 *
 *      P:{datos.n > 0 && datos.n == datos.valores.size()}
 *      tSolEscalera escaleraDescendente(const tDatos & datos) return sol
 *      Q:{
 *          (Para todo i : datos.n - sol.elementos < i < datos.n - 1 : datos.valores[i] >= datos.valores[i + 1])
 *          ^
 *          (sol.escalonMasAncho = max( # (Para todo i : datos.n - sol.elementos < i < datos.n - 1s : datos.valores[i] == datos.valores[i + 1]) ))
 *      }
 *
 *      I:{
 *         -1 <= i <= datos.n - 2 ^
 *         sol.elementos = (datos.n - 1) - i ^
 *         (longitudEscalonActual = # (Para todo e : i < e < i + longitudEscalorActual : datos.valores[e] == datos.valores[e + 1]) )) ^
 *         1 <= sol.escalonMasAncho <= longitudEscalonActual
 *      }
 *      Función cota: i
 *
 */

struct tDatos {
    int n;
    vector<int> valores;
};

struct tSolEscalera {
    int elementos;
    int escalonMasAncho;
};

struct tSol {
    bool esEscalera;
    int escalonMasAncho;
    int elementosTramoAscendente;
    int elementosTramoDescendente;
};

tSolEscalera escaleraAscendente(const tDatos & datos) {
    tSolEscalera sol = { 1, 1 };

    int i = 1, longitudEscalonActual = 1;
    while (i < datos.n && datos.valores[i - 1] <= datos.valores[i]) {
        if (datos.valores[i - 1] == datos.valores[i]) {
            longitudEscalonActual++;
        } else {
            if (sol.escalonMasAncho < longitudEscalonActual) {
                sol.escalonMasAncho = longitudEscalonActual;
            }

            longitudEscalonActual = 1;
        }

        sol.elementos++;
        i++;
    }
    if (sol.escalonMasAncho < longitudEscalonActual) {
        sol.escalonMasAncho = longitudEscalonActual;
    }

    return sol;
}

tSolEscalera escaleraDescendente(const tDatos & datos) {
    tSolEscalera sol = { 1, 1 };

    int i = datos.n - 2, longitudEscalonActual = 1;
    while (i >= 0 && datos.valores[i] >= datos.valores[i + 1]) {
        if (datos.valores[i] == datos.valores[i + 1]) {
            longitudEscalonActual++;
        } else {
            if (sol.escalonMasAncho < longitudEscalonActual) {
                sol.escalonMasAncho = longitudEscalonActual;
            }

            longitudEscalonActual = 1;
        }

        sol.elementos++;
        i--;
    }
    if (sol.escalonMasAncho < longitudEscalonActual) {
        sol.escalonMasAncho = longitudEscalonActual;
    }

    return sol;
}

tSol resolver(const tDatos & datos) {
    tSol sol;

    tSolEscalera solTramoAscendente = escaleraAscendente(datos);
    tSolEscalera solTramoDescendente = escaleraDescendente(datos);

    if (solTramoAscendente.elementos + solTramoDescendente.elementos >= datos.n) {
        sol.esEscalera = true;
        sol.escalonMasAncho = max(solTramoAscendente.escalonMasAncho, solTramoDescendente.escalonMasAncho);
    } else {
        sol.esEscalera = false;
        sol.elementosTramoAscendente = solTramoAscendente.elementos;
        sol.elementosTramoDescendente = solTramoDescendente.elementos;
    }

    return sol;
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.n;
    if (datos.n == -1) return false;

    datos.valores = vector<int>(datos.n);
    for (int i = 0; i < datos.n; ++i) {
        cin >> datos.valores[i];
    }

    tSol sol = resolver(datos);

    if (sol.esEscalera) cout << "SI " << sol.escalonMasAncho << '\n';
    else cout << "NO " << sol.elementosTramoAscendente << ' ' << sol.elementosTramoDescendente << '\n';

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