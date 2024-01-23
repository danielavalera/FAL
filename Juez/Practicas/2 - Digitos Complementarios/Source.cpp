// Cristian García Moruno F42
// Daniela Valentina Valera Fuentes F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


/*
* Si aplicamos el Teorema de la división a partir de la función de recurrencia obtenemos que el coste asintótico de la función recursiva será del orden 0(logn), 
* donde n es el valor de entrada. 
* 
* T1(n) = c0              si n=1
* T1(n) = c1 * T(n-1)     si n>1
* 
* Siendo n el número de cifras
* 
* 
* T2(n) = c0              si n=0
* T2(n) = c1 * T(n-1)     si n>0
* 
* Siendo n el número de cifras
*/
int complementario(int n) {
    if (n < 10) return 9 - n;
    else {
        int complementarioSinUnidades = complementario(n / 10);
        int complementarioUnidades = 9 - n % 10;
        return complementarioSinUnidades * 10 + complementarioUnidades;
    }
}

int inversoComplementario(int n, int m) {
    if (n <10 && m==0) return 9 - n;
    else if (n == 0) return m;
    else return inversoComplementario(n / 10, m * 10 + (9 - (n % 10)));
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	// escribir sol
	cout << complementario(n) << " " << inversoComplementario(n, 0) << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}