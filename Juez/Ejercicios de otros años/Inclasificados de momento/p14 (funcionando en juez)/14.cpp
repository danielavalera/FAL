// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const& datos, int ini, int fin, int & suma) {
	if (fin <= ini) return true; //si vacio o un elemento cumple
	else if (ini == fin - 1) {//2 elementos
		suma = datos[ini] + datos[fin];

		if (datos[ini] < datos[fin]) return true;
		else return false;
	}
	else { // mas de 2 elementos
		int mitad = (ini + fin) / 2;
		int sumaDerecha = 0, sumaIzquierda = 0;

		bool derecha = resolver(datos, mitad + 1, fin, sumaDerecha);
		bool izquierda = resolver(datos, ini, mitad, sumaIzquierda);

		if (sumaIzquierda < sumaDerecha && derecha && izquierda) {
			suma = sumaDerecha + sumaIzquierda;
			return true;
		}
		else {
			return false;
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int row, col;
	std::cin >> row >> col;


	if (!std::cin) return false;

	std::vector<std::vector<int>> datos(row);
	int aux;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			std::cin >> aux;
			datos[i].push_back(aux);
		}
	}

	bool solucion = true;

	for (int i = 0; i < row && solucion; ++i) {
		int suma = 0;
		solucion = resolver(datos[i], 0, col - 1, suma);
	}

	// escribir sol
	if (solucion) std::cout << "SI";
	else std::cout << "NO";
	std::cout << std::endl;

	return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
  /*  #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
 /*    #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
	system("PAUSE");

    
    return 0;
}