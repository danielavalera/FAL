// Daniela Valentina Valera Fuentes
// F94

/*
* COSTE: O(n) siendo n el número de cifras
* 
* ESPECIFICACIÓN:
*
*       tenemos dos casos base 
*       (no tiene que ser literalmente lo que hay en el código, 
*       hay que quedarse con la idea del algoritmo)
*       -Función de recurrencia:
*               T(n) = c0             si n = 0
*               T(n) = c1 + T(n-1)    si n > 0
*                siendo n el nº de cifras
*
*                **c0 y c1 son constantes
*                **T(n-1) xq en cada vuelta se reduce n una vez
*
*
*
*
*       -Desplegado:
*               T(n) = c1 + T(n-1) //de primeras, es copiar esta función de la f.de recurrencia
*               En la segunda vuelta: T(n) = c1 + T(n-1) * c1 + c1 + T(n-2)
*               En la tercera... T(n) = c1 + T(n-1) * c1 + c1 + T(n-2) * c1 + c1 + c1 + T(n-3) = 3c1 + T(n-3)
*               ...
*               T(n) = k*c1 + T(n-k)
*
*
*       Decir que ese n-k queremos que sea un 0. Lo que nos queda que n = k
*       -Postulado:
*               n-k = 0 -> n = k
*               Por lo que si sustituimos en la función de desplegado (T(n) = k*c1 + T(n-k)):
*               k*c1 + T(n-k) = nc1 + T(n-n) = nc1 + T(0) = nc1 + c0 = n , por lo que ahora podemos especificar el coste:
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
