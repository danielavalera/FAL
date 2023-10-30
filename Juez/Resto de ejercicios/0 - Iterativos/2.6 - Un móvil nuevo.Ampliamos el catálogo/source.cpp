// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
vector<int> resolver(vector<int> a, vector<int> b) {
    vector<int> listaOrdenada;
    int i = 0; int j = 0;

    while (i < a.size() && j < b.size()) { // da min(a.size(), b.size()) de vueltas
        if (a[i] < b[j]) {
            listaOrdenada.push_back(a[i]);
            i++;
        }
        else if (a[i] == b[j]) {
            listaOrdenada.push_back(a[i]);
            listaOrdenada.push_back(b[j]);
            i++; j++;
        }
        else {
            listaOrdenada.push_back(b[j]);
            j++;
        }
    }

    while (i < a.size()) { //mientras aún queden elementos por recorrer en la listaA, lo mete en orden xq las listas están ordenadas inicialmente
        listaOrdenada.push_back(a[i]);
        i++;
    }

    while (j < b.size()) { //mientras aún queden elementos por recorrer en la listaB, lo mete en orden xq las listas están ordenadas inicialmente
        listaOrdenada.push_back(b[j]);
        j++;
    }

    return listaOrdenada;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamA, tamB; cin >> tamA >> tamB;
    int precioA, precioB;
    vector<int> a, b;

    for (int i = 0; i < tamA; i++){
        cin >> precioA;
        a.push_back(precioA);
    }

    for (int i = 0; i < tamB; i++){
        cin >> precioB;
        b.push_back(precioB);
    }

    vector<int> sol = resolver(a, b);

    // escribir sol
    for (int i = 0; i < sol.size(); i++){
        cout << sol[i] << ' ';
    }
    cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.6.txt");
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