// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
//coste = O(n*m)
int resolver(std::vector< std::vector<int> > const& datos) {
	int validos = 0;
	for (int i = 0; i < datos.size(); i++){
		for (int j = 0; j < datos[0].size(); j++)
		{
			if (datos[i][j] == i) ++validos;
		}
		
	}
	return validos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int filas,columnas;
	std::cin >> filas >> columnas;
    if (! std::cin)
        return false;
	std::vector< std::vector<int> > m(filas, std::vector<int>(columnas));
	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			std::cin >> m[i][j];
    
    // escribir sol
	std::cout << resolver(m) << std::endl;

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