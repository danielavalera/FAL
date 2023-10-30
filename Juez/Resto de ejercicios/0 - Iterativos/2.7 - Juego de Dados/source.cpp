// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
vector<int> resolver(int nTiradas, int nMax, int&max) {
    int n;
    vector<int> v2(nMax, 0);
    
    for (int i = 0; i < nTiradas; i++)
    {
        cin >> n;
        v2[n - 1]++;
        if (max < v2[n - 1]) {
            max = v2[n - 1];
        }
    }

    return v2;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nTiradas, nMax;
    cin >> nTiradas >> nMax;
    if (nTiradas == -1)
        return false;

    int max = 0;
    vector<int> sol = resolver(nTiradas, nMax, max);
    
    // escribir sol
    for (int i = sol.size() - 1; i >= 0; i--)
    {
        if (sol[i] == max)
            cout << i + 1 << ' ';
    }
    cout << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.7.txt");
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
