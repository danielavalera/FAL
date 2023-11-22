// DANIELA VALENTINA VALERA FUENTES
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int>& v, int ini, int fin) {
    if (ini + 1 == fin)
        return v[ini];
    else {
        int m = (ini + fin) / 2;
        if (v[m] > v[m - 1])
            return resolver(v, ini, m);
        else if (v[m] > v[m + 1])
            return resolver(v, m + 1, fin);
        else
            return v[m];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamVector; cin >> tamVector;
    if (!std::cin)
        return false;

    vector<int> v(tamVector);
    for (int i = 0; i < tamVector; i++){
        cin >> v[i];
    }

    // escribir sol
    cout << resolver(v, 0, tamVector) << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("CurvaConcava.txt");
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