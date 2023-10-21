// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver( std::vector <int> const& datos,int &ini, int &fin) {
	if (datos[ini] < datos[fin]){

	}
	else if (datos[ini] > datos[fin]) {

	}
	else {
		int mitad = (fin - ini) / 2;
		if (datos[mitad]<datos[ini]) resolver(datos, mitad, fin);
		else resolver(datos, ini, mitad);
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam;
	std::cin >> tam;
    if (tam == 0)
        return false;
	std::vector <int> datos;
	for (int &i : datos) std::cin >> i;
	int ini = 0;
    bool sol = resolver(datos,ini,tam);
    // escribir sol
	if (sol) std::cout << "SI" << " " << ini << std::endl;
	else std::cout << "NO" << " " << ini << " " << tam << std::endl;
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
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