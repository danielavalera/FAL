// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
char resolver(std::vector<char> const& datos, int const& posIni, int const& posFin, char const&  charIni, char const& charFin) {
	if (posIni == datos.size()) return charFin; //Un solo valor 

	int mitad = (posIni + posFin) / 2

	if (posIni > posFin) return datos[posIni] - 1; //Si tenemos un solo valor
	else if (datos[mitad] - charIni == mitad) return resolver(datos, mitad + 1, posFin, charIni, charFin); //Si la mitad corresponde con el valor de la mitad vamos a la derecha
	else return resolver(datos, posIni, mitad - 1, charIni, charFin); //Si mitad no corresponde vamos a la izquierda
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char inicio, fin;
	std::cin >> inicio >> fin;

	int tam = int(fin) - int(inicio);

	std::vector<char> datos(tam);

	for (char &i : datos) std::cin >> i;
	char sol = resolver(datos, 0, tam, inicio,fin);

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
	//system("PAUSE");
	return 0;
}