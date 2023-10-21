// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector<int> const& datos, int ini, int fin) {
	if (ini >= fin) return -1; //vector vacio
	else if (ini == fin - 1) return datos[ini]; //1 elemento
	else {
		int mitad = (ini + fin - 1) / 2;
		//Como van en orden decreciente
		if (datos[ini]<datos[fin - 1]) { //Si el primero es menos que el ultimo
			if (datos[mitad] < datos[mitad + 1]) return datos[mitad];//Si la mitad es menor que el siguiente, lo hemos encontrado
			else if (datos[mitad] > datos[fin-1]) return resolver(datos, ini, mitad + 1);//Si la mitad es mayor que el ultimo, vamos a la izquierda
			else  return resolver(datos, mitad, fin);//Si la mitad  es menor que el ultimo, vamos a la derecha
		}
		else return datos[fin - 1]; //Si el ultimo es mayor que el primero, sabemos que ese es el valor buscado
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

bool resuelveCaso() {
	// leer los datos de la entrada
	int capacidad;
	std::cin >> capacidad;
	std::vector<int> datos(capacidad);
	for (int &i : datos) std::cin >> i;
	if (!std::cin)
		return false;

	int sol = resolver(datos, 0, capacidad);

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