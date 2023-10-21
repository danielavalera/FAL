// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> const& dias, std::vector<int> const& abrigos,int const n, int const a, int k, int anterior, int primero, std::vector<int> & marcas, int &sol) {
	for (int i = 0; i < a; i++){
		if (k == 0) primero = i;
		if (i != anterior){
			if (marcas[i] < 2 + k / 3) {
				if (dias[k] <= abrigos[i]) {
					if (k == n - 1) {
						if(primero != i) sol++;
					}
					else {
						marcas[i]++;
						resolver(dias, abrigos, n, a, k + 1, i, primero, marcas, sol);
						marcas[i]--;
					}
				}
			}
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, a, sol = 0;
	std::cin >> n >> a;
	if (n == 0 && a == 0)
		return false;
	std::vector<int> dias(n), abrigos(a), marcas(a);
	for (int i = 0; i < n; i++) std::cin >> dias[i];
	for (int i = 0; i < a; i++) std::cin >> abrigos[i];

    resolver(dias, abrigos, n, a, 0, -1, -1 ,marcas, sol);
	if (sol == 0) std::cout << "Lo puedes comprar\n";
	else std::cout << sol << '\n';
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