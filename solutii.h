#include "algoritmi.h"


void sol1() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = 5;

	int m = 5;

	int linie = 2;

	cout << "==============================INAINTE==============================" << endl;
	afisareMatrice(x, n,m);
	cout << "==============================DUPA==============================" << endl;
	stergereLinie(x, n, m, linie);

	afisareMatrice(x, n, m);
}

void sol2() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = 5;

	int m = 5;

	int coloana = 2;

	stergereColoana(x, n,m,coloana);

	afisareMatrice(x, n, m);
}


void sol3() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = 5;

	int m = 5;

	int linie = 3;

	inserareLinie(x, n, m, linie);

	afisareMatrice(x, n, m);
}

void sol4() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = 5;

	int m = 5;

	int coloana = 3;

	inserareColoana(x, n, m, coloana);

	afisareMatrice(x, n, m);
}


void sol5() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = 5;

	int m = 5;

	interschimbareLinii(x, n, m);

	afisareMatrice(x, n, m);
}


void sol6() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} };

	int n = 5;

	int m = 5;

	interschimbareColoane(x, n, m);

	afisareMatrice(x, n, m);
}

void sol7() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	stergereElement3CifreEgale(x, n, m);

	afisareMatrice(x, n, m);
}


void sol8() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	stergereAlDoileaElemPrim(x, n, m);

	afisareMatrice(x, n, m);
}


void sol9() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	stergereElemRar(x, n, m);

	afisareMatrice(x, n, m);
}

void sol10() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{1,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	stergereMaxima(x, n, m);

	afisareMatrice(x, n, m);
}

void sol11() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	stergereLiniiOrdonateCrescDesc(x, n, m);

	afisareMatrice(x, n, m);
}

void sol12() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	inserareColoanaRastElem(x, n, m);

	afisareMatrice(x, n, m);
}

void sol13() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	inserareLinieDubluElemPare(x, n, m);

	afisareMatrice(x, n, m);
}

void sol14() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	inserareColoanaCifraMinim(x, n, m);

	afisareMatrice(x, n, m);
}


void sol15() {

	int x[100][100] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,333,15},{16,17,18,19,20},{21,111,23,24,25} };

	int n = 5;

	int m = 5;

	inserareLinieElemPalin(x, n, m);

	afisareMatrice(x, n, m);
}