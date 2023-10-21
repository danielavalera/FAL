// Nombre del alumno Antonio Lucas Simón
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector <int> const& datos, int ini, int fin, int const k) {
	if (ini >= fin) return true; //vacio o un elemento
	else if (ini == fin - 1) {// 2 elementos
		if (std::abs(datos[ini] - datos[fin]) >= k) return true; //formula de disperso
		else return false;
	}
	else {// Más de 2 elementos
		int mitad = (ini + fin) / 2;

		bool izquierda = resolver(datos, ini, mitad, k);
		bool derecha = resolver(datos, mitad + 1, fin, k);

		if (derecha && izquierda && std::abs(datos[ini] - datos[fin]) >= k) return true;
		else return false;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int longitud, k;
	std::cin >> longitud >> k;
    if (! std::cin)
        return false;
	std::vector <int> datos(longitud);
	for (int i = 0; i < longitud; i++) std::cin >> datos[i];
    
    // escribir sol
	if (resolver(datos, 0, longitud - 1, k)) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
 /*    #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
    
    return 0;
}