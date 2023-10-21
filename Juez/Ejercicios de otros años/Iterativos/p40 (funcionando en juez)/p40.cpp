// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
	int max, racha,postRacha;
};

// función que resuelve el problema
// Coste = datos.size()
tSol resolver(std::vector<int> const& datos) {
	int max = 0, racha = 0,postRacha = 0;
	int maxAux = 0;
	for (int i = 0; i < datos.size(); i++){
		++postRacha; // aumenta el numero de partido desde la ultima racha

		if (datos[i]>0) ++maxAux; //maximo relativo de partidos ganados aumenta
		else maxAux = 0; //partido perdido o empatado

		if (max > 0 && maxAux == max) { //si es igual al maximo absoluto, sumamos sumamos uno a la racha
			++racha;
			postRacha = 0;
		}
		else if (maxAux > max) { //si es mayor al maximo absoluto lo establecemos como nuevo maximo
			max = maxAux;
			racha = 1;
			postRacha = 0;
		}
	}
	return {max, racha, postRacha};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int elementos;
	std::cin >> elementos;
	std::vector <int> datos(elementos);
	for (int &i : datos) std::cin >> i;
	if (!std::cin)
		return false;
	// escribir sol
	tSol solucion = resolver(datos);
	std::cout << solucion.max << " " << solucion.racha << " " << solucion.postRacha << std::endl;


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
/* #ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */


	while (resuelveCaso())
		;


/*	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif */
	system("PAUSE");
	return 0;
}