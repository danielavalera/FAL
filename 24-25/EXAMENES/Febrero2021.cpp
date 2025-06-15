// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v, int const& k) {
    int n = v.size();
    if (n == 0) return 0;

    int resetVentana = 0;  // Posición donde debe empezar la ventana válida actual
    int maxLongitud = 0;
    int paresConsecutivos = 0;  // Contador de pares consecutivos actuales

    for (int i = 0; i < n; i++) {
        // Si el elemento actual es par, incrementar contador
        if (v[i] % 2 == 0) {
            paresConsecutivos++;
        }
        else {
            // Si es impar, reiniciar contador de pares consecutivos
            paresConsecutivos = 0;
        }

        // Si tenemos más de k pares consecutivos, necesitamos resetear la ventana
        if (paresConsecutivos > k) {
            // La nueva ventana debe empezar k posiciones atrás desde i
            resetVentana = i - k + 1;
            paresConsecutivos = k;  // Ahora tenemos exactamente k pares consecutivos
        }

        // Calcular la longitud del segmento válido actual
        maxLongitud = max(maxLongitud, i - resetVentana + 1);
    }

    return maxLongitud;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, k, elem; cin >> tam >> k;
    vector<int> v;
    for (int i = 0; i < tam; i++)
    {
        cin >> elem;
        v.push_back(elem);
    }

    cout << resolver(v, k) << "\n";
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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