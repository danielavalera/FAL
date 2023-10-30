// Nombre del alumno Antonio Lucas Simón
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// función que resuelve el problema
std::string resolver(int a) {
	if (a==1) return "1";
	else if (a==0) return "0";
	else return resolver(a/2) + char('0' + a % 2);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int a;
	std::cin >> a;
    
	std::string sol = resolver(a);
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