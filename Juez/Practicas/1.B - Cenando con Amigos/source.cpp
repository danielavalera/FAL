// Cristian García Moruno F42
// Daniela Valentina Valera Fuentes F94


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


/*
* P = { n > 0 ^ existe i: 0 <= i < n : v[i] >= 1}
* 
* Q = { iniInterMax = existe i : 1<= i < n: inicio del intervalo
        lMax = existe l : 1 > l >= n: fin del intervalo
        sumaMax = sumatorio : existe i: 1 <= i < n ^ existe j: 1 <= i < n: tal que i inicio intervalo y j final intervalo}
* 
* I = {0 <= suma < v.size() ^
*      (suma > 0 => 0 <= l < v.size()) && (suma <= 0 => 1 = 0)
        }
* Coste: O(n)
* Explicación: el coste es lineal puesto que recorre todos los elementos del vector una vez, y como es de tamaño n el coste es n
* 
* Función de cota: n-i


*/
struct Sol {
    int suma, comienzo, l;
};
// función que resuelve el problema
Sol resolver(vector<int> const & v) {
    int suma = 0, iniInter = 0, l = 0, lMax = l;
    int sumaMax = suma;
    int iniInterMax = iniInter;
    int i = 0;

    while (i<v.size()) {
        suma += v[i];
        ++l;

        if (suma > 0) {
            if (suma > sumaMax || (suma == sumaMax && l < lMax)) {
                sumaMax = suma;
                iniInterMax = iniInter;
                lMax = l;
            }
        }
        else {
            suma = 0;
            l = 0;
            iniInter = i + 1;
        }
        i++;

    }
        
     return { sumaMax, iniInterMax, lMax };

}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamVector; cin >> tamVector;
    if (!std::cin)
        return false;
    
    vector<int> v(tamVector);
    for (int i = 0; i < tamVector; i++)
    {
        cin >> v[i];
    }

    Sol sol = resolver(v);

    // escribir sol
    cout << sol.suma << ' ' << sol.comienzo << ' ' << sol.l << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos1B.txt");
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