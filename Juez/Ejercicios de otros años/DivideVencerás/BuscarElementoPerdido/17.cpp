// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

int resolver(std::vector<int> const& datos, std::vector<int> const& datos2, int ini, int fin) {
	if (ini >= fin) return datos[fin];
	else if (ini == fin - 1) {
		if (datos[ini] == datos2[ini]) return datos[fin];
		else return datos[ini];
	}	
	else {
		int mitad = (ini + fin) / 2;
		if (datos[mitad] < datos2[mitad]) return resolver(datos, datos2, ini, mitad);
		else return resolver(datos, datos2, mitad + 1, fin);
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;

	std::vector<int> datos(n);
	std::vector<int> datos2(n - 1);

	for (int & i : datos) std::cin >> i;
	for (int & i : datos2) std::cin >> i;

	// escribir sol
	std::cout << resolver(datos, datos2, 0, n - 1) << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
/*#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	system("PAUSE");
	return 0;
}