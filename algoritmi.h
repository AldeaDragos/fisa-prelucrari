#pragma once
#include <iostream>
#include <string.h>
using namespace std;

void stergereLinie(int a[100][100], int &n, int m, int linie) {


	for (int i = linie; i < n-1 ; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = a[i+1][j];

		}
	}
	n--;
}

void stergereColoana(int a[100][100], int n,int &m, int coloana) {

	for (int i = 0; i < n; i++) {
		for (int j = coloana; j < m-1; j++) {
			a[i][j] = a[i][j + 1];
		}
	}
	
	m--;
}

void inserareLinie(int a[100][100], int &n, int m, int linie) {

	for (int i = n; i > linie; i--) {
		for (int j = 0; j < m; j++) {
			a[i][j] = a[i-1][j];
		}
	}
	n++;
}

void inserareColoana(int a[100][100], int n, int& m, int coloana) {

	for (int i = 0; i < n; i++) {
		for (int j = n; j > coloana; j--) {
			a[i][j] = a[i][j - 1];
		}
	}
	m++;
}

void afisareMatrice(int a[100][100], int n,int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

}

void interschimbareLinii(int a[100][100], int n, int m) {

	for (int i = 0; i < n-1; i+=2) {
		for (int j = 0; j < m; j++) {
			int aux = a[i][j];
			a[i][j] = a[i+1][j];
			a[i+1][j] = aux;
		}
	}

}

void interschimbareColoane(int a[100][100], int n, int m) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j+=2) {
			int aux = a[i][j];
			a[i][j] = a[i][j+1];
			a[i][j+1] = aux;
		}
	}

}

// Stergeti linia si coloana tuturor elementelor cu proprietatea ce au exact 3 cifre egale intre ele

int gasireNr3CifreEgale(int n) {

	int f[10] = { 0 };
	
	while (n > 0) {
		int cifra = n % 10;
		f[cifra]++;
		n /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (f[i] >= 3) {
			return true;
		}
	}

	return false;
}

void stergereElement3CifreEgale(int a[100][100], int &n, int& m) {


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (gasireNr3CifreEgale(a[i][j])) {
				stergereLinie(a, n, m, i);
				stergereColoana(a, n, m, j);
			}
		}
	}

	


}

// Stergeti linia si coloana e care se afla al doilea numar primm din matrice. Daca matricea nu contine cel putin 2 numere prime , se vva afisa mesajul Nu exista.

int nrPrim(int n) {

	if (n <= 1) {
		return false;
	}

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

void stergereAlDoileaElemPrim(int a[100][100], int& n, int& m) {

	int ct = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nrPrim(a[i][j])) {
				ct++;
				if (ct == 2) {
					stergereLinie(a, n, m, i);
					stergereColoana(a, n, m, j);
				}
			}
		}
	}
	if (ct < 2) {
		cout << "Nu exista" << endl;
	}
}

// Stergeti linia ce are cel  mai rrar cifra k in componenta elementelor 

int aparitiiCifraK(int n, int k) {

	int ct = 0;
	while (n != 0) {
		if (n % 10 == k) {
			ct++;
		}
		n /= 10;
	}
	return ct;
}

void stergereElemRar(int a[100][100], int& n, int m) {

	int k;
	cout << "Introduceti o valoare pentru k: ";
	cin >> k;

	int f[100]={0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f[i] += aparitiiCifraK(a[i][j], k);
		}
	}

	int linieMinFrecventa = 0;

	for (int i = 1; i < n; i++) {
		if (f[i] < f[linieMinFrecventa]) {
			linieMinFrecventa = i;
		}
	}

	stergereLinie(a, n, m, linieMinFrecventa);

}

// Sa se stearga linia si coloana elementului cu frecventa maxima.
void stergereMaxima(int a[100][100], int& n, int& m) {

	int f[1000] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			f[a[i][j]]++;
		}
	}

	int elemFrecventaMaxima = a[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (f[a[i][j]] > f[elemFrecventaMaxima]) {
				elemFrecventaMaxima = a[i][j];
			}
		}
	}

	int linieElemMax = -1;
	int coloanaElemMax = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == elemFrecventaMaxima) {
				linieElemMax = i;
				coloanaElemMax = j;
			}
		}
	}

	stergereLinie(a, n, m, linieElemMax);
	stergereColoana(a, n, m, coloanaElemMax);

}

//Stergeti toate liniile ce nu au elemente ordnate(crescator sau descrescator);

int liniiOrdCresc(int a[], int m) {


	for (int j = 0; j < m-1; j++) {
		if (a[j] > a[j + 1]) {
			return false;
		}

	}
	return true;
}

int liniiOrdDesc(int a[], int m) {

	for (int j = 0; j < m-1; j++) {
		if (a[j] < a[j + 1]) {
			return false;
		}
	}
	return true;
}

void stergereLiniiOrdonateCrescDesc(int a[100][100], int& n, int m) {



	for (int i = 0; i < n; i++) {

		if (!liniiOrdCresc(a[i], m) && !liniiOrdDesc(a[i], m)) {
			stergereLinie(a, n, m, i);
		}
	}
}

// Inserati dupa a doua coloana ce contine cel putin un patrat perfect , rasturnatul fiecarui element din aceasta . In caz ca nu avem o astfel de coloana se va afisa mesajul " NU ";

int patratPerfect(int n) {

	if (sqrt(n) * sqrt(n) == n) {
		return true;
	}
	return false;
}

int rasturnatNumar(int n) {

	int numarNou = 0;

	while (n != 0) {
		int cifra = n % 10;
		numarNou = numarNou * 10 + cifra;
		n = n / 10;
	}
	return numarNou;
}

void inserareColoanaRastElem(int a[100][100], int n, int& m) {

	int ct = 0;
	int colGasita = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (patratPerfect(a[i][j])) {
				ct++;
			}
			if (ct == 2) {
				colGasita = j;
			}
		}
	}

	inserareColoana(a, n, m, colGasita);

	for (int i = 0; i < n; i++) {
		a[i][colGasita + 1] = rasturnatNumar(a[i][colGasita]);
	}

}

// Sa se insereze dupa linia cu cele mai multe elemente pare, dublul ei

void inserareLinieDubluElemPare(int a[100][100], int& n, int m) {

	int nrMaxP = 0;
	int linieGasita = -1;

	for (int i = 0; i < n; i++) {
		int ctPare = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] % 2 == 0) {
				ctPare++;
			}
		}
		if (ctPare > nrMaxP) {
			nrMaxP = ctPare;
			linieGasita = i;
		}
	}

	inserareLinie(a, n, m, linieGasita);

	for (int j = 0; j < m; j++) {
		a[linieGasita + 1][j] = 2 * a[linieGasita][j];
	}

}

// Sa se insereze inainte de coloana pe care se afla cele mai multe elemente de maxim , cifra minima dintre toate elementele vectorului. Daca exista mai multe coloane cu acelasi numar de aparitii se va lua in considerare ultima coloana

int gasireMaxim(int a[100][100], int n, int m) {

	int maxim = a[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > maxim) {
				maxim = a[i][j];
			}
		}
	}
	return maxim;
}

int cifraMinima(int a[100][100], int n, int m) {

	int cifraMin = 9;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int nr = a[i][j];
			while (nr != 0) {
				int cifra = nr % 10;
				if (cifra < cifraMin) {
					cifraMin = cifra;
				}
				nr = nr / 10;
			}
		}
	}
	return cifraMin;
}

void inserareColoana2(int a[100][100], int n, int& m, int coloana,int valoare) {

	for (int i = 0; i < n; i++) {
		for (int j = m; j > coloana; j--) {
			a[i][j] = a[i][j - 1];
		}
		a[i][coloana] = valoare;
	}
	m++;
}

void inserareColoanaCifraMinim(int a[100][100], int n, int& m) {

	int maxim = gasireMaxim(a, n, m);

	int ct = 0;
	
	int maxCt = 0;

	int colMax = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == maxim) {
				ct++;
			}
			if (ct >= maxCt) {
				maxCt = ct;
				colMax = j;
			}
		}
	}

	int minCifra = cifraMinima(a, n, m);

	inserareColoana2(a, n, m, colMax, minCifra);

}

//Inserati dupa fiecare coloana ce este formata din elementet in care fiecare cifra (0-9) appare cel putin o data , cifra de control a fiecarui element

//Inserati dupa linia pe care  se gaseste primul element palindrom ce are intre 3 si 5 divizori proprii, dublul ei

int palindrom(int n) {

	int inv = rasturnatNumar(n);

	if (n != inv) {
		return false;
	}
	return true;
}

int nrDiv(int n) {

	int ct = 0;

	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			ct++;
		}
	}
	return ct;
}

void inserareLinieElemPalin(int a[100][100], int& n, int m) {



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (palindrom(a[i][j])) {
				int divizori = nrDiv(a[i][j]);
				if (divizori >= 3 && divizori <= 5) {
					int elem = a[i][j];
					inserareLinie(a, n, m, i);
					for (int k = 0; k < m; k++) {
						a[i + 1][k] = 2*elem;
					}
					
				}
			}
		}
	}

}