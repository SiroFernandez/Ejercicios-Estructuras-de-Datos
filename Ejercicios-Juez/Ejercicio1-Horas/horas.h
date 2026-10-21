# ifndef HORAS
# define HORAS

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Fecha {
public:
    Fecha() {}
    Fecha(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
            throw std::invalid_argument(" Fecha invalida ");
        horas = h;
        min = m;
        seg = s;
    }

    int get_horas() const { return horas; }
    int get_mins() const { return min; }
    int get_segs() const { return seg; }

    bool operator< (Fecha const& f ) const {
        int t1 = this->horas * 3600 + this->min * 60 + this->seg;
        int t2 = f.get_horas() * 3600 + f.get_mins() * 60 + f.get_segs();
        return t1 < t2;
    }

    bool operator== (Fecha const& f ) const {
        return this->horas == f.get_horas() && this->min == f.get_mins() && this->seg == f.get_segs();
    }

private :
    int horas;
    int min;
    int seg;
};

#endif