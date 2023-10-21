// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>

// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const& v,int const N, int k, std::vector<bool> trabajo, std::vector<bool> funcionario, int asignacion_actual, int & asignacion_optima) {
	for (int i = 0; i < N; i++){
		if (!trabajo[i]){
			for (int j = 0; j < N; j++){
				if (!funcionario[j]){
					asignacion_actual += v[j][i];
					trabajo[i] = true;
					funcionario[j] = true;

					if (k == N - 1) {
						if (asignacion_actual < asignacion_optima) asignacion_optima = asignacion_actual;
					}
					else resolver(v, N, k + 1, trabajo, funcionario, asignacion_actual, asignacion_optima);

					asignacion_actual -= v[j][i];
					trabajo[i] = false;
					funcionario[j] = false;
				}
				
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int N;
	std::cin >> N;
    if (N==0)
        return false;
    
	std::vector<std::vector<int>> funcionarios(N, std::vector<int>(N));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			std::cin >> funcionarios[i][j];
		}
	}
	std::vector<bool> trabajo(N), funcionario(N);
	for (int i = 0; i < N; i++) {
		trabajo[i] = false;
		funcionario[i] = false;
	}

	int sol = std::numeric_limits<int>::max();
	resolver(funcionarios, N, 0, trabajo, funcionario, 0, sol);
	std::cout << sol << '\n';
    
    // escribir sol
    
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