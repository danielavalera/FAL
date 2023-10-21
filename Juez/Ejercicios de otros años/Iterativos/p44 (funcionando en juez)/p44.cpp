// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tDatos {
	std::vector<int> datos;
	int seqMax;
};

// función que resuelve el problema
//coste == datos.size()
tDatos resolver(std::vector<int> const& datos,int const& llano) {
	std::vector<int> retorno;
	int comienzoSeq = datos.size() - 1;
	int numSeq = 0;
	int seqMax = 0;
	int valorMasAlto = 0;
	for (int i = datos.size() - 1; i >= 0; i--)
	{
		if (datos[i] > valorMasAlto) {//Empezamos secuencia valida por altura
			valorMasAlto = datos[i];
			comienzoSeq = i;
			numSeq = 1;
		}
		else if (datos[i] == datos[comienzoSeq]) ++numSeq; //seguimos la secuencia para ver si es valida
		else numSeq = 0; //secuencia no valida

		if (numSeq >= llano) { //La secuencia cumple los requisitos de altura y tamaño
			if (retorno.size() == 0 || retorno[retorno.size() - 1] != comienzoSeq) retorno.push_back(comienzoSeq); // si no está ya añadida la añadimos
			if (numSeq > seqMax) seqMax = numSeq; //Vemos la secuencia maxima encontrada
		}
	}
	return { retorno,  seqMax };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int longitud, llano;
	std::cin >> longitud >> llano;
    if (! std::cin)
        return false;
	std::vector<int> datos(longitud);
	for (int& i: datos) std::cin >> i;
    
    tDatos sol = resolver(datos,llano);
    
    // escribir sol
	std::cout << sol.seqMax << " " << sol.datos.size() << " ";
	for (int i = 0; i < sol.datos.size(); i++) std::cout << sol.datos[i] << " ";
	std::cout << std::endl;

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