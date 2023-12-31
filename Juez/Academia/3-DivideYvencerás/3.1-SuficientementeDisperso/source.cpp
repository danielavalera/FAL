#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

/*
 * Coste: O(n) siendo n el número de elementos visibles
 *
 * Especificación:
 *
 *      -Ecuacion de recurrencia:
 *          T(n) = c0               si n = 1
 *          T(n) = c1 + 2T(n/2)     si n > 1
 *          Siendo n el número de elementos visibles
 *              ** 2T(n/2) : xq hay 2 llamadas recursivas donde el seg visible de cada una de ellas se reduce a la mitad
 *
 *      Por lo tanto, el coste de la solución es n, orden lineal.
 *      (Todos los elementos se visitan una vez).
 * 
 *      [Cuando tenemos un caso recursivo donde se hace una llamada con la mitad de elementos (T(n/2)), obligatoriamente se hace el Desplegado y Postulado.
 *      Pero cuando tenemos 2T(n/2) no hace falta xq se entiende que tenemos un coste lineal, xq al final se están visitando todos los elementos.Por eso ponemos el párrafo de:
 *      líneas 19 y 20]
 *      -Desplegado:
 *
 *      -Postulado:
 *
 */

bool suficientementeDisperso(const vector<int>& v, int k, int ini, int fin) {
    //1ro calcular la pos de la mitad del vector (NO SE HACE DIVIDIENDO EL TAMAÑO/2):
    /*TRUCO: decimos que el vector será constante y vamos a recibir 2 pos (ini y fin)
    por lo que la mitad es (ini+fin) /2.
    */

    if (ini + 1 == fin) return true; //caso base: cuando tengamos un único elemento
    else { //caso recursivo
        int mitad = (ini + fin) / 2;
        //Hay 2 TIPOS
        /*Los que hacen 2 llamadas recursivas, como este. Que el coste no es demasiado eficiente, mínimo lineal. Se aplican porque obligatoriamente según 
        * la naturaleza del problema nos lo piden.
        * Los que solo hacen 1 llamada, como otro ejercicio.
        */
        bool izq = suficientementeDisperso(v, k, ini, mitad);
        bool der = suficientementeDisperso(v, k, mitad, fin);

        //abs() : da un valor absoluto
        return izq && der && abs(v[ini] - v[fin - 1]) >= k;
    }
}

bool resuelveCaso() {
    int n, k;
    cin >> n >> k;
    if (!cin) return false;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    if (suficientementeDisperso(v, k, 0, n)) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("SuficientementeDisperso.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}