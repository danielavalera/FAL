// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int>& v, int l) {
    int c = 0, u = 0; //nº de ceros y unos
    int nInter = 1; //nº intervalos. Inicialmente hay 1.

    for (int i = l; i < v.size(); i++) //empiezas en l xq dice que en el 1er intervalo no hay 0's ni 1's
    {
        if (v[i] == 0)
            ++c;
        if (v[i] == 1)
            ++u;
        if (v[i-l] == 0)
            --c;
        if (v[i-l] == 1)
            --u;
        if (c == u) // si en el mismo nº, contamos un intervalo más
            ++nInter;
    }

    return nInter;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int secuencia, nElems, n;
    cin >> secuencia >> nElems;
    vector<int> v;

    for (int i = 0; i < nElems; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    int sol = resolver(v, secuencia);
    // escribir sol

    cout << sol << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.4.txt");
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