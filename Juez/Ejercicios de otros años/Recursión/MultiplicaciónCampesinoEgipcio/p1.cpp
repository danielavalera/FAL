// Nombre del alumno Antonio Lucas Simón
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
long long int resolver(long long int a, long long int b) {
	if (b == 0) return 0;
	else if (b == 1) return a;
	else if (b > 1 && b % 2 == 0) return resolver(2 * a,b / 2);
	else return (resolver(2 * a,b / 2) + a);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	long long  int a, b;
	std::cin >> a >> b;
    
    long long int sol = resolver(a,b);
    // escribir sol
	std::cout << sol << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
	#ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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