// Nombre del alumno Antonio Lucas Simon
// Usuario del Juez E32


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>


std::string color2string(int n) {
	if (n == 0) return "azul ";
	else if (n == 1) return "rojo ";
	else return "verde ";
}

void mostrar(std::vector <int> const & sol,int const k) {
	for (int i = 0; i <= k; i++)
		std::cout << color2string(sol[i]);
	std::cout<< std::endl;
}

bool esValida(std::vector <int>const & sol, int k) {
	bool valida = true;
	int i = 0;
	int a = 0, v = 0;
	while (i <= k && valida)
	{
		if (sol[i] == 0) a++;
		else if (sol[i] == 2) v++;
		if (v > a) valida = false;
		i++;
	}
	return valida;
}

bool masRojas(std::vector <int> const & sol) {
	bool solucion = false;
	int i = 1, r = 1;
	while (i<sol.size() && !solucion)
	{
		if (sol[i] == 1) r++;
		if (r > sol.size()/2) solucion = true;
		i++;
	}
	return solucion;
}



// función que resuelve el problema
void resolver(std::vector <int> & sol, int k,int n, std::vector <int> colores, bool & haySoluciones) {
	for (int i = 0; i < n; i++){
		sol[k] = i;
		if (colores[i] > 0)
		{ // Hay torres de ese color
			if (!(sol[k] == 2 && sol[k - 1] == 2))
			{ // No 2 verdes seguidas
				if (esValida(sol, k)) { //verdes no superan a azules
					colores[i]--;
					if (k == sol.size() - 1) { //es solucion
						if (masRojas(sol)) { // rojas mayor que el resto
							haySoluciones = true;
							mostrar(sol, k);
						}
					}
					else { //no es solucion
						resolver(sol, k + 1, n, colores,haySoluciones);
					}
					colores[i]++;
				}
			}
		}
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int altura;
	std::vector<int> col(3); //vector colores col[i] i = color (a=0,r=1,v=2)
	std::cin >> altura >> col[0] >> col[1] >> col[2];
    if (altura == 0)
        return false;
	bool tieneSolucion = false;
	std::vector <int> sol(altura); 
	sol[0] = 1;
	col[1]--;
    resolver(sol,1,3,col,tieneSolucion);
    
    // escribir sol
	if (!tieneSolucion)
		std::cout << "SIN SOLUCION" << std::endl;

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
   /* #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif */
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
   /*  #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif */
	system("PAUSE");
    return 0;
	
}