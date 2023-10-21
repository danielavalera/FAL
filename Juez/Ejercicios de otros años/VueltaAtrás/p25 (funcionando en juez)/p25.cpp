// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esValida(std::vector <int> const& auxBombillas, int const k, std::vector <int> const& tira,  int const luces) {
	if (k > 1 && tira[k] == tira[k - 1] && tira[k - 1] == tira[k - 2])
		return false;

	if (auxBombillas[tira[k]] > (luces - auxBombillas[tira[k]]) + 1)
		return false;

	return true;
}
//añadimos la tira al vector


// función que resuelve el problema
void resolver(int & sol, int const longitud,int const maxConsumo, int k,int consumo, int luces, std::vector <int> const & bombillas, std::vector <int> auxBombillas, std::vector <int> tira) {
	for (int i = 0; i < bombillas.size(); i++)
	{
		tira[k] = i;
		++auxBombillas[i];
		consumo += bombillas[i];
		++luces;
		if (esValida(auxBombillas,k,tira,luces)){
			if (k == longitud - 1){
				if (consumo <= maxConsumo)
					++sol;
			}
			else{
				resolver(sol, longitud, maxConsumo, k + 1, consumo,luces, bombillas, auxBombillas, tira);
			}	
		}
		consumo -= bombillas[i];
		--auxBombillas[i];
		--luces;
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int longitud, tamColores, maxConsumo;
	std::cin >> longitud >> tamColores >> maxConsumo;
	std::vector <int> colores(tamColores), auxColores(tamColores), tira(longitud);
	for (int i = 0; i < tamColores; i++) {
		std::cin >> colores[i];
		auxColores[i] = 0;
	}
	int sol = 0;
    if (! std::cin)
        return false;
    resolver(sol,longitud,maxConsumo,0,0,0,colores,auxColores,tira);
	
    
    // escribir sol
	std::cout << sol << std::endl;
/*	if (sol.size() == 0)
	{
		std::cout << "SIN SOLUCION" << std::endl;
	}
	else
	{
		for (int i = 0; i < sol.size(); i++) {
			for (int j = 0; j < longitud; j++)
				std::cout << sol[i][j] << " ";
			std::cout << std::endl;
		}	
	}
    return true;
    */
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
  /*   #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
    
    return 0;
}