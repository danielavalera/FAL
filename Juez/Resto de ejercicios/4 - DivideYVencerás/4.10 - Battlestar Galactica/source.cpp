// DANIELA VALENTINA VALERA FUENTES
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// función que resuelve el problema
int resolver(vector<int>& datos, int ini, int fin) {
	if (ini >= fin) 
		return 0;
	else {
		int mitad = (ini + fin) / 2;

		int izquierda = resolver(datos, ini, mitad);
		int derecha = resolver(datos, mitad + 1, fin);

		int i = ini, j = mitad + 1;
		int contador = 0;

		while (i <= mitad && j <= fin) {
			if (datos[i] > datos[j]) {
				contador += (mitad - i + 1);
				++j;
			}
			else ++i;
		}
		sort(datos.begin() + ini, datos.begin() + fin + 1);
		return izquierda + derecha + contador;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n; cin >> n;
	if (!std::cin)
		return false;

	vector<int> datos(n);
	for (int i = 0; i < datos.size(); i++){
		cin >> datos[i];
	}

	// escribir sol
	cout << resolver(datos, 0, n - 1) << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos4.10.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;



	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	system("PAUSE");
	return 0;
}