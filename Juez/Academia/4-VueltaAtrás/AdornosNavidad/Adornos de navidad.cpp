#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n^2) =  O(n) siendo n el número de objetos
 *
 * Justificación del coste: por cada elemento se prueba a comprarse o no comprarse
 *
 */

struct tObjeto {
    int coste;
    int superficie;
};

struct tDatos {
    int nObjetos;
    int presupuesto;
    vector<tObjeto> objetos;
};

struct tSol {
    int coste;
    int superficie;
    vector<bool> sol;
};

void resolver(const tDatos & datos, int k, tSol & solActual, tSol & solMejor) {
    // Se prueba a comprar el objeto k
    solActual.sol[k] = true;
    solActual.coste += datos.objetos[k].coste;
    solActual.superficie += datos.objetos[k].superficie;

    if (solActual.coste <= datos.presupuesto) {
        if (k + 1 == datos.nObjetos) {
            if (solActual.superficie > solMejor.superficie) solMejor = solActual;
        } else resolver(datos, k + 1, solActual, solMejor);
    }

    solActual.sol[k] = false;
    solActual.coste -= datos.objetos[k].coste;
    solActual.superficie -= datos.objetos[k].superficie;

    // Se prueba a no comprar el objeto k
    if (solActual.coste <= datos.presupuesto) {
        if (k + 1 == datos.nObjetos) {
            if (solActual.superficie > solMejor.superficie) solMejor = solActual;
        } else resolver(datos, k + 1, solActual, solMejor);
    }
}

bool resuelveCaso() {
    tDatos datos;
    cin >> datos.nObjetos >> datos.presupuesto;
    if (!cin) return false;
    datos.objetos = vector<tObjeto>(datos.nObjetos);

    tSol solMejor, solActual;
    solMejor.coste = 0;
    solMejor.superficie = 0;
    solMejor.sol = vector<bool>(datos.nObjetos, false);
    solActual.coste = 0;
    solActual.superficie = 0;
    solActual.sol = vector<bool>(datos.nObjetos, false);

    for (int i = 0; i < datos.nObjetos; ++i) {
        cin >> datos.objetos[i].coste >> datos.objetos[i].superficie;
    }

    resolver(datos, 0, solActual, solMejor);

    cout << solMejor.superficie << '\n';

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