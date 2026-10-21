// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include "bintree_eda.h"

using namespace std;

/*Para buscar por niveles:
-Creamos cola y metemos raiz
-La sacamos y miramos y metemos sus hijos
-Sacamos primer hijo y lo miramos y metemos sus hijos
Se repite asi sucesivamente
*/
void buscarImpar(bintree<int> const& arbol) {
    if (arbol.empty()) {
        cout << "NO HAY\n";
        return;
    }

    queue <pair<bintree<int>, int>> cola;

    cola.push({ arbol, 1 });

    while (!cola.empty()) {
        pair<bintree<int>, int> actual = cola.front();
        cola.pop();

        bintree<int> sub_arbol = actual.first;
        int nivel = actual.second;

        if (sub_arbol.root() % 2 == 1) {
            cout << sub_arbol.root() << " " << nivel << "\n";
            return;
        }
        else {
            if (!sub_arbol.left().empty()) {
                cola.push({ sub_arbol.left(), nivel + 1 });
            }
            if (!sub_arbol.right().empty()) {
                cola.push({ sub_arbol.right(), nivel + 1 });
            }
        }
    }
    
    cout << "NO HAY\n";
}

bool esVocal(char c) {
    c = tolower(c); // Por si nos dan mayúsculas
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void buscarVocal(bintree<char> const& arbol) {
    if (arbol.empty()) {
        cout << "NO HAY\n";
        return;
    }

    queue<pair<bintree<char>, int>> cola;
    cola.push({ arbol, 1 });

    while (!cola.empty()) {
        pair<bintree<char>, int> actual = cola.front();
        cola.pop();

        bintree<char> sub_arbol = actual.first;
        int nivel = actual.second;

        if (esVocal(sub_arbol.root())) {
            cout << sub_arbol.root() << " " << nivel << "\n";
            return;
        }
        else {
            if (!sub_arbol.left().empty()) {
                cola.push({ sub_arbol.left(), nivel + 1 });
            }
            if (!sub_arbol.right().empty()) {
                cola.push({ sub_arbol.right(), nivel + 1 });
            }
        }
    }

    cout << "NO HAY\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    char tipo;
    cin >> tipo;

    if (!cin) return false;

    bintree<int> arbolN;
    bintree<char> arbolC;

    if (tipo == 'N') {
        arbolN = leerArbol(-1);
        buscarImpar(arbolN);
    }
    if (tipo == 'C') {
        arbolC = leerArbol('#');
        buscarVocal(arbolC);
    }

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}