/*
 * Escribir el nombre y usuario del juez de cada mmiembro de la pareja:
 *   Nombre y usuario:E-20 david dominguez
 *   Nombre y usuario:E-65 daniela valera fuentes
 *
 * Explicad brevemente el algoritmo:
 *
 */

#include <fstream>
#include <iostream>

using namespace std;

// No olvides la recurrencia que corresponde al coste de la función recursiva utilizando el número de dígitos de n como tamaño del problema.
// Indica también a qué orden de complejidad asintótica pertenece dicho coste.


//Escribe la función recursiva que resuelve el problema. Puedes definir los structs y funciones auxiliares que necesites


int contarObtusos(int n, int productoImpares)
{
    if (n == 0)
    {
        return 0;
    }
    else {

        int digito = n % 10;

        int esObtuso = (productoImpares % 10 == digito);
            if (digito % 2 != 0)
            {
                productoImpares *= digito;
            }
            int cuentaRestante = contarObtusos(n / 10, productoImpares);

        return cuentaRestante+esObtuso;
    }
}
void resuelveCaso() {
    int n;
    cin >> n;

    //Llama a la función
    cout << contarObtusos(n, 1) << endl;
    //Escribe el resultado
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");  //o cambia el nombre por el fichero que te descargues
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

