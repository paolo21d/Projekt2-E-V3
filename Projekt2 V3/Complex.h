//
// Created by Ewa on 06.03.2018.
//

#ifndef PROJEKT2_COMPLEX_H
#define PROJEKT2_COMPLEX_H

#include <iostream>
#include <cmath>
template <typename Tre, typename Tim>
class Complex {
private:
	Tre re;
	Tim im;
public:
	Complex() : re(0), im(0) {}
	Complex(Tre r, Tim i) : re(r), im(i) {}
	Complex(const Complex &com) : re(com.re), im(com.im) {}//konstruktor kopiujacy
	Complex(Tre r) : re(r), im(0) {};
	~Complex() {
		//std::cout << "Destruktor." << std::endl;
	}

	Tre getRe() const {
		return this->re;
	}
	Tim getIm() const {
		return this->im;
	}
	void ustaw(Tre r, Tim i) {
		re = r;
		im = i;
	}
	double modul() {
		return sqrt(re * re + im * im);
	}
	double argument() {
		if (this->modul() == 0) {
			std::cout << "Modul=0, brak argumentu" << std::endl;
			return 0;
		}
		return asin(im / this->modul());
	}

	friend std::ostream &operator<<(std::ostream &wyjscie, const Complex &z) {
		if (z.getIm() > 0)
			return wyjscie << z.getRe() << "+" << z.getIm() << "i";
		else if (z.getIm() < 0)
			return wyjscie << z.getRe() << "" << z.getIm() << "i";
		else
			return wyjscie << z.getRe();
	}


	friend Complex operator+(const Complex &z1, const Complex &z2) {
		return Complex(z1.re + z2.re, z1.im + z2.im);
	}

	friend Complex operator-(const Complex &z1, const Complex &z2) {
		return Complex(z1.re - z2.re, z1.im - z2.im);
	}

	friend Complex operator*(const Complex &z1, const Complex &z2) {
		Tre r = z1.re * z2.re - z1.im * z2.im;
		Tim i = z1.re * z2.im + z1.im * z2.re;
		return Complex(r, i);
	}
	/*Complex &operator= (const Complex &z) {
		re = z.re;
		im = z.im;

	}*/
	//_zwracany_typ_ & operator +=( const _typ_ & );
	Complex &operator+=(const Complex &z) {
		this->re += z.re;
		this->im += z.im;
		return *this;
	}

	Complex &operator-=(const Complex &z) {
		this->re -= z.re;
		this->im -= z.im;
		return *this;
	}

	Complex &operator*=(const Complex &z) {
		this->re = this->re * z.re - this->im * z.im;
		this->im = this->re * z.im + this->im * z.re;
		return *this;
	}

	//Operatory porownywania
	bool operator< (const Complex<Tre, Tim>& z) const {
		bool result = true;
		if ((re >= z.re) && (re != z.re || im >= z.im)) {
			result = false;
		}
		return result;
	}
	/*bool operator<(const Complex &z) {
	if ((re < z.re) || (re == z.re && im < z.im))
	return true;
	else return false;
	}
	bool operator>(const Complex &z) {
	if ((re > z.re) || (re == z.re && im > z.im))
	return true;
	else return false;
	}*/
	bool operator==(const Complex &z) {
		if (re == z.re && im == z.im)
			return true;
		else return false;
	}
};

#endif //PROJEKT2_COMPLEX_H