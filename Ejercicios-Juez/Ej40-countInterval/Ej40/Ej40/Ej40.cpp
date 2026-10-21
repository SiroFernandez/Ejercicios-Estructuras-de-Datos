// Siro Fernandez Garcia
// A-18


#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_plus.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, interv;
    if (!(cin >> n >> interv))
        return false;

    set_plus<int> s;

    for (int i = 0; i < n; ++i) {
        int elem;
        cin >> elem;
        s.insert(elem);
    }
    
    for (int i = 0; i < interv; ++i) {
        int lower, upper;
        cin >> lower >> upper;
        cout << s.darIntervalo(lower, upper) << "\n";
    }

    cout << "---\n";

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