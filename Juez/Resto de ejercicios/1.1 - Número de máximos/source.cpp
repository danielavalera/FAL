// Daniela Valentina Valera Fuentes
// F94
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {}

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
//--> El contador se inicializa a 1 para que en el segundo caso y tercero salga bien.
//--> La comprobación de igual va antes de la de mayor porque sino el contador no se hace bien
//--> El contador es =1 en la comprobación de mayor para que cuando haya un maximo que supere al otro se reinicie el contador
void resuelveCaso() {
    int n;
    int grande;
    int contador = 0;

    // leer los datos de la entrada
    cin >> n;
    grande = n;

    while (n != 0) {
        //cout << n << " ";
        if (n > grande) {
            grande = n;
            contador = 1;
        }
        else if (n == grande) {
            contador++;
        }
        cin >> n; //IMPORTANTE ESTA ENTRADA AQUÍ
    }
    //TipoSolucion sol = resolver(datos);
    // escribir sol
    cout << grande << " " << contador << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos1.1.txt");
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