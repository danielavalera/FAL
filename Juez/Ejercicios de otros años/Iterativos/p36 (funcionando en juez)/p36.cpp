// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> & datos) {
	int j = 0;
	for (int i = 0; i < datos.size(); ++i) {
		if (datos[i] % 2 == 0) {
			datos[j] = datos[i];
			++j;
		}
	}
	datos.resize(j);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int elementos;
	std::cin >> elementos;
	std::vector <int> datos(elementos);
	for (int &i : datos) std::cin >> i;
    resolver(datos);
    // escribir sol
	for (int i = 0; i < datos.size();++i) std::cout << datos[i] <<" ";
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