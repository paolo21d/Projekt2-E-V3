#include <iostream>
#include <limits>

#include "Complex.h"
#include "Setcomplex.h"
using namespace std;



int main() {
	int opcja, wczytNumZbi, wczytNumZbi2;
	float re, im;
	//list <Setcomplex<float, float>> zbiory;
	Setcomplex<float, float> *zbiory = new Setcomplex<float, float>[2];
	int bierzacyRozmiar = 0;
	int maxRozmiar = 2;
	while (1) {
		cout << "MENU" << endl;
		cout << "1 Dodaj nowy pusty zbior" << endl;
		cout << "2 Dodaj liczbe do zbioru" << endl;
		cout << "3 Iloczyn zbiorow" << endl;
		cout << "4 Suma zbiorow" << endl;
		cout << "5 Wypisz zbiory" << endl;
		cout << "0 Wyjscie z programu" << endl;
		cout << "Liczby wprowadzamy w postaci: czesc_rzeczywista czesc_urojona" << endl;
		//cin >> opcja;
		while (!(cin >> opcja)) {
			cout << endl << "Blad! Podaj odpowiedni numer ";
			cin.clear();
			cin.ignore(1024, '\n');
		}
		if (opcja == 1) {
			if (bierzacyRozmiar == maxRozmiar - 1) { // zwiekszamy tablice 2 krotnie
				Setcomplex<float, float> * tmp = new Setcomplex<float, float>[bierzacyRozmiar+1];
				if (tmp == nullptr) {
					cout << "Blad alokacji!";
					return 1;
				}
				for (int i = 0; i < bierzacyRozmiar; i++) {
					//cout << "i:" << i << endl;
					tmp[i] = zbiory[i];
				}
					

				delete[]zbiory;
				zbiory = new Setcomplex<float, float>[2 * maxRozmiar];
				if (zbiory == nullptr) {//nie udalo sie zaalokowac pamieci
					delete[] tmp;
					cout << "Blad alokacji!";
					return 1;
				}
				maxRozmiar *= 2;
				for (int i = 0; i<bierzacyRozmiar; i++)
					zbiory[i] = tmp[i];
				delete[]tmp;
				//zbiory[bierzacyRozmiar] = z;
				bierzacyRozmiar++;
			}
			else { //dodajemy na koniec tablicy obiekt complex
				//zbiory[bierzacyRozmiar] = z;
				bierzacyRozmiar++;
			}
			cout << "Dodano zbior o numerze: " << bierzacyRozmiar - 1 << endl;
		}
		else if (opcja == 2) { //dodaj element
			cout << "Podaj liczbe z ";
			while (!(cin >> re >> im)) {
				cout << endl << "Blad! Podaj liczbe z ";
				cin.clear();
				cin.ignore(1024, '\n');
			}
			Complex<float, float> z(re, im);
			cout << "Podaj do ktorego zbioru chcesz dodac liczbe: ";
			while (true) {
				while (!(cin >> wczytNumZbi)) {
					cout << endl << "Blad! Podaj numer zbioru ";
					cin.clear();
					cin.ignore(1024, '\n');
				}
				if (wczytNumZbi<0 || wczytNumZbi >= bierzacyRozmiar) {
					cout << "Nie ma takiego zbioru, podaj jeszcze raz: ";
					continue;
				}
				break;
			}
			int iterator =wczytNumZbi;
			//for (int i = 0; i < wczytNumZbi; i++) { iterator++; }
			zbiory[iterator].dodajElement(z);
			cout << "Dodano element " << z << " do zbioru numer " << wczytNumZbi << endl;
		}
		else if (opcja == 3) { //iloczyn
			cout << "Podaj numery dwoch zbiorow ktorych czesci wspolnej szukasz(iloczyn): " << endl;
			while (true) {
				while (!(cin >> wczytNumZbi >> wczytNumZbi2)) {
					cout << endl << "Blad! Podaj numery zbiorow ";
					cin.clear();
					cin.ignore(1024, '\n');
				}
				if (wczytNumZbi<0 || wczytNumZbi >= bierzacyRozmiar || wczytNumZbi2<0 || wczytNumZbi2 >= bierzacyRozmiar) {
					cout << "Nie ma takiego zbioru, podaj jeszcze raz: ";
					continue;
				}
				break;
			}
			Setcomplex<float, float> iloczyn;
			int zb1 = wczytNumZbi;
			int zb2 = wczytNumZbi2;
			//for (int i = 0; i < wczytNumZbi; i++) { zb1++; }
			//for (int i = 0; i < wczytNumZbi2; i++) { zb2++; }
			////Iloczynowanie
			for (int i = 0; i < zbiory[zb1].listaSize(); i++) {
				for (int j = 0; j < zbiory[zb2].listaSize(); j++) {
					if (zbiory[zb1].getElement(i) == zbiory[zb2].getElement(j)) {
						iloczyn.dodajElement(zbiory[zb1].getElement(i));
					}
				}
			}
			/*for (int i = 0; i < zb2->listaSize(); i++) {
			for (int j = 0; j < zb1->listaSize(); j++) {
			if (zb2->getElement(i) == zb1->getElement(j)) {
			iloczyn.dodajElement(zb2->getElement(i));
			}
			}
			}*/
			cout << "Iloczyn zbiorow: ";
			iloczyn.wypiszZbior();
			cout << endl;
		}
		else if (opcja == 4) { //suma
			cout << "Podaj numery dwoch zbiorow ktorych sumy szukasz: " << endl;
			while (true) {
				while (!(cin >> wczytNumZbi >> wczytNumZbi2)) {
					cout << endl << "Blad! Podaj numery zbiorow ";
					cin.clear();
					cin.ignore(1024, '\n');
				}
				if (wczytNumZbi<0 || wczytNumZbi >= bierzacyRozmiar || wczytNumZbi2<0 || wczytNumZbi2 >= bierzacyRozmiar) {
					cout << "Nie ma takiego zbioru, podaj jeszcze raz: ";
					continue;
				}
				break;
			}
			Setcomplex<float, float> suma;
			int zb1 = wczytNumZbi;
			int zb2 = wczytNumZbi2;
			//for (int i = 0; i < wczytNumZbi; i++) { zb1++; }
			//for (int i = 0; i < wczytNumZbi2; i++) { zb2++; }
			////Sumowanie
			for (int i = 0; i < zbiory[zb1].listaSize(); i++) {
				suma.dodajElement(zbiory[zb1].getElement(i));
			}
			for (int i = 0; i < zbiory[zb2].listaSize(); i++) {
				suma.dodajElement(zbiory[zb2].getElement(i));
			}
			cout << "Suma zbiorow: ";
			suma.wypiszZbior();
			cout << endl;
		}
		else if (opcja == 5) { //wypisanie zbiorow
			int i = 0;
			if (bierzacyRozmiar==0) {
				cout << "Brak zbiorow" << endl;
			}
			for (int i=0; i<bierzacyRozmiar; i++) {
				cout << "Zbior numer: " << i << endl;
				zbiory[i].wypiszZbior();
				cout << endl;
			}
		}
		else if (opcja == 0) {
			/*for (int i = 0; i < bierzacyRozmiar; i++) {
				zbiory[i].clear();
			}*/
			if (zbiory != nullptr)
				delete[]zbiory;
			break;
		}
		else {
			cout << "Bladna opcja!" << endl;
		}
	}
	return 0;
}