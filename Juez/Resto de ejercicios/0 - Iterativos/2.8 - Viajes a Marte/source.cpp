// Daniela Valentina Valera Fuentes
// F94
//está bien hecho pero no es lo que pide, pide un algoritmo de partición.


/*
N = v.size();
P: 0 <= N <= 150.000 ^ altura > 0 ^ v=V
^ para todo k: 0 <= k < N: v[k] = 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct viajero {
    string nombre;
    int altura;
};

bool compararPorNombre(const viajero& a, const viajero& b) {
    return a.nombre < b.nombre;
};

// función que resuelve el problema
bool resolver(vector<viajero> viajeros, int hMax) {
    vector<viajero> altos, bajos;
    for (int i = 0; i < viajeros.size(); i++)
    {
        if (viajeros[i].altura <= hMax) {
            bajos.push_back({ viajeros[i].nombre, viajeros[i].altura });
        }
        else {
            altos.push_back({ viajeros[i].nombre, viajeros[i].altura });
        }
    }

    sort(bajos.begin(), bajos.end(), compararPorNombre);
    sort(altos.begin(), altos.end(), compararPorNombre);

    cout << "Bajos: " << ' ';
    for (int i = 0; i < bajos.size(); i++)
    {
        cout << bajos[i].nombre << ' ';
    }
    cout << '\n';
    cout << "Altos: " << ' ';
    for (int i = 0; i < altos.size(); i++)
    {
        cout << altos[i].nombre << ' ';
    }
    cout << '\n';

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamVector, hMax; cin >> tamVector >> hMax;
    if (!std::cin)
        return false;

    string nombre_aux;
    int altura_aux;
    vector<viajero> viajeros;

    for (int i = 0; i < tamVector; i++) {
        cin >> nombre_aux >> altura_aux;
        viajeros.push_back({ nombre_aux, altura_aux });
    }
    
    // escribir sol
    bool sol = resolver(viajeros, hMax);
    
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.8.txt");
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