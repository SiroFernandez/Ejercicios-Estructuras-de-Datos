// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream> // Necesario para trocear las líneas de texto
#include <map>
#include <vector>

using namespace std;

// Resuelve un caso de prueba
void resuelveCaso() {
    string lineaVieja, lineaNueva;

    // 1. LECTURA DE LOS DICCIONARIOS
    // Leemos las dos líneas completas
    getline(cin, lineaVieja);
    getline(cin, lineaNueva);

    map<string, int> viejo, nuevo;

    // Convertimos las líneas en flujos de datos para extraer las palabras
    stringstream ssViejo(lineaVieja);
    stringstream ssNuevo(lineaNueva);

    string clave;
    int valor;

    // Llenamos el mapa viejo
    while (ssViejo >> clave >> valor) {
        viejo[clave] = valor;
    }
    // Llenamos el mapa nuevo
    while (ssNuevo >> clave >> valor) {
        nuevo[clave] = valor;
    }

    // 2. LÓGICA DE COMPARACIÓN
    vector<string> anadidas;
    vector<string> borradas;
    vector<string> cambiadas;

    // A) Buscamos añadidas y cambiadas (Recorremos el NUEVO)
    for (auto const& par : nuevo) {
        string palabra = par.first;
        int valorNuevo = par.second;

        if (viejo.count(palabra) == 0) { // count() averigua si la clave pertenece al diccionario
            anadidas.push_back(palabra);
        }
        else if (viejo.at(palabra) != valorNuevo) {
            cambiadas.push_back(palabra);
        }
    }

    // B) Buscamos las borradas (Recorremos el VIEJO)
    for (auto const& par : viejo) {
        string palabra = par.first;
        if (nuevo.count(palabra) == 0) {
            borradas.push_back(palabra);
        }
    }

    // 3. IMPRESIÓN DE RESULTADOS
    if (anadidas.empty() && borradas.empty() && cambiadas.empty()) {
        cout << "Sin cambios\n";
    }
    else {
        if (!anadidas.empty()) {
            cout << "+";
            for (string const& s : anadidas) cout << " " << s;
            cout << "\n";
        }
        if (!borradas.empty()) {
            cout << "-";
            for (string const& s : borradas) cout << " " << s;
            cout << "\n";
        }
        if (!cambiadas.empty()) {
            cout << "*";
            for (string const& s : cambiadas) cout << " " << s;
            cout << "\n";
        }
    }

    // Fin del caso de prueba
    cout << "----\n";
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    int numCasos;
    if (std::cin >> numCasos) {
        // MUY IMPORTANTE: Limpiar el salto de línea que deja 'cin >> numCasos'
        // para que 'getline' no lea una línea vacía fantasma.
        std::cin.ignore(10000, '\n');

        for (int i = 0; i < numCasos; ++i) {
            resuelveCaso();
        }
    }

#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}