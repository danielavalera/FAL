// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
string resolver(vector<string> p) {
    string primeraPalabraEnOrden = p[0];

    for (int i = 1; i < p.size(); i++)
    {
        if (p[i] < primeraPalabraEnOrden) {
            primeraPalabraEnOrden = p[i];
        }
    }

    return primeraPalabraEnOrden;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nPalabras;
    string palabra;
    vector<string> p;

    cin >> nPalabras;
    for (int i = 0; i < nPalabras; i++)
    {
        cin >> palabra;
        p.push_back(palabra);
    }

    string sol = resolver(p);

    // escribir sol
    cout << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos1.3.txt");
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