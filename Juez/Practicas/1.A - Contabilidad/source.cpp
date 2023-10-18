// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(vector<int> v) {
    int suma = 0;
    for (int i = v.size()-1; i >= 0; i--) //empiezas la suma desde la posición final del vector
    {
        if (v[i] == suma)
            return true;
        suma += v[i];
    }

    return false;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nSec; cin >> nSec;
    if (nSec == 0)
        return false;

    vector<int> v(nSec);
    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    bool sol = resolver(v);
    // escribir sol
    if (sol) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datosEv1A.txt");
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
