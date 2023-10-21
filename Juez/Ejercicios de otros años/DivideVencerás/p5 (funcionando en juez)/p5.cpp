// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector<int> v,int ini, int fin) {

	if (ini == (fin-1)) {// Un solo valor
		return v[ini]; 
	}
	else if ((v[(ini + fin) / 2] > v[(ini + fin) / 2 - 1])) {// Valor mitad mayor que izquierda
		return resolver(v, ini, (ini + fin) / 2);
	}
	else if (v[(ini + fin) / 2] > v[(ini + fin) / 2 + 1]){// Valor mitad mayor que derecha
		return resolver(v, (ini + fin) / 2,fin);
	}
	else {// Hemos encontrado la posicion buscada
		return v[(ini + fin) / 2];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int capacidad;
	std::cin >> capacidad;
	std::vector<int> datos(capacidad);
	if (!std::cin)
		return false;
	for (int &i : datos) std::cin >> i;
    
    int sol = resolver(datos,0,capacidad);
    
    // escribir sol
	std::cout << sol << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /* #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
    /* #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
	system("PAUSE");
    return 0;
}