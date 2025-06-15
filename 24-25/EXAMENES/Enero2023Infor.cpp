// Nombre del alumno .....
// Usuario del Juez ......
using namespace std;

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(vector<int> const& v, int const& k) {
    int par=0, impar=0, count=0;
    if (k > v.size()) {
        return count;
    }
    else {
        for (int i = 0; i < k; i++)
        {
            if (v[i] % 2 == 0) par += v[i];
            if (v[i] % 2 != 0) impar += v[i];
        }

        if (par > impar) count++;

        for (int i = k; i < v.size(); i++)
        {
            if (v[i - k] % 2 == 0) par -= v[i - k];
            if (v[i - k] % 2 != 0) impar -= v[i - k];
            if (v[i] % 2 == 0) par += v[i];
            if (v[i] % 2 != 0) impar += v[i];

            if (par > impar) count++;
        }
        return count;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int l, tam, elem; cin >> l >> tam;
    vector<int> v;
    for (int i = 0; i < tam; i++)
    {
        cin >> elem;
        v.push_back(elem);
    }

    cout << resolver(v, l) << "\n";
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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