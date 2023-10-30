// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int n) {
	if (n / 10 == 0) return 9 - n;
	else return resolver(n / 10) * 10 + (9 - (n % 10));
}
int resolver2(int n, int inverso) {

	if (n / 10 == 0 && inverso == 0) return 9 - n;
	else if (n == 0) return inverso;
	else return resolver2(n / 10, inverso * 10 + (9 - (n % 10)));
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	// escribir sol
	std::cout << resolver(n) << " " << resolver2(n,0) << std::endl;
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