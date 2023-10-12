// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int nEdificios, alturaNave;
    cin >> nEdificios >> alturaNave;
    vector<int> v;

    int alturas;
    for (int i = 0; i < nEdificios; i++)
    {
        cin >> alturas;
        v.push_back(alturas);
    }

    // Contar el intervalo de números más grandes que alturaNave
    int count = 0;
    // Contar el intervalo máximo de números más grandes que alturaNave
    int count_max = 0;

    // Posiciones del vector que cumplen la condición de números más grandes que alturaNave
    int p, q;
    // Posiciones máximas del vector que cumplen la condición de números más grandes que alturaNave
    int pMax, qMax;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] > alturaNave) {
            count++;

            if (count == 1)
                p = i;
            q = i;

            if (count_max < count) { //se actualiza cuando hay un maximo más grande que mi maximo
                pMax = p;
                qMax = q;
                count_max = count;
            }
        }
        else {
            count = 0;
        }
    }

    //TipoSolucion sol = resolver(datos);
    // escribir sol
    cout << pMax << " " << qMax << "\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.1.txt");
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