// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int>& v) {
    int minElem = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < minElem) {
            minElem = v[i];
        }

        
    }

    return true; // es minimalista
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nSec, elementos;
    cin >> nSec;
    if (nSec == -1)
        return false;

    vector<int> v;
    int count = 0;
    for (int i = 0; i < nSec; i++)
    {
        cin >> elementos;
        v.push_back(elementos);
    }

    // escribir sol
    if (resolver(v)) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.3.txt");
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
