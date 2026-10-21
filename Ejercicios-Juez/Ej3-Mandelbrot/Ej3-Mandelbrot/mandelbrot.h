#ifndef MANDELBROT
#define MANDELBROT

#include <iostream>
#include <array>
#include <stdexcept>
#include <cmath>

class Complejo {
public:
	Complejo(double r, double i): real(r), imaginario(i) {}

	Complejo operator+(Complejo const& n) const {
		return {real + n.getReal(), imaginario + n.getImaginario()};
	}

	Complejo operator*(Complejo const& n) const {
		return { real * n.getReal() - imaginario * n.getImaginario(), imaginario * n.getReal() + real * n.getImaginario() };
	}

	double modulo() const {
		return sqrt(real * real + imaginario * imaginario);
	}

	bool diverge(int n) const {
		Complejo serie(0.0, 0.0);
		int i = 0;

		while (serie.modulo() <= 2.0 && i < n) {
			serie = serie * serie + *this;
			i++;
		}
		return (serie.modulo() > 2.0);
	}

private:
	double real;
	double imaginario;
	double getReal() const { return real; }
	double getImaginario() const { return imaginario; }
};

#endif