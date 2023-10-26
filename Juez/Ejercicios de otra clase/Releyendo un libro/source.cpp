// Nombre del alumno Javier Daza Justo
// Usuario del Juez A75

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resolver(vector<int> const& Pag_Libro, int Max_PagPosibles) {
	int Puntos_MaxPagina = 0;
	int Pos_inicio = 0;

	for (int i = 0; i < Pag_Libro.size(); ++i) 
	{
		if (Pag_Libro[i] > Puntos_MaxPagina) 
		{
			Pos_inicio = i;
			Puntos_MaxPagina = Pag_Libro[i];
		}
		else if (Pag_Libro[i] == Puntos_MaxPagina)
		{
			Pos_inicio = i;
		}
	}
	cout << Pos_inicio - Max_PagPosibles + 1 << endl;
}

bool resolverCaso() {
	int Pag_Libro;
	int Pag_Leer;

	cin >> Pag_Libro;
	cin >> Pag_Leer;

	if (Pag_Leer == 0 && Pag_Libro == 0)
	{
		return false;
	}
	vector<int> paginasDelLibro(Pag_Libro);

	for (int i = 0; i < Pag_Libro; ++i)
	{
		cin >> paginasDelLibro[i];
	}
	resolver(paginasDelLibro, Pag_Leer);

	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resolverCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}