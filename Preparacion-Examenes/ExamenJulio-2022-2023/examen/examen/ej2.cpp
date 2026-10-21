// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct Solucion {
    int barcos;
    int sobranTesoros;
};

Solucion barcosNecesarios(const bintree<int>& arbol, int caben) {
    if (arbol.empty()) {
        return { 0, 0 };
    }

    Solucion izqda = barcosNecesarios(arbol.left(), caben);
    Solucion drcha = barcosNecesarios(arbol.right(), caben);

    int tesorosPendientes = arbol.root() - (izqda.sobranTesoros + drcha.sobranTesoros);
    int barcos = izqda.barcos + drcha.barcos;
    int sobranTesoros = 0;

    if (tesorosPendientes <= 0) {
        sobranTesoros = -tesorosPendientes;
    }
    else {
        barcos += tesorosPendientes / caben;

        if (tesorosPendientes % caben != 0) {
            barcos++;
            sobranTesoros = caben - (tesorosPendientes % caben);
        }
        else {
            sobranTesoros = 0;
        }
    }

    return { barcos, sobranTesoros };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    int caben;
    cin >> caben;

    Solucion sol = barcosNecesarios(arbol, caben);

    cout << sol.barcos << " " << sol.sobranTesoros << "\n";
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