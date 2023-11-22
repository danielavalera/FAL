// DANIELA VALENTINA VALERA FUENTES
// F94

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
 * Coste: O(log(n)) siendo n el número de elementos visibles
 *
 * Especificación:
 *
 *      -Ecuacion de recurrencia:
 *          T(n) = c0               si n = 1
 *          T(n) = c1 + T(n/2)      si n > 1
 *          Siendo n el número de elementos visibles
 *
 *      -Desplegado:
 *          T(n) = c1 + T(n/2) = c1 + c1 + T(n/2/2) = 2c1 + T(n/4) = ... = 3c1 + T(n/8) = ...
 *          = ... = kc1 + T(n/(2^k))
 *
 *      -Postulado:
 *          n/(2^k) = 1 -> n = 2^k -> k = log(n) xq pasamos el 2^k a la izq.
 *          kc1 + T(n/2^k) = log(n)c1 + T(n/2^log(n)) = log(n)c1 + T(n/n) = log(n)c1 + c0 = log(n)
 */

// función que resuelve el problema
int resolver(const vector<int>& v1, const vector<int>& v2, int ini, int fin) {
    if (ini == fin) return v1[ini];
    else {
        int m = (ini + fin) / 2;
        if(v1[m] < v2[m])
            return resolver(v1, v2, ini, m);
        else 
            return resolver(v1, v2, m+1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamVector; cin >> tamVector;

    vector<int> v1(tamVector);  
    for (int i = 0; i < tamVector; i++){
        cin >> v1[i];
    }
    
    vector<int> v2(tamVector - 1);
    for (int i = 0; i < tamVector-1; i++){
        cin >> v2[i];
    }
    // escribir sol
    cout << resolver(v1, v2, 0, tamVector - 1) << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("BuscElemPerdido.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}