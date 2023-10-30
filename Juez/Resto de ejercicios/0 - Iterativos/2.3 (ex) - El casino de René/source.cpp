// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
bool resolver(int minBeneficio, vector<int> v) {
    int sumaMax = 0, suma = 0, iniInterv = 0, iniIntervAux, finInterv = 0;


    for (int i = 0; i < v.size(); i++) {
        suma += v[i];

        if (suma >= minBeneficio) {
            if (suma > sumaMax) {
                sumaMax = suma;
                iniInterv = iniIntervAux;
                finInterv = i;
            }
        }

        if (suma < 0) { // resetear
            suma = 0;
            iniIntervAux = i + 1;
        }
    }

    if (sumaMax < minBeneficio) {
        cout << "NO COMPENSA" << '\n';
    }
    else {
        cout << sumaMax << " " << iniInterv << " " << finInterv << '\n';
    }

    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tVector, minBeneficio;
    cin >> tVector >> minBeneficio;
    vector<int> v;
    int n;

    for (size_t i = 0; i < tVector; i++)
    {
        cin >> n;
        v.push_back(n);
    }
    
    bool sol = resolver(minBeneficio, v);
    // escribir sol

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.3.txt");
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