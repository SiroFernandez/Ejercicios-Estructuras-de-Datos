// Siro Fernandez Garcia
// A18


#include <iostream>
#include <iomanip>
#include <fstream>
#include "reverse_iterator.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    list<int> lista;

    while (cin >> n && n != 0) {
        lista.push_back(n);
    }

    auto it = lista.rbegin();
    bool primero = true;
    while (it != lista.rend()) {
        if (!primero) cout << " ";
        cout << *it;
        ++it;
        primero = false;
    }
    cout << endl;

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