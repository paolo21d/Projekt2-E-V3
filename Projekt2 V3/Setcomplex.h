//
// Created by Ewa Turska on 24.04.2018.
//

#ifndef V2_SETCOMPLEX_H
#define V2_SETCOMPLEX_H

#include <iostream>
#include "Complex.h"

template <typename Tre, typename Tim>
class Setcomplex {
	Complex<Tre, Tim>* lista;
	int bierzacyRozmiar, maxRozmiar;
public:
	Setcomplex() : bierzacyRozmiar(0), maxRozmiar(2) {
		lista = new Complex<Tre, Tim>[2];
	};
	~Setcomplex() {
		delete[] lista;
	}
	int dodajElement(Complex<Tre, Tim>& z) {
		//0-nie udalo sie zaalokowac pamieci, 1-elemnt juz wystapil w zbiorze, 2-udalo sie dodac
		if (bierzacyRozmiar != 0) {
			for (int i = 0; i<bierzacyRozmiar; i++) {
				if (lista[i] == z)
					return 1;
			}
		}

		if (bierzacyRozmiar == maxRozmiar - 1) { // zwiekszamy tablice 2 krotnie
			Complex<Tre, Tim> * tmp = new Complex<Tre, Tim>[bierzacyRozmiar];
			if (tmp == nullptr) {
				return 0;
			}
			for (int i = 0; i<bierzacyRozmiar; i++)
				tmp[i] = lista[i];

			delete[]lista;
			lista = new Complex<Tre, Tim>[2 * maxRozmiar];
			if (lista == nullptr) {//nie udalo sie zaalokowac pamieci
				delete[] tmp;
				return 0;
			}
			maxRozmiar *= 2;
			for (int i = 0; i<bierzacyRozmiar; i++)
				lista[i] = tmp[i];
			delete[]tmp;
			lista[bierzacyRozmiar] = z;
			bierzacyRozmiar++;
		}
		else { //dodajemy na koniec tablicy obiekt complex
			lista[bierzacyRozmiar] = z;
			bierzacyRozmiar++;
		}
		return 2;
	}
	void wypiszZbior() const {
		if (bierzacyRozmiar == 0)
			std::cout << "Pusty zbior." << std::endl;
		else {
			for (int i = 0; i<bierzacyRozmiar ; i++) {
				std::cout << lista[i] << " ";
			}
		}
	}
	Complex<Tre, Tim> getElement(int numer) const {
		return lista[numer];
	}
	int listaSize() const {
		return bierzacyRozmiar;
	}

	bool empty() {
		if (bierzacyRozmiar == 0)
			return true;
		return false;
	}
	void clear() {
		if(lista != nullptr)
			delete[] lista;
	}
	Setcomplex <Tre, Tim> & operator=(Setcomplex<Tre, Tim> & z) {
		if(lista!=nullptr)
			delete [] lista;
		bierzacyRozmiar = z.bierzacyRozmiar;
		maxRozmiar = z.maxRozmiar;
		lista = new Complex<Tre, Tim>[bierzacyRozmiar];
		for (int i = 0; i < bierzacyRozmiar; i++) {
			lista[i] = z.lista[i];
		}
		return *this;
	}
};
#endif //V2_SETCOMPLEX_H