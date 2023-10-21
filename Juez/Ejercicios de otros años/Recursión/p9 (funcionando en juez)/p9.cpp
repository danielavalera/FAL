// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& datos, int ini, int fin) {
	if (ini == fin - 1) return datos[ini]; //1 elemento
	else if (datos[ini] % 2 != 0) return datos[ini]; //primero impar
	else if (datos[fin-1] % 2 != 0) return datos[fin-1]; //ultimo impar
	else {
		int mitad = (ini + fin-1) / 2;
		if (datos[mitad] < ((datos[ini] + datos[fin - 1]) / 2)) return resolver(datos, ini, mitad+1); //mitad menor que numero de en medio
		else return resolver(datos, mitad, fin); //mitad mayor o igual al numero de en medio
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int capacidad;
	std::cin >> capacidad;
	std::vector<int> datos(capacidad);
	for (int i = 0; i < capacidad; ++i) std::cin >> datos[i];
    if (capacidad==0)
        return false;
    
    int sol = resolver(datos,0,capacidad);
    
    // escribir sol
	std::cout << sol << std::endl;
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