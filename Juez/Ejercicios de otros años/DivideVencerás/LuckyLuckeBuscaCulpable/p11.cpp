// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolverIz(std::vector <int> const & datos, int ini, int fin,int dato) {
	if (ini >= fin) return ini; // vacio
	else { 
		int mitad = (ini + fin) / 2;
		if (datos[mitad] < dato) return resolverIz(datos,mitad+1, fin,dato);
		else return resolverIz(datos, ini, mitad,dato); 
	}
}
int resolverDr(std::vector <int> const & datos, int ini, int fin, int dato) {
	if (ini >= fin && datos[ini] == dato) return ini; // vacio
	else if (ini >= fin && datos[ini] != dato) return ini - 1; // 1 elemento
	else { 
		int mitad = (ini + fin) / 2;
		if (datos[mitad] > dato) return resolverDr(datos,ini, mitad, dato);
		else return resolverDr(datos, mitad+1, fin, dato);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int tam, numero;
	std::cin >> tam;
	if (!std::cin) return false;
	std::cin >> numero;
	std::vector <int > datos(tam);
	for (int& i : datos) std::cin >> i;
	// Busca en el lado izquierdo
	int posIz = resolverIz(datos, 0, tam - 1, numero);
	if (datos[posIz] != numero)
		std::cout << "NO EXISTE"  << std::endl;
	else {
		// Si existe el elemento busca en el lado derecho
		int posDr = resolverDr(datos, 0, tam - 1, numero);
		if (posIz == posDr) std::cout << posIz << std::endl;
		else std::cout << posIz << " " << posDr << std::endl;
	}
	return true ;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /*#ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     /*#ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif*/
    
    return 0;
}