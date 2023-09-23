// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <climits> //necesitamos esta libreria para INT_MAX
using namespace std;



// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tamVector, posVector;
    cin >> tamVector;
    cin >> posVector;
    vector<int> v(tamVector); //reservas las posiciones
    for (int i = 0; i < tamVector; i++) {
        cin >> v[i]; //metes el valor en esas posiciones
    }
    int numMax = v[0], numMin = INT_MAX;

    for (int i = 1; i <= posVector; i++) {
        if (numMax < v[i]) {
            numMax = v[i];
        }
    }

    for (int i = posVector +1; i < tamVector; i++) {
        if (numMin > v[i]) {
            numMin = v[i];
        }
    }

    //TipoSolucion sol = resolver(datos);
    // escribir sol
    if (numMax < numMin) {
        cout << "SI" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}