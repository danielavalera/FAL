// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema

int resolver(std::vector<int> const & v, int ini, int fin)
{
	if (ini >= fin) return 1; // 1 elemento
	else if (v[ini] == v[fin]) return 1; // Todos iguales
	else if (ini + 1 == fin) { // 2 elementos
		if (v[ini] == v[fin]) return 1;
		else return 2;
	}
	else { //más de 2 elementos
		int mitad = (fin + ini) / 2;
		int derecha = resolver(v, mitad + 1, fin); //calculamos izquierda
		int izquierda = resolver(v, ini, mitad); //calculamos derecha
		if (v[mitad] == v[mitad + 1]) return derecha - 1 + izquierda; //Si ambas mitades coinciden quitamos uno a la suma porque hemos calculado lo mismo en ambos lados
		else return derecha + izquierda; //Devolvemos la suma de los lados
	}
}



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
	std::vector<int> v(n);
    if (n==0)
        return false;
	for (int i = 0; i < n; ++i) std::cin >> v[i];
    
	int sol = resolver(v,0,n-1);
    
    // escribir sol
	std::cout << sol << std::endl;
    return true;
    
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
    /* #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif*/
	system("PAUSE");
    return 0;
}