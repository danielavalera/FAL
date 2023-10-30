// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct player {
	bool presentado;
	int juegos;
};

// función que resuelve el problema

player resolver(std::vector<std::string> const& datos, int ini, int fin, int rondaInfo, int & ronda) {

	if (ini == fin - 1) {// 2 jugadores en total
		ronda = 1;
		if ((datos[ini] == "NP") && (datos[fin] == "NP")) return { false, 0 };
		else if ((datos[ini] == "NP") || (datos[fin] == "NP")) return { true, 0 };
		else return { true, 1 };
	}
	else {
		int mitad = (ini + fin) / 2;

		player izquierda = resolver(datos, ini, mitad, rondaInfo, ronda);
		player derecha = resolver(datos, mitad + 1, fin, rondaInfo, ronda);

		if (rondaInfo > ronda && izquierda.presentado && derecha.presentado) {// los 2 se presentan
			++ronda;
			return { true, izquierda.juegos + derecha.juegos + 1 };
		}
		else if (izquierda.presentado || derecha.presentado) {// se presenta 1
			++ronda;
			return { true, (izquierda.juegos + derecha.juegos) };
		}
		else {// no se presenta ninguno
			++ronda;
			return { false, (izquierda.juegos + derecha.juegos) };
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	std::cin >> n;
	
	if (!std::cin) return false;
	
	int rondaInfo,ronda;
	std::cin >> rondaInfo;
	
	std::vector <std::string> datos(n);
	for (std::string &i: datos) std::cin >> i;

	player solucion = resolver(datos, 0, n - 1, rondaInfo, ronda);
	// Escribir sol:
	std::cout << solucion.juegos << "\n";

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