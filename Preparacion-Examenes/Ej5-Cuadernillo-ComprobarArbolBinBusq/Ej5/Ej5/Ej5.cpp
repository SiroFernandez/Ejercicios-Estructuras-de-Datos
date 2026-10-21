// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <algorithm>
#include "bintree_eda.h"

using namespace std;

struct Solucion {
    bool loEs;
    int min;
    int max;
};

// función que resuelve el problema
Solucion esArbolBusqueda(const bintree<int>& arbol) {
    if (arbol.empty())
        return { true, INT_MAX , INT_MIN }; //He ouesto 0 para el min y 10 para el max
    
    if (arbol.left().empty() && arbol.right().empty())
        return{ true, arbol.root(), arbol.root()};

    Solucion izqda = esArbolBusqueda(arbol.left());
    Solucion drcha = esArbolBusqueda(arbol.right());

    bool arbolBusqueda = izqda.loEs && drcha.loEs && (arbol.root() > izqda.max && arbol.root() < drcha.min);
    int minimo = min(arbol.root(), izqda.min);
    int maximo = max(arbol.root(), drcha.max);

    return { arbolBusqueda, minimo, maximo };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);

    Solucion sol = esArbolBusqueda(arbol);

    if (sol.loEs)
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