// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const& datos, int ini, int fin, int & min, int & max) {
	if (fin <= ini) return true; //Un elemento
	else if (ini == fin - 1) {// 2 elementos
		if (datos[ini] <= datos[fin]) {//parcialmente ordenados
			min = datos[ini];
			max = datos[fin];
			return true;
		}
		else {
			return false; 
		}
	}
	else {//Mas de 2 elementos
		int mitad = (ini + fin) / 2;
		int minDerecha, minIzquierda, maxDerecha, maxIzquierda;

		bool derecha = resolver(datos, mitad + 1, fin, minDerecha, maxDerecha);//Vemos el min y max de la derecha
		bool izquierda = resolver(datos, ini, mitad, minIzquierda, maxIzquierda);//Vemos el min y max de la izquierda

		if (derecha && izquierda) { //Si las mitades están parcialmente ordenadas seguimos
			if (minIzquierda <= minDerecha && maxIzquierda <= maxDerecha ) { //Vemos que se cumplan las condiciones de parcialmente ordenado
				max = maxDerecha;//max esta en la derecha por definicion
				min = minIzquierda;//min esta en la izquierda por definicion
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::vector <int> v;
	int i;
	std::cin >> i;

	if (i == 0) return false;

	while (i != 0) {
		v.push_back(i);
		std::cin >> i;
	}

	int min, max;
	bool solucion = resolver(v, 0, v.size() - 1, min, max);

	// escribir sol
	if (solucion) std::cout << "SI";
	else std::cout << "NO" ;
	std::cout << std::endl;

	return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
  /*  #ifndef DOMJUDGE
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
	system("PAUSE");

    
    return 0;
}