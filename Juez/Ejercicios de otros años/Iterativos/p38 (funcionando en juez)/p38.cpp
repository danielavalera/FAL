// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
	int ini, ganancia;
};

// función que resuelve el problema
// Coste = numAsaltos
tSol resolver(std::vector<int> const& datos, const int numAsaltos) {
	int ini = 0, gananciaMax = 0;
	for (int i = 0; i < numAsaltos; i++) gananciaMax += datos[i];
	int gananciaAux = gananciaMax;
	for (int i = numAsaltos; i < datos.size(); i++) {
		gananciaAux -= datos[i - numAsaltos];
		gananciaAux += datos[i];
		if (gananciaAux >= gananciaMax) {
			gananciaMax = gananciaAux;
			ini = i - numAsaltos + 1;
		}
	}
	return { ini, gananciaMax };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int elementos, numAsaltos;
	std::cin >> elementos >> numAsaltos;
	std::vector <int> datos(elementos);
	for (int &i : datos) std::cin >> i;
	// escribir sol
	tSol solucion = resolver(datos, numAsaltos);
	std::cout << solucion.ini << " " << solucion.ganancia << std::endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	/*   #ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif */


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
	/*   #ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif */

	system("PAUSE");
	return 0;
}