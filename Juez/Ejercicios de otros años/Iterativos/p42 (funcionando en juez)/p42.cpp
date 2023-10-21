// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
// Coste = longitud del vector
int resolver(std::vector<int> const& datos) {
	int posMax = - 1;
	int numCeros = 0, numUnos = 0;
	for (int i = 0; i < datos.size(); i++)
	{
		if (datos[i] == 0) ++numCeros;
		else if (datos[i] == 1) ++numUnos;
		if (numCeros == numUnos && i > posMax) posMax = i;
	}

	return posMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int longitud;
	std::cin >> longitud;
	std::vector<int> v(longitud);
	for (int& i : v) std::cin >> i;
    // escribir sol
	std::cout << resolver(v) << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
 /*   #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
  /*   #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
    
	system("PAUSE");
    return 0;
}