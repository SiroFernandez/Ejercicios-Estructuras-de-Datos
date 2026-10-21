// Siro Fernandez Garcia
// A-18


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

using namespace std;

// función que resuelve el problema
vector<int> resolver(const bintree<int>& a) {
    if (a.empty()) {
        return{ };
    }

    vector<int>res;
    res.push_back(a.root());

    vector<int>izquierda = resolver(a.left());
    vector<int>derecha = resolver(a.right());
    res.insert(res.end(),izquierda.begin(), izquierda.end());

    if (derecha.size() > izquierda.size()) 
        res.insert(res.end(), derecha.begin() + izquierda.size(), derecha.end());
    
    return res;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<int> a = leerArbol(-1);
    vector<int> v;
    v = resolver(a);

    if (!v.empty()) {
        cout << v[0];
        for (int i = 1; i < v.size(); ++i) {
            cout << " " << v[i];
        }
    }
    cout << "\n";
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