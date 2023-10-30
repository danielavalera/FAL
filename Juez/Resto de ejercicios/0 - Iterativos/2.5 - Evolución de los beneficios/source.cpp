// Daniela Valentina Valera Fuentes
// F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
vector<int> resolver(int annoInicio, vector<int> ventas) {

    vector<int> annos;
    int primerAnno = ventas[0];
    int anno;
    for (int i = 1; i < ventas.size(); i++)
    {
        if (ventas[i] > primerAnno) {
            primerAnno = ventas[i];
            anno = annoInicio + i;
            annos.push_back(anno);
        }
    }

    return annos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int annoInicio, annoFin;
    cin >> annoInicio >> annoFin;

    int tamVectorVentas = annoFin - annoInicio;
    vector<int> ventas;
    int venta;

    for (int i = 0; i <= tamVectorVentas; i++)
    {
        cin >> venta;
        ventas.push_back(venta);
    }
    
    vector<int> sol = resolver(annoInicio, ventas);

    // escribir sol
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << ' ';
    }
    cout << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos2.5.txt");
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