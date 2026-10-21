#include "horas.h"

using namespace std;

bool resuelveCaso() {
    
    try {
        int h1, m1, s1, h2, m2, s2;
        char basura;

        cin >> h1 >> basura >> m1 >> basura >> s1
            >> h2 >> basura >> m2 >> basura >> s2;

        Fecha f1(h1, m1, s1), f2(h2, m2, s2);
        Fecha suma = f1 + f2;

        suma.imprimir();
    }
    catch (overflow_error const& e) {
        cout << e.what() << "\n";
    }
    catch (invalid_argument& ia) {
        cout << ia.what() << '\n';
    }
    

    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("prueba.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std :: cin to casos .# endif
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { resuelveCaso(); } // Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system(" PAUSE ");
# endif
    return 0;
}