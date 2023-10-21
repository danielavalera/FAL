// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema

int resolver(std::vector  <int> & v, int i, int suma, int acu) {
	acu += v[i];
	if (suma == acu) return 1;
	else if (i < 0 || i == v.size() - 1) return 0;
	else if (acu > suma) {
		acu -= v[i];
		resolver(v, i + 1, suma, acu);
	}
	else{
		return 1 + resolver(v, i + 1, suma, acu);
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int a, b;
	std::cin >> a >> b;
	if (!std::cin) return false;
	std::vector <int> v(a);
	for (int i = 0; i < a; i++) std::cin >> v[i];
	int acu = 0;
	std::cout << resolver(v,0, b, acu) << std::endl;
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