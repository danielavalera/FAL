// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
//coste = O(n*m+m)

/*int resolver(std::vector< std::vector<int> > const& datos, int const& k, int const& y, int const& x) {
int i = 0, j = 0, numCeros = 0, contadorY = 0, iniK = 0, validos = 0;
std::vector <bool> cumple(datos[j].size());
while (i < datos[j].size()) { //recorremos la matriz por columnas
while (j < datos.size() && numCeros < x) { // comprobar que haya los ceros buscados en las n columnas, no siempre se recorren enteras
if (datos[j][i] == 0) ++numCeros;
++j;
}
cumple[i] = numCeros == x; // si están los ceros ponemos true en esa columna
if (cumple[i]) ++contadorY;	//si es true la añadimos a nuestro contador de columnas validas en esa franja
if (contadorY == y) ++validos; // si las columnas validas coinciden con la "y" pedida sumamos una combinacion valida
if (i + 1 - iniK == k) { //recorremos la ventana
if (cumple[iniK]) --contadorY;
++iniK;
}
numCeros = 0;
j = 0;
++i;
}
return validos;
}*/

int resolver(std::vector< std::vector<int> > const& datos, int const n, int const m, int const k, int const y, int const x) {
	std::vector <int> numCeros(m);
	int contador = 0, validos = 0, aux = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (datos[j][i] == 0) ++contador;
		}
		numCeros[i] = contador;
		contador = 0;
	}
	for (int i = 0; i < k; i++) {
		if (numCeros[i] >= x) ++aux;
	}
	if (aux >= y) ++validos;
	for (int i = k; i < m; i++){
		if (numCeros[i] >= x) ++aux;
		if (numCeros[i - k] >= x) --aux;
		if (aux >= y) ++validos;
	}
	return validos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, m, k, y, x;
	std::cin >> n >> m >> k >> y >> x;
	if (!std::cin)
		return false;
	std::vector< std::vector<int> > matriz(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> matriz[i][j];

	// escribir sol
	std::cout << resolver(matriz, n, m, k, y, x) << std::endl;

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