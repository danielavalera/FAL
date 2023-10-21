// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

enum piedrasPreciosas { diamante, rubi, esmeralda, zafiro, jade };

std::istream& operator>> (std::istream& entrada, piedrasPreciosas& p) {
	char num;
	entrada >> num;
	switch (num) {
	case 'd': p = diamante; break;
	case 'r': p = rubi; break;
	case 'e': p = esmeralda; break;
	case 'z': p = zafiro; break;
	case 'j': p = jade; break;
	}
	return entrada;
}

struct tEntrada{
	int numpiedras, numtipo1, numtipo2; 
	long int  tam;
	piedrasPreciosas tipo1, tipo2;
};

// función que resuelve el problema
// Coste = piedrasPreciosas.size()
int resolver(std::vector<piedrasPreciosas> const& datos, tEntrada const& e) {
	int tipo1aux = 0, tipo2aux = 0, combinaciones = 0;
	for (int i = 0; i < e.tam; i++) {
		if (datos[i] == e.tipo1) ++tipo1aux;
		else if (datos[i] == e.tipo2) ++tipo2aux;
	}
	if (tipo1aux >= e.numtipo1 && tipo2aux >= e.numtipo2) ++combinaciones;
	for (int i = e.tam; i < datos.size(); i++) {
		if (datos[i] == e.tipo1) ++tipo1aux;
		else if (datos[i] == e.tipo2) ++tipo2aux;
		if (datos[i - e.tam] == e.tipo1) --tipo1aux;
		else if (datos[i - e.tam] == e.tipo2) --tipo2aux;
		if (tipo1aux >= e.numtipo1 && tipo2aux >= e.numtipo2) ++combinaciones;
	}
	return combinaciones;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	tEntrada e;
	std::cin >> e.numpiedras >> e.tam >> e.tipo1 >> e.numtipo1 >> e.tipo2 >> e.numtipo2;
	std::vector<piedrasPreciosas> v(e.numpiedras);
	for (piedrasPreciosas& i : v) std::cin >> i;
    // escribir sol
	std::cout << resolver(v, e) << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
 /*   #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
  /*   #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
    
	system("PAUSE");
    return 0;
}

/*
4
6 3 d 1 z 1
r d z e d z
7 3 e 2 j 1
e j e r e e j
5 2 r 1 z 0
d z j r e
7 4 z 2 r 1
z r d z z r e

*/