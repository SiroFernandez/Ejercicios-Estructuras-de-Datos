#include "linked_list_plus.h"
#include <iostream>
#include <fstream>

using namespace std;

bool resuelve() {
	int num;
	cin >> num;
	if (num == 0)
		return false;

	linked_list_plus<int> list;

	int valor;
	for (int i = 0; i < num; i++) {
		cin >> valor;
		list.push_back(valor);
	}

	list.intercambio();
	list.mostrar();
	
	return true;
}

int main() {
	
	# ifndef DOMJUDGE
		std::ifstream in("datos.txt");
		auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos . txt
	# endif
		while (resuelve()) {} // Resolvemos todos los casos
	# ifndef DOMJUDGE // para dejar todo como estaba al principio
		std::cin.rdbuf(cinbuf);
		system(" PAUSE ");
	# endif
		return 0;
}