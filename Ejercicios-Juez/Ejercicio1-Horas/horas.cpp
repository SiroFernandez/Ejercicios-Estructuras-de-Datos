#include "horas.h"

using namespace std;

bool resuelveCaso(){
    int n;

    cin >> n;
    if (!cin) return false;

    for(int i=0; i<n; i++){
        int h1, m1, s1, h2, m2, s2;
        char basura;

        cin >> h1 >> basura >> m1 >> basura >> s1
            >> h2 >> basura >> m2 >> basura >> s2;

        Fecha f1(h1, m1, s1), f2(h2, m2, s2);

        if (f1 == f2)
            cout << "IGUALES" << endl;
        else if (f1 < f2) {
            cout << setw(2) << setfill('0') << h1 << ":" << setw(2) << setfill('0') << m1 << ":" << setw(2) << setfill('0') << s1 << " " << setw(2) << setfill('0') << h2 << ":" << setw(2) << setfill('0') << m2 << ":" << setw(2) << setfill('0') << s2 << endl;
        }
        else
            cout << setw(2) << setfill('0') << h2 << ":" << setw(2) << setfill('0') << m2 << ":" << setw(2) << setfill('0') << s2 << " " << setw(2) << setfill('0') << h1 << ":" << setw(2) << setfill('0') << m1 << ":" << setw(2) << setfill('0') << s1 << endl;
    }

    return true;
}

int main(){
    #ifndef DOMJUDGE
        ifstream in ("texto.txt");
        auto cinbuf = std :: cin . rdbuf ( in . rdbuf ()); // save old buf and redirect std :: cin to casos .# endif
    #endif

    while (resuelveCaso()) {} // Resolvemos todos los casos
    #ifndef DOMJUDGE // para dejar todo como estaba al principio
        cin.rdbuf ( cinbuf );
        system (" PAUSE ");
    # endif
    return 0;
}