// Examen ED 2025. Ejercicio 3

// ****  IMPORTANTE  ******

// Nombre y apellidos del estudiante

// Usuario del juez de examen

//*************************************

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>

using namespace std;

using jugador = std::string;
using equipo = std::string;

class gestor_futbolistas {

private:
    struct InfoJugador {
        equipo eqActual;
        unordered_set<equipo> eqHisotorial;
        list<jugador>::iterator eqPos;
    };

    struct InfoEquipo {
        list<jugador> plantilla;
    };

    unordered_map<jugador, InfoJugador> jugadores;
    unordered_map<equipo, InfoEquipo> equipos;

public:
    gestor_futbolistas() {}

    void fichar(jugador j, equipo e) {
        auto itJ = jugadores.find(j);
        
        if (itJ != jugadores.end() && itJ->second.eqActual == e)
            return;

        if (itJ != jugadores.end() && itJ->second.eqActual != e) {
            equipos[itJ->second.eqActual].plantilla.erase(itJ->second.eqPos);
            itJ->second.eqActual = e;
        }

        if (itJ == jugadores.end()) {
            jugadores[j].eqActual = e;
        }

        // 1. Añadimos el nuevo equipo a su historial (el 'set' ignora si ya estaba de antes)
        jugadores[j].eqHisotorial.insert(e);

        // 2. Lo metemos AL PRINCIPIO de la plantilla del nuevo equipo (push_front)
        equipos[e].plantilla.push_front(j);

        // 3. ¡ACTUALIZAMOS EL MARCAPÁGINAS!
        // Como lo acabamos de meter al principio, su posición exacta es el 'begin()' de la lista
        jugadores[j].eqPos = equipos[e].plantilla.begin();
    }

    equipo equipo_actual(jugador j) const {
        auto it = jugadores.find(j);

        if (it == jugadores.end())
            throw domain_error("Jugador inexistente");

        return it->second.eqActual;
    }

    int fichados(equipo e) const {
        auto it = equipos.find(e);

        if (it == equipos.end())
            throw domain_error("Equipo inexistente");

        return it->second.plantilla.size();
    }

    vector<jugador> ultimos_fichajes(equipo e, int n) const {
        auto it = equipos.find(e);
        vector <jugador> resultado;

        if(it == equipos.end())
            throw domain_error("Equipo inexistente");

        auto itLista = it->second.plantilla.begin();
        int contador = 0;

        while (contador < n && itLista != it->second.plantilla.end()) {
            resultado.push_back(*itLista);
            itLista++;
            contador++;
        }

        return resultado;
    }

    int cuantos_equipos(jugador j) const {
        auto it = jugadores.find(j);

        if (it == jugadores.end())
            return 0;

        return it->second.eqHisotorial.size();
    }

};


// A PARTIR DE AQUI NO SE PUEDE MODIFICAR EL CODIGO

// Resuelve cada caso de entrada
bool resuelveCaso() {
    std::string orden, jug, equ;
    int n;
    std::cin >> orden;
    if (!std::cin)
        return false;

    gestor_futbolistas gestor;

    while (orden != "FIN") {
        try {
            if (orden == "fichar") {
                std::cin >> jug >> equ;
                gestor.fichar(jug, equ);
            }
            else if (orden == "equipo_actual") {
                std::cin >> jug;
                auto eq = gestor.equipo_actual(jug);
                std::cout << "El equipo de " << jug << " es " << eq << '\n';
            }
            else if (orden == "fichados") {
                std::cin >> equ;
                int n = gestor.fichados(equ);
                std::cout << "Jugadores fichados por " << equ << ": " << n << '\n';
            }
            else if (orden == "ultimos_fichajes") {
                std::cin >> equ >> n;
                auto lista = gestor.ultimos_fichajes(equ, n);
                std::cout << "Ultimos fichajes de " << equ << ":";
                for (auto j : lista)
                    std::cout << ' ' << j;
                std::cout << '\n';
            }
            else if (orden == "cuantos_equipos") {
                std::cin >> jug;
                int n = gestor.cuantos_equipos(jug);
                std::cout << "Equipos que han fichado a " << jug << ": " << n << '\n';
            }
            else
                std::cout << "OPERACION DESCONOCIDA\n";
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("casos3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso());//Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

