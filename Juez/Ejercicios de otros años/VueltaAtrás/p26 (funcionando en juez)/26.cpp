// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


bool esValida(std::vector <int> sol, int const k, std::vector <std::string> const& tipoJuguetes, std::vector <std::vector <int>> const& satisNino, std::vector <int> const& udDisponibles,int const satisfacion, std::vector <std::vector <bool>> const& marcaNino) {
	int posAct = sol[k];
	if (udDisponibles[posAct] < 0) return false;
	if (k % 2 != 0)
	{
		int posAnt = sol[k - 1];
		if (tipoJuguetes[posAct] == tipoJuguetes[posAnt]) return false;
		if (satisNino[(k -1)/2][posAct] + satisNino[(k - 1) / 2][posAnt] < satisfacion) return false;
	}
	return true;
}


//añadimos la tira al vector


// función que resuelve el problema
void resolver(std::vector <int> sol, std::vector <int> udDisponibles, std::vector <std::string> const& tipoJuguetes, std::vector <std::vector <int>> const& satisNino, int const satisfacion, std::vector <std::vector <bool>> marcaNino, int k, bool & solucion) {
	for (int i = 0; i < tipoJuguetes.size(); i++){
		if ((k % 2 == 0 && !marcaNino[k / 2][i]) || (k % 2 != 0 && !marcaNino[(k - 1) / 2][i])) {
			sol[k] = i;
			udDisponibles[i]--;
			if (esValida(sol, k, tipoJuguetes, satisNino, udDisponibles, satisfacion, marcaNino)) {
					if (k == sol.size() - 1) {
						for (int i = 0; i < sol.size(); i++) {
							std::cout << sol[i] << " ";
						}
						std::cout << std::endl;
						solucion = true;				
					}
					else {
						if (k % 2 == 0) marcaNino[k / 2][i] = true;
						else marcaNino[(k - 1) / 2][i] = true;

						resolver(sol, udDisponibles, tipoJuguetes, satisNino, satisfacion, marcaNino, k + 1, solucion);
					}
			}
			udDisponibles[i]++;
		}
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int m, n, satisfacion;
	std::cin >> m >> n >> satisfacion;
    if (! std::cin)
        return false;

	std::vector <int> udDisponibles(m);
	for (int &i : udDisponibles) std::cin >> i;
	
	std::vector <std::string> tipoJuguetes(m);
	for (std::string &i : tipoJuguetes) std::cin >> i;
	
	std::vector <std::vector <int>> satisNino(n, std::vector <int>(m));
	for (int i = 0; i < n;++i)
		for (int j = 0; j < m; ++j) std::cin >> satisNino[i][j];
	
	std::vector <int> sol(n*2);
	std::vector <std::vector <bool>> marcaNino(n, std::vector <bool>(m));
	bool solucion = false;
    // escribir sol
	resolver(sol, udDisponibles, tipoJuguetes, satisNino, satisfacion, marcaNino, 0, solucion);
	if (!solucion) std::cout << "SIN SOLUCION" << std::endl;
	std::cout << std::endl;
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
	//system("PAUSE");
    return 0;
}