// Siro Fernandez Garcia
// A-18


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct Tabla {
    unordered_map <string, int> numerosJugador;
    unordered_map <int, vector<string>> posiciones;
};

// función que resuelve el problema
vector<string> resolver(Tabla& datos) {
    vector<string> ganadores;
    int n;

    while (ganadores.empty() && cin >> n) {
        if (datos.posiciones.count(n) > 0) {
            for (int i = 0; i < datos.posiciones[n].size(); i++) {
                string jugador = datos.posiciones[n][i];

                datos.numerosJugador[jugador]--;

                if (datos.numerosJugador[jugador] == 0) {
                    ganadores.push_back(jugador);
                }
            }
            datos.posiciones.erase(n);
        }
    }

    sort(ganadores.begin(), ganadores.end());
    return ganadores;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

    Tabla datos;

    for (int i = 0; i < n; i++) {
        string jugador;
        int num;
        set <int> carton;

        cin >> jugador >> num;

        while (num != 0) {
            if (carton.count(num) == 0) {
                carton.insert(num);
                datos.posiciones[num].push_back(jugador);
                datos.numerosJugador[jugador]++;
            }
            cin >> num;
        }
    }

    vector <string> sol;
    sol = resolver(datos);

    // escribir sol
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i];
        if (i < sol.size() - 1) {
            cout << " ";
        }
    }
    cout<< "\n";

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
