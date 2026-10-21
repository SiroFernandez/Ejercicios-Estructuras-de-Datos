# ifndef HORAS
# define HORAS

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Fecha {
public:
    Fecha(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
            throw invalid_argument(" Fecha invalida ");
        segundos = h * 3600 + m * 60 + s;
    }

    Fecha(int segs) {
        if (segs >= 24 * 3600)
            throw overflow_error("hoy no");
        segundos = segs;
    }

    int get_segs() const { return segundos; }

    Fecha operator+ (Fecha const& f) const {
        int s = segundos + f.get_segs();
        Fecha nueva(s);

        return nueva;
    }

    void imprimir() const {
        int h = segundos / 3600;
        int m = (segundos % 3600) / 60;
        int s = segundos % 60;

        cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << "\n";
    }

private:
    int segundos;
};

#endif