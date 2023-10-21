// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
	int ini, fin;
};

// función que resuelve el problema
// Coste = t
tSol resolver(std::vector<int> const& datos, const int t) {
	int ini=0,tam=0;
	int j=0;
	for (int i = 0; i < datos.size(); i++){
		if (t < datos[i]) {
			++j;
			if (j > tam) {
				ini = i - j + 1;
				tam = j;
			}
		}
		else {
			j = 0;
		}
	}
	return {ini, ini + tam - 1 };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int elementos, t;
	std::cin >> elementos >> t;
	std::vector <int> datos(elementos);
	for (int &i : datos) std::cin >> i;
    // escribir sol
	tSol solucion = resolver(datos, t);
	std::cout << solucion.ini << " " << solucion.fin << std::endl;
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