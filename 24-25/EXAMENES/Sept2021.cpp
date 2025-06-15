// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v, int const & k) {
    int positivosDcha=0, positivosIzq=0, intervalos=0;
    for (int i = 0; i < k; i++)
    {
        if (i < k/2) {
            if (v[i] >= 0) positivosIzq++;
        }
        else {
            if (v[i] >= 0) positivosDcha++;
        }
    }

    if (positivosIzq >= positivosDcha) intervalos++;

    for (int i = k; i < v.size(); i++)
    {
        if (v[i - k] >= 0) positivosIzq--;
        if (v[i - (k / 2)] >=0) {
            positivosIzq++;
            positivosDcha--;
        }
        if (v[i] >= 0) {
            positivosDcha++;
        }

        if (positivosIzq >= positivosDcha) intervalos++;
    }
    return intervalos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k, elem; cin >> n >> k;
    vector<int> v;
    if (n==0)
        return false;

    for (int i = 0; i < n; i++)
    {
        cin >> elem;
        v.push_back(elem);
    }
    cout << resolver(v, k);

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
