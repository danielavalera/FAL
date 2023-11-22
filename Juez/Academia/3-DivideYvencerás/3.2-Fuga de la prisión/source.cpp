// DANIELA VALENTINA VALERA FUENTES
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//COMO LOS DATOS ESTÁN ORDENADOS (MENOR A MAYOR) ES FÁCIL APLICAR DIVIDE Y VENCERAS
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
char resolver(const vector<char>&v, char primero, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v[ini] - primero == ini)
            return (char)(v[ini] + 1);
        else
            return (char)(v[ini] - 1);
    }else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] - primero == mitad)
            return resolver(v, primero, mitad, fin);
        else
            return resolver(v, primero, ini, mitad);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char primero, ultimo; cin >> primero >> ultimo;
    vector<char> v(ultimo-primero);
    for (int i = 0; i < v.size(); i++) {
        cin >> v[i];
    }
    // escribir sol
    cout << resolver(v, primero, 0, v.size()) << '\n';


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("FugaPrision.txt");
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