// IMPORTANTE
// Siro Fernandez Garcia
// A-18

// Las torres del desierto

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <map>
#include <fstream>

using namespace std;

enum Direccion { Norte, Sur, Este, Oeste };

class Desierto {
private:
    struct Pos {
        int x;
        int y;
    };
    
    unordered_map<string, Pos> posNombre;
    unordered_map<int, map<int, string>> xEnY;
    unordered_map<int, map<int, string>> yEnX;

public:
    void anyadir_torre(const string& nombre, int x, int y) {
        if (posNombre.count(nombre))
            throw domain_error("Torre ya existente");
        if(xEnY.count(x) && xEnY[x].count(y))
            throw domain_error("Posicion ocupada");

        posNombre[nombre] = { x, y };
        xEnY[x][y] = nombre;
        yEnX[y][x] = nombre;
    }

    void eliminar_torre(const string& nombre) {
        auto it = posNombre.find(nombre);
        if (it == posNombre.end())
            throw domain_error("Torre no existente");

        int x = it->second.x;
        int y = it->second.y;

        xEnY[x].erase(y);
        if (xEnY[x].empty())
            xEnY.erase(x);

        yEnX[y].erase(x);
        if (yEnX[y].empty())
            yEnX.erase(y);

        posNombre.erase(it);
    }

    pair<int, int> posicion(const string& nombre) const {
        auto it = posNombre.find(nombre);
        if (it == posNombre.end())
            throw domain_error("Torre no existente");

        return{ it->second.x, it->second.y };
    }

    pair<bool, string> torre_en_posicion(int x, int y) const {
        auto it = xEnY.find(x);

        if (it != xEnY.end() && it->second.count(y))
            return{ true, it->second.at(y) };
           
        return{ false, "" };
    }

    string torre_mas_cercana(const string& nombre, const Direccion& dir) const {
        auto it = posNombre.find(nombre);
        if (it == posNombre.end())
            throw domain_error("Torre no existente");

        int x = it->second.x;
        int y = it->second.y;

        if (dir == Norte) {
            const auto& columna = xEnY.at(x);
            auto itAux = columna.find(y);
            itAux++;

            if (itAux == columna.end())
                throw domain_error("No hay torres en esa direccion");

            return itAux->second;
        }
        else if (dir == Sur) {
            const auto& columna = xEnY.at(x);
            auto itAux = columna.find(y);

            if (itAux == columna.begin()) 
                throw domain_error("No hay torres en esa direccion");
            itAux--;

            return itAux->second;
        }
        else if (dir == Este) {
            const auto& fila = yEnX.at(y);
            auto itAux = fila.find(x);
            itAux++;

            if (itAux == fila.end()) 
                throw domain_error("No hay torres en esa direccion");

            return itAux->second;
        }
        else if (dir == Oeste) {
            const auto& fila = yEnX.at(y);
            auto itAux = fila.find(x);

            if (itAux == fila.begin())
                throw domain_error("No hay torres en esa direccion");
            itAux--;

            return itAux->second;
        }

        throw domain_error("No hay torres en esa direccion");
    }

};

// Transforma un string en el tipo enumerado Direccion
// Para la llamada a la función torre_mas_cercana
Direccion calculaDir(std::string const& d) {
    if (d == "Sur") return Sur;
    else if (d == "Norte") return Norte;
    else if (d == "Este") return Este;
    else return Oeste;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    Desierto d;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "anyadir_torre") {
                std::string nombre; int x, y;
                std::cin >> nombre >> x >> y;
                d.anyadir_torre(nombre, x, y);
            }
            else if (op == "eliminar_torre") {
                std::string nombre;
                std::cin >> nombre;
                d.eliminar_torre(nombre);
            }
            else if (op == "posicion") {
                std::string nombre;
                std::cin >> nombre;
                std::pair<int, int> sol = d.posicion(nombre);
                std::cout << sol.first << ' ' << sol.second << '\n';
            }
            else if (op == "torre_en_posicion") {
                int x, y; std::cin >> x >> y;
                std::pair<bool, std::string> sol = d.torre_en_posicion(x, y);
                if (sol.first)
                    std::cout << "SI " << sol.second << '\n';
                else std::cout << "NO\n";
            }
            else {
                std::string nombre; std::string dir;
                std::cin >> nombre >> dir;
                std::string sol = d.torre_mas_cercana(nombre, calculaDir(dir));
                std::cout << sol << '\n';
            }
        }
        catch (std::domain_error const& e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> op;
    }
    std::cout << "---\n";
    return true;

}


int main() {

#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());//Resolvemos todos los casos


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


