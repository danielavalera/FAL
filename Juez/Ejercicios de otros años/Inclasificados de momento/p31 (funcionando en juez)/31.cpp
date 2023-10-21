// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>



// función que resuelve el problema
void resolver(std::vector<std::vector<int>> const& m, std::vector<int> const v_actores,int const n, int const k, int const p, int const punt_min,
				int act, std::vector<bool> actores, 
				int punt_actual, int presupuesto_actual, std::vector<int> asignacion_actual, int &punt_mejor, int &presupuesto_mejor, std::vector<int> &asignacion_mejor) {
	if (act == n){
		if (punt_actual >= punt_min && punt_actual > punt_mejor){
			punt_mejor = punt_actual;
			presupuesto_mejor = presupuesto_actual;
			for (int i = 0; i < n; i++) asignacion_mejor[i] = asignacion_actual[i];
		}
	}
	else {
		for (int i = 0; i < k; i++) {
			if (!actores[i]){
				asignacion_actual[act] = i;
				punt_actual += m[act][i];
				presupuesto_actual += v_actores[i];
				actores[i] = true;
				if (presupuesto_actual <= p) 
					resolver(m, v_actores, n, k, p, punt_min, act + 1, actores, 
						punt_actual, presupuesto_actual, asignacion_actual, punt_mejor, presupuesto_mejor, asignacion_mejor);
				actores[i] = false;
				presupuesto_actual -= v_actores[i];
				punt_actual -= m[act][i];
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, k, p, punt_min;
	std::cin >> n >> k >> p >>punt_min;
    if (n == 0 && k == 0 && p == 0 && punt_min == 0)
        return false;
    
	std::vector<std::vector<int>> actores_papel(n, std::vector<int>(k));
	std::vector<int> actores(k);
	std::vector<bool> papeles(k);

	for (int i = 0; i < k; i++) {
		std::cin >> actores[i];
		papeles[i] = false;
	}
	for (int i = 0; i < n; i++){
		papeles[i] = false;
		for (int j = 0; j < k; j++){
			std::cin >> actores_papel[i][j];
		}
	}

	

	int punt_mejor = 0, presupuesto_mejor = 0;
	std::vector<int> asignacion(n);
	resolver(actores_papel, actores, n, k, p, punt_min, 0, papeles, 0, 0, std::vector<int>(n), punt_mejor, presupuesto_mejor, asignacion);
	if (punt_mejor == 0 && presupuesto_mejor == 0) {
		std::cout << "0 0\n";
	}
	else {
		std::cout << punt_mejor << " " << presupuesto_mejor << '\n';
		for (int i = 0; i < n; i++) std::cout << i << " " << asignacion[i] << '\n';
	}
	
    
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