// Siro Fernandez Garcia
// A18


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

using namespace std;

// función que resuelve el problema
int resolver(int n, int salta) {
    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() > 1) { //!Empty no vale
        for (int j = 0; j < salta; j++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, salta;
    cin >> n >> salta;

    if (n == 0)
        return false;

    int sol = resolver(n, salta);

    // escribir sol

    cout << sol << endl;

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
