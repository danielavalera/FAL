// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& datos,int ini, int fin, int numero) {
	if (ini == fin ) return -1;//Si no tiene solucion posible, vacío
	else {
		int m = (ini + fin - 1) / 2;
		if ((m + numero) == datos[m]) return datos[m]; //Si la posicion mas el numero coincide, devolvemos el valor
		else if ((m + numero) > datos[m]) return resolver(datos, m+1, fin, numero); //El numero buscado es mayor que la mitad
		else return resolver(datos, ini,m,numero); //El numero es menor que la mitad
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numeros, cantado;
	std::cin >> numeros >> cantado;
	std::vector<int> datos(numeros);
	for (int &i : datos) std::cin >> i;
	int sol = resolver(datos, 0, numeros,cantado);
	// escribir sol
	if (sol==-1) std::cout <<  "NO" << std::endl;
	else 
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

	return 0;
}