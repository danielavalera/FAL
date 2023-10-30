// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector <int> const &datos, int ini, int fin, int &numPares) {
	if (ini >= fin) {
		numPares = 0;
		return true;
	}
	else if (ini == fin - 1) {
		if ((datos[ini] % 2 == 0) && (datos[fin] % 2 == 0)) numPares = 2;
		else if ((datos[ini] % 2 == 0) || (datos[fin] % 2 == 0)) numPares = 1;
		else numPares = 0; 
		return true;
	}
	else {
		int mitad = (ini + fin) / 2;
		int izquierda, derecha;
		if (resolver(datos, ini, mitad, izquierda)) {
			if (resolver(datos, mitad + 1, fin, derecha)) {
				if (abs(izquierda - derecha) < 3) {
					numPares = izquierda + derecha;
					return true;
				}
			}
		}
		return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	if (n == 0)
		return false;
	std::vector <int> datos(n);
	for (int &i : datos) std::cin >> i;
	int numPares = 0;
	// escribir sol

	if (resolver(datos, 0, n - 1, numPares)) std::cout << "SI";
	else std::cout << "NO";
	std::cout << std::endl;
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
/*#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif*/
	system("PAUSE");
	return 0;
}