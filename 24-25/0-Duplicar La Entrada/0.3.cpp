// Daniela Valentina Valera Fuentes
// Usuario del Juez FAL-E65


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int>& datos) {
    for (int i = 0; i < datos.size(); i++)
    {
        datos[i] = datos[i] * 2;
    }
    return datos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;
    if (n == -1)
        return false;

    int e;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        cin >> e;
        v.push_back(e);
    }

    vector<int> sol = resolver(v);
    // escribir sol
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("0.3.txt");
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
