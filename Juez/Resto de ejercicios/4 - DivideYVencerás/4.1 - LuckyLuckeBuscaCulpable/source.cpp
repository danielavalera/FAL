// DANIELA VALENTINA VALERA FUENTES
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolverIz(vector <int> const& datos, int ini, int fin, int dato) {
	if (ini >= fin) 
		return ini; // vacio
	else {
		int mitad = (ini + fin) / 2;
		if (datos[mitad] < dato) 
			return resolverIz(datos, mitad + 1, fin, dato);
		else 
			return resolverIz(datos, ini, mitad, dato);
	}
}
int resolverDr(vector <int> const& datos, int ini, int fin, int dato) {
	if (ini >= fin && datos[ini] == dato) 
		return ini; // vacio
	else if (ini >= fin && datos[ini] != dato) 
		return ini - 1; // 1 elemento
	else {
		int mitad = (ini + fin) / 2;
		if (datos[mitad] > dato) 
			return resolverDr(datos, ini, mitad, dato);
		else 
			return resolverDr(datos, mitad + 1, fin, dato);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam, numero; cin >> tam >> numero;
	if (!std::cin) 
		return false;

	vector <int> datos(tam);
	for (int i = 0; i < datos.size(); i++){
		cin >> datos[i];
	}

	// Busca en el lado izquierdo
	int posIz = resolverIz(datos, 0, tam - 1, numero);
	if (datos[posIz] != numero)
		cout << "NO EXISTE" << '\n';
	else {
		// Si existe el elemento busca en el lado derecho
		int posDr = resolverDr(datos, 0, tam - 1, numero);
		if (posIz == posDr) 
			cout << posIz << '\n';
		else 
			cout << posIz << " " << posDr << '\n';
	}
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
	#ifndef DOMJUDGE
	std::ifstream in("datos4.1.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
	#endif


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
	#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
	#endif

	return 0;
}