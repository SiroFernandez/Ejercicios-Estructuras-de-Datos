// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct Solucion {
    int nodos;
    bool zurdo;
};

// función que resuelve el problema
Solucion esZurdo(const bintree<char>& arbol) {
    if (arbol.empty())
        return{ 0, true };
    if (arbol.left().empty() && arbol.right().empty())
        return{ 1, true };

    Solucion izqda = esZurdo(arbol.left());
    Solucion drcha = esZurdo(arbol.right());

    bool zurdo = izqda.zurdo && drcha.zurdo;
    int nodosIzqda = izqda.nodos;
    int nodosDrcha = drcha.nodos;

    return { nodosIzqda + nodosDrcha +1, zurdo && nodosIzqda > nodosDrcha };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');

    Solucion sol = esZurdo(arbol);

    if (sol.zurdo)
        cout << "SI" << "\n";
    else
        cout << "NO" << "\n";
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