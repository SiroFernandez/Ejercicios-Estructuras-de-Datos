// Siro Fernandez Garcia
// A18


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

struct Resultado {
    int cont;
    int tamano;
};

Resultado salvar(const bintree<char>& a) {
    if (a.empty())
        return { 0, 0 };

    Resultado izquierda = salvar(a.left());
    Resultado derecha = salvar(a.right());

    int tam = 1 + izquierda.tamano + derecha.tamano;
    int cortarIzqda = izquierda.tamano + derecha.cont;
    int cortarDrcha = derecha.tamano + izquierda.cont;
    int maximo = max(cortarDrcha, cortarIzqda);

    return { maximo, tam };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    bintree<char> a = leerArbol<char>('.');
    Resultado res = salvar(a);
    cout << res.cont << "\n";
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