// DANIELA VALENTINA VALERA FUENTES
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& datos, int ini, int fin, int numero) {
	if (ini == fin) 
		return -1;//Si no tiene solucion posible, vacío
	else {
		int m = (ini + fin - 1) / 2;
		if ((m + numero) == datos[m]) 
			return datos[m]; //Si la posicion mas el numero coincide, devolvemos el valor
		else if ((m + numero) > datos[m]) 
			return resolver(datos, m + 1, fin, numero); //El numero buscado es mayor que la mitad
		else 
			return resolver(datos, ini, m, numero); //El numero es menor que la mitad
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int numeros, cantado; cin >> numeros >> cantado;
	
	vector<int> datos(numeros);
	for (int i = 0; i < datos.size(); i++){
		cin >> datos[i];
	}

	int sol = resolver(datos, 0, numeros, cantado);
	// escribir sol
	if (sol == -1) 
		cout << "NO" << '\n';
	else
		cout << sol << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos4.7.txt");
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