// Examen ED. Ejercicio 3
// **** IMPORTANTE  ******
// Nombre y apellidos del estudiante
// Usuario del juez de examen
//*************************************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
// Incluye aquí tus librerías mágicas (unordered_map, map, list, vector...)

#include <map>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

using entrenador = string;
using pokemon = string;

/*
- capturar_pokemon(string e, string p, int n) -> insertar(p) con nivel n en el equipo del entrenador e,
                      lista de pokemons en entrenador
- vencer_pokemon(string e, int n) -> la lista de pokemones en entrenador debe estar ordenada
- dia_de_liberacion(string p) -> ...
- gimnasio(string e) -> se elimina pokemon de la lista ordenada que elimina al mas antiguo
              (cola) y para eliminar usamos iterador
*/

class CentroPokemon {
private:
    struct InfoEntrenador {
        map<int, pokemon> por_nivel;           // Nivel -> Nombre pokemon
        list<pokemon> historial;               // Cola cronológica
        unordered_map<pokemon, int> por_nombre; // Nombre -> Nivel (Para buscar rápido)
    };

    unordered_map<entrenador, InfoEntrenador> entrenadores;

public:
    CentroPokemon() {}

    void capturar_pokemon(const entrenador& e, const pokemon& p, int n) {
        InfoEntrenador& mochila = entrenadores[e];

        if (mochila.por_nombre.count(p))
            throw invalid_argument("Pokemon repetido");
        if (mochila.por_nivel.count(n))
            throw invalid_argument("Nivel repetido");

        mochila.por_nombre[p] = n;
        mochila.por_nivel[n] = p;
        mochila.historial.push_back(p);
    }

    auto vencer_pokemon(const entrenador& e, int n) const {
        auto it = entrenadores.find(e);

        if(it==entrenadores.end())
            throw invalid_argument("Entrenador inexistente");

        if(it->second.por_nombre.size() <= 0 && it->second.por_nivel.size() <= 0)
            throw invalid_argument("No tiene pokemons");

        if(it->second.por_nivel.begin() < n)
            throw invalid_argument("pokemon no puede ser vencido");

        auto pokemonMasNivel = it->second.por_nivel.begin();

        return pokemonMasNivel;
    }

    int dia_de_liberacion(const pokemon& p) {
        int liberados = 0;

        for (auto& par : entrenadores) {
            InfoEntrenador& mochila = par.second;

            if (mochila.por_nombre.count(p)) {
                int nivel = mochila.por_nombre[p];

                mochila.por_nombre.erase(p);
                mochila.por_nivel.erase(nivel);
                mochila.historial.remove(p);
            }

            liberados++;
        }

        return liberados;
    }

    pokemon gimnasio(const entrenador& e) {
        auto it = entrenadores.find(e);
        if (it == entrenadores.end())
            throw invalid_argument("Entrenador no existente");

        InfoEntrenador& mochila = it->second;
        if (mochila.historial.empty())
            throw invalid_argument("No tiene pokemons");

        // 1. Miramos quién es el más antiguo y sacamos su nivel
        pokemon p = mochila.historial.front();
        int nivel = mochila.por_nombre[p];

        // 2. Lo borramos de las 3 estructuras
        mochila.historial.pop_front();
        mochila.por_nivel.erase(nivel);
        mochila.por_nombre.erase(p);

        return p; // Devolvemos el nombre del que hemos echado
    }
};

// A PARTIR DE AQUÍ NO SE DEBE MODIFICAR EL CÓDIGO
// Resuelve cada caso de entrada
bool resuelveCaso() {
    string orden, ent, pok;
    int niv;

    cin >> orden;
    if (!cin)
        return false;

    CentroPokemon centro;

    while (orden != "FIN") {
        try {
            if (orden == "capturar_pokemon") {
                cin >> ent >> pok >> niv;
                centro.capturar_pokemon(ent, pok, niv);
            }
            else if (orden == "vencer_pokemon") {
                cin >> ent >> niv;
                InfoVencedor info = centro.vencer_pokemon(ent, niv);
                cout << ent << " utiliza el pokemon " << info.nombre
                    << " con nivel " << info.nivel << " para vencer a un nivel " << niv << '\n';
            }
            else if (orden == "dia_de_liberacion") {
                cin >> pok;
                int cantidad = centro.dia_de_liberacion(pok);
                cout << "Liberados " << cantidad << " pokemon " << pok << '\n';
            }
            else if (orden == "gimnasio") {
                cin >> ent;
                pokemon liberado = centro.gimnasio(ent);
                cout << ent << " deja el pokemon " << liberado << " en un gimnasio\n";
            }
            else {
                cout << "OPERACION DESCONOCIDA\n";
            }
        }
        catch (invalid_argument& e) {
            cout << "ERROR: " << e.what() << '\n';
        }
        cin >> orden;
    }
    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("casos_pokemon.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // Guardar buffer y redirigir
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}