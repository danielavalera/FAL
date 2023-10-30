// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

int resolver(std::vector < std::vector <int> > & m, int a, int b) {
	if (b == 0 ||b == a) return m[a][b] = 1;
	else if (b == 1 || b == a - 1) return m[a][b] = a;
	else {
		if (m[a - 1][b - 1] == -1) m[a - 1][b - 1] = resolver(m, a - 1, b - 1);
		if (m[a - 1][b] == -1) m[a - 1][b] = resolver(m, a - 1, b);
		return m[a][b] = m[a - 1][b - 1] + m[a - 1][b];
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	std::cin >> a >> b;
	if (!std::cin) return false;
	std::vector < std::vector <int> > m(a + 1, std::vector <int >(b + 1, -1));
	std::cout << resolver(m, a, b) << std::endl;
	return true ;
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