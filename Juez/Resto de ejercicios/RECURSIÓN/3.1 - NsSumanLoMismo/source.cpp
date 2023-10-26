// DANIELA VALENTINA VALERA FUENTES
// FAL94


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada


    TipoSolucion sol = resolver(datos);
    // escribir sol


    /*Primero calculo el primero que leo, miro cada uno cuanto suma y si suma lo mismo que el de partida lo imprimo, lo guardo en otro vector...etc.
    */

    /*---------------------------------ESTA ES LA MANERA RECURSIVA NO FINAL--------- xq lo último que se hace no es la llamada recursiva (suele ser la más fácil)
    * inf f(const int k){
    * CASO BASE: 
    * if(k<10) return k;
    * else{
    * CASO RECURSIVO:
    * int x = f(k/10); //TENGO QUE SUPONER QUE ESTO SE CUMPLE (NO BUSCAR QUE SE CUMPLA)
    * return x + k%10; //Y SI LO ANTERIOR SE CUMPLE, ENTONCES ESTO TMBN.
    * }}
    * 
    * HAY QUE PENSARLO COMO LOS EJS. DE INDUCCIÓN
    */

    /*---------------------------------ESTA ES LA LLAMADA RECURSIVA FINAL------------- suele necesitar llevar parámetros adicionales (contador, var.acumuladoras,...etc.)
    * int f(int k, int acum){
    * if(k<10) return acum + k;
    * } else{
    * return f(k/10, acum + k%10)
    * }
    */

    /*RECURSIVA SIMPLE: 
    * RECURSIVA MÚLTIPLE:
    */

    
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