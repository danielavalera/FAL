// DANIELA VALENTINA VALERA FUENTES
// F94


/*
* Coste: O(n) siendo n el número de cifras
*
*
* Especificación:
*           -Ecuación de recurrencia:
*                   T1(n) = c0              si n=1
*                   T1(n) = c1 + T1(n-1)    si n>1
*                   siendo n el nº de cifras
*
*                   T2(n) = c0              si n=0
*                   T2(n) = c1 + T2(n-1)    si n>0
*                   siendo n el nº de cifras
*
*           -Desplegado:
*                   T1(n) = c1 + T1(n-1) * 2c1 + T(n-2) * ...
*                   ...
*                   T1(n) = k*c1 - T1(n-k)
*
*                   T2(n) = c1 + T2(n-1) * 2c1 + T(n-2) * ...
*                   ...
*                   T2(n) = k*c1 - T2(n-k)
*
*           -Postulado:
*               n-k = 1 -> n - 1 = k
*               k*c1 - T1(n-k) = (n-1)*c1 + T1(n -(n - 1)) = (n-1)*c1 + T1(1) = (n-1)*c1 + c0 = n -> O(n)
*
*               n-k = 0 -> n = k
*               k*c1 - T1(n-k) = n*c1 + T1(n - n) = nc1 + T1(0) = nc1 + c0 = n -> O(n)
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int complementario(int n){
    if (n<10) return 9-n;
    else{
        int complementarioSinUnidades = complementario(n/10); //caso recursivo
        int complementarioUnidades = 9-n%10;
        return complementarioSinUnidades*10 + complementarioUnidades;
    }
}
int inversoComplementario(int n, int m){
    if(n<10 && n== 0) return 9-n;
    else if (n == 0) return m;
    else return inversoComplementario(n/10, m*10 + (9-n%10));
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; cin >> n;

    // escribir sol
    cout << complementario(n) << ' ' << inversoComplementario(n,0) << '\n';
    
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