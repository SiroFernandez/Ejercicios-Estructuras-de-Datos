#ifndef set_plus_h
#define set_plus_h

#include <algorithm>
#include <functional>
#include <stack>
#include <stdexcept>
#include "set_eda.h"

using namespace std;


template <class T, class Comparator = std::less<T>>
class set_plus : public set<T, Comparator> {
    using Link = typename set<T, Comparator>::Link;

public:
    int darIntervalo(T const& lower, T const& upper) const {
        return count_interval(this->raiz, lower, upper);
    }

private:
    int count_interval(Link a, T const& lower, T const& upper) const {
        if (a == nullptr)
            return 0;

        if (a->elem >= lower && a->elem <= upper) {
            return (1 + count_interval(a->dr, lower, upper) + count_interval(a->iz, lower, upper));
        }
        else if (a->elem < lower) {
            return count_interval(a->dr, lower, upper);
        }
        else {
            return count_interval(a->iz, lower, upper);
        }
    }

};
#endif // set_eda_h
