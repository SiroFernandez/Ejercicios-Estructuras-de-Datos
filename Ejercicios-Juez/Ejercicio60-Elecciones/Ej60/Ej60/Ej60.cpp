// IMPORTANTE
// Nombre del alumno:
// Usuario del juez:


// Elecciones presidenciales

#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>
#include <unordered_map>
#include <map>

using namespace std;

class ConteoVotos {
private:
    struct DatosEstado{
        int compromisarios;
        unordered_map<string, int> votosPartido; //Patido->votos
        string ganadorAct;
        int maxVotos;
    };

    unordered_map<string, DatosEstado> estados;

public:
    void nuevo_estado(const string& nombre, int num_compromisarios) {
        auto it = estados.find(nombre);

        if (it != estados.end())
            throw domain_error("Estado ya existente");

        DatosEstado estado = { num_compromisarios, {}, "", 0};
        estados.insert({ nombre, estado });
    }

    void sumar_votos(const string& estado, const string& partido, int num_votos) {
        auto itEs = estados.find(estado);

        if (itEs == estados.end())
            throw domain_error("Estado no encontrado");

        int votosActualizados = itEs->second.votosPartido[partido] += num_votos;
        if (votosActualizados > itEs->second.maxVotos) {
            itEs->second.maxVotos = votosActualizados;
            itEs->second.ganadorAct = partido;
        }
    }

    string ganador_en(const string& estado) const {
        auto it = estados.find(estado);

        if (it == estados.end())
            throw domain_error("Estado no encontrado");

        return it->second.ganadorAct;
    }

    vector<pair<string, int>> resultados() const {
        map<string, int> compromisarios_por_partido;

        for (auto const& par : estados) {
            string ganador = par.second.ganadorAct;
            int delegados = par.second.compromisarios;

            compromisarios_por_partido[ganador] += delegados;
        }

        vector<pair<string, int>> resultado_final;

        for (auto const& par : compromisarios_por_partido) {
            resultado_final.push_back(par);
        }

        return resultado_final;
    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string op;
    std::cin >> op; // lectura del nombre de la operacion
    if (!std::cin) return false;
    ConteoVotos cv;
    while (op != "FIN") { // Lectura de todas las operaciones
        try {
            if (op == "nuevo_estado") {
                std::string nombre; int num_compromisarios;
                std::cin >> nombre >> num_compromisarios;
                cv.nuevo_estado(nombre, num_compromisarios);
            }
            else if (op == "sumar_votos") {
                std::string estado, partido;
                int num_votos;
                std::cin >> estado >> partido >> num_votos;
                cv.sumar_votos(estado, partido, num_votos);
            }
            else if (op == "ganador_en") {
                std::string estado;
                std::cin >> estado;
                std::string sol = cv.ganador_en(estado);
                std::cout << "Ganador en " << estado << ": " << sol << '\n';
            }
            else if (op == "resultados") {
                std::vector<std::pair<std::string, int>> sol = cv.resultados();
                for (std::pair<std::string, int> const& s : sol)
                    std::cout << s.first << ' ' << s.second << '\n';
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
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());//Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


