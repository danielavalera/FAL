/*
* Daniela Valentina Valera Fuentes(F94)
Creo una variable maximo donde clono el valor de n fuera del bucle, para una primera comprobación.
El bucle compara maximo con el siguiente valor de cin, si es el mismo valor aumenta el contador con el numero de veces
que se repite esa puntuación, si es menor actualiza su valor y resetea el contador.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// función que resuelve el problema
//TipoSolucion resolver(TipoDatos datos) {}

// Resuelve un caso de prueba, leyendo de la entrada la configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n, maximo;
    int contador = 0;
    // leer los datos de la entrada
    cin >> n;
    maximo = n;

    while (n != 0) {
        if (n == maximo) {
            contador++;
        }else if (n > maximo) {
            maximo = n;
            contador = 1;
        }//sino, paso al siguiente valor
        cin >> n; //IMPORTANTE ESTA ENTRADA AQUÍ
    }
    //TipoSolucion sol = resolver(datos);
    // escribir sol
    cout << maximo << " " << contador << "\n";
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