// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>

// función que resuelve el problema
void resolver(std::vector <std::vector <int>> const& datos,int const m,  int const n, std::vector <int> &marcas, int suma, int & solMejor, int k) {
	for (int i = 0; i < m; i++){
		if (marcas[i] < 3) {
			suma += datos[i][k];
			if (suma < solMejor) {
				if (k == n - 1) {
					solMejor = suma;
				}
				else {
					marcas[i]++;
					resolver(datos, m, n, marcas, suma, solMejor, k + 1);
					marcas[i]--;
				}
			}
			suma -= datos[i][k];
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int m, n;
	std::cin >> m >> n;
	std::vector <std::vector <int>> datos(m, std::vector <int>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> datos[i][j];
		}
	}
	int solMejor = std::numeric_limits<int>::max();
	std::vector <int> marcas(m);
    resolver(datos,m,n,marcas, 0, solMejor, 0);
    // escribir sol
	if (solMejor == std::numeric_limits<int>::max()) std::cout << "Sin solucion factible";
	else std::cout << solMejor;
	std::cout << std::endl;
    
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