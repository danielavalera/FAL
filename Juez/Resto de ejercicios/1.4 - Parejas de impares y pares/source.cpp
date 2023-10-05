// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int>& v) {

    int contParejas = 0;
    int imparesEncontrados = 0;

    for (int i = 0; i < v.size(); i++) {

        if ((v[i] % 2) == 0) {
            contParejas +=  imparesEncontrados;
        }
        else {
            imparesEncontrados++;
        }
    }

    return contParejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tVector; cin >> tVector;
    int n; 
    vector<int> v;

    for (int i = 0; i < tVector; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    int sol = resolver(v);
    // escribir sol
    cout << sol << endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos1.4.txt");
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