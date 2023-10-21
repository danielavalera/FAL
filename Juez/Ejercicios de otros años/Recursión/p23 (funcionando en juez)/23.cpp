// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(int &peso) {
	int pi, di, pd, dd;
	std::cin >> pi >> di >> pd >> dd;
	
	bool eqIzquierda = true, eqDerecha = true; // lo consideramos en equilibrio de inicio

	if (pi == 0) eqIzquierda = resolver(pi); //añadimos submovil izquierdo
	if (pd == 0) eqIzquierda = resolver(pd); //añadimos submovil derecho
	if (eqIzquierda && eqDerecha && pi * di == pd * dd) { //comprobamos el equilibrio segun la formula que nos han enunciado
		peso = pd + pi;
		return true;
	}
	else return false;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	// escribir sol
	if (resolver(n)) std::cout << "SI";
	else std::cout << "NO";
	std::cout << std::endl;
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