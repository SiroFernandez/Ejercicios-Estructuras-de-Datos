#include <iostream>
#include <fstream>
#include "mandelbrot.h"

using namespace std;

void resuelveCaso(){
	double real, imaginario;
	int iter;

	cin >> real >> imaginario >> iter;

	Complejo complejo(real, imaginario);

	if (!complejo.diverge(iter))
		cout << "SI\n";
	else
		cout << "NO\n";
}

int main() {
/*#ifndef DOMJUDGE
	ifstream in("texto.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .
# endif*/

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {	// Resolvemos todos los casos
		resuelveCaso();
	}

/*#ifndef DOMJUDGE // para dejar todo como estaba al principio
	cin.rdbuf(cinbuf);
	system(" PAUSE ");
#endif*/
	return 0;
}