// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
//coste = O(n*n*p)
/*int resolver(std::vector< std::vector<int> > const& datos, int const& p) {
	int suma = 0, sumaMax = 0, sumaIni = 0;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			sumaIni += datos[i][j];
		}
	}
	suma = sumaIni;
	for (int i = 0; i < datos.size() - p; i++) {
		for (int j = 0; j < datos.size() - p; j++) {
			for (int k = i; k < i + p; k++) {
				suma -= datos[k][j];
				suma += datos[k][j + p];
				if (suma > sumaMax) sumaMax = suma;
			}
		}
		for (int k = 0; k < p; k++) {
			sumaIni -= datos[i][k];
			sumaIni += datos[i + p][k];
		}
		suma = sumaIni;
		if (suma > sumaMax) sumaMax = suma;
	}
	return sumaMax;
}*/

int resolver(std::vector< std::vector<int> > const& datos, int const& p) {
	int  suma = 0, sumaIni = 0,  sumaMax = 0, ini = 0;
	bool final = false, haciaDerecha = true;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			suma += datos[i][j];
		}
	}
	sumaIni = suma;
	sumaMax = suma;
	for (int i = p - 1; i < datos.size(); i++)
	{
		if (i >= p)
		{
			for (int j = 0; j < p; j++)
			{
				sumaIni -= datos[i - p][j];
				sumaIni += datos[i][j];
			}
			++ini;
			suma = sumaIni;
			if (suma > sumaMax) sumaMax = suma;
		}
		for (int j = p; j < datos.size(); j++)
		{
			for (int k = ini; k < ini + p; k++)
			{
				suma -= datos[k][j - p];
				suma += datos[k][j];
			}
			if (suma > sumaMax) sumaMax = suma;
		}
	}
	return sumaMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, p;
	std::cin >> n >> p;
	if (!std::cin)
		return false;
	std::vector< std::vector<int> > matriz(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> matriz[i][j];

	// escribir sol
	std::cout << resolver(matriz, p) << std::endl;

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
	/*   #ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif	*/
	system("PAUSE");

	return 0;
}