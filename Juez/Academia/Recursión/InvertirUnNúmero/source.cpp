// Daniela Valentina Valera Fuentes
// F94

/*
* COSTE:
* 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
/*
INICIAL: n: 2345 <-> m: 0
1RA EJ:  n: 234 <-> m: 5
...:     n:    <-> m: 5432
*/
int resolver(int n, int m) { 
    if (n == 0) return m;
    else return resolver(n / 10, m * 10 + n % 10); 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    if (n == 0)
        return false;

    // escribir sol
    cout << resolver(n, 0) << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("InvertirNumero.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
