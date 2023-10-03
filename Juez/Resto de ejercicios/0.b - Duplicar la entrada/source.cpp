// Daniela Valentina Valera Fuentes (F94)
// 
//Programa que duplica la entrada de números enteros,
//la diferencia con 0.a es que el fin del programa 
//lo marca un 0, por lo que la plantilla es diferente (Centinela).
//Tampoco tiene coste, igual que 0.a.


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
/*TipoSolucion resolver(TipoDatos datos) {
}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;


    // escribir sol
    cout << n * 2 << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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