// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
	int sumaSecuencia, posIni, longitud;
};

// función que resuelve el problema
//coste == datos.size()

tDatos resolver(std::vector<int> const& datos) {
	int suma = 0, sumaMax = suma, ini = 0, iniMax = ini, longitud = 0, longitudMax = longitud;
	for (int i = 0; i < datos.size(); i++) {
		suma += datos[i];
		++longitud;
		if (suma > 0) {
			if (suma > sumaMax || (suma == sumaMax && longitud < longitudMax)) {
				sumaMax = suma;
				iniMax = ini;
				longitudMax = longitud;
			}
		}
		else {
			suma = 0;
			longitud = 0;
			ini = i + 1;
		}
	}
	return { sumaMax, iniMax, longitudMax };
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int longitud;
	std::cin >> longitud;
    if (! std::cin)
        return false;
	std::vector<int> datos(longitud);
	for (int& i: datos) std::cin >> i;
    
    tDatos sol = resolver(datos);
    
    // escribir sol
	std::cout << sol.sumaSecuencia << " " << sol.posIni << " " << sol.longitud << std::endl;

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
  /*   #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif	*/
	system("PAUSE");

    return 0;
}