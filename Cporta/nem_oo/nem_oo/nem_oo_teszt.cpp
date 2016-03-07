/**
* \file nem_oo_teszt.cpp (latin2 kodolasu fajl)
*
* A C++ nem OO bővítéseinek gyakorlásához.
*
* FELADAT:
*  Valósítsa meg a nem_oo.h állományban deklarált függvényeket!
*  Ellenőrizze azok működését az alábbi tesztprogrammal.
*
* Szorgalmi feladat:
*  A tesztprogram egy részletet mutat arra, hogy helyes nyelvi
*  beállításokkal ékezetes szöveget is össze lehet hasonlítani.
*
*  Az ékezetes szöveg kezeléséhez további segítséget itt talál:
*  http://infocpp.iit.bme.hu/ekezetes
*
*/
#include <iostream>
#include <cstring>
#include <locale>               // ékezetekhez kell

#include "nem_oo.h"

using namespace std;

/**
* Szorgalmi feladathoz.
* Összehasonlít két nullával lezárt stringet és kiírja az eredményt
* Az összehasonlító függvényt paraméterként kapja.
*/
typedef int(*cmp_t)(const char *, const char *);
void printOrderOf(const char *s1, const char *s2, cmp_t cmp) {
	char ch = '=';
	int ret = cmp(s1, s2);
	if (ret < 0)
		ch = '<';
	else if (ret > 0)
		ch = '>';
	cout << s1 << " " << ch << " " << s2 << endl;
}

/**
* Ezt a tesztprogramot futtatja a CPORTA
*/
int main() {
#ifndef CPORTA      // Cporta-n nem akarjuk ezt a részt futtatni.
	const char *duma1 = "Ádám";
	const char *duma2 = "Béla";

	cout << "Alapertelmezett locale: " << setlocale(LC_ALL, NULL) << endl;
	cout << "strcmp: ";
	printOrderOf(duma1, duma2, strcmp);
	cout << "strcoll: ";
	printOrderOf(duma1, duma2, strcoll);

	// alapértelmezett nyelvi környezet beállítása (remélhetőleg latin2)
	cout << endl << "Környzeti locale: " << setlocale(LC_ALL, "") << endl;
	cout << "strcmp: ";
	printOrderOf(duma1, duma2, strcmp);
	cout << "strcoll: ";
	printOrderOf(duma1, duma2, strcoll);
#endif // CPORTA

	try {
		cout << sajat::atoi("100") << endl;     // 10-es számrendszerben: 100
		cout << sajat::atoi("100", 8) << endl;  // 8-asban: 64
		cout << sajat::atoi("100", 2) << endl;  // 2-esben: 4

												// kipróbáljuk az strcat-ot:
		char *str = sajat::strcat("Mit sütsz kis szűcs?\n", "Sós húst sütsz kis szűcs?");
		cout << str << endl;
		delete[] str;          // Nekünk kell felszabadítani!

							   // kipróbáljuk a swap-et
		int a = 1;
		int b = 2;
		swap(a, b);            // referenciát vár: nem kell &!
		cout << "a=" << a << " b=" << b << endl; // megcserélte ?

												 // kipróbáljuk a unique-ot
		char test[] = "ssszia C+++++ + !\n";     // sok ismétlődő kar.

		cout << test;
		char *p = sajat::unique(test, test + strlen(test));
		*p = 0;                      // p az új sorozat végére mutat
		cout << test;

		// itt egy nagyobb próba következik a standard inputról
		const int SORHOSSZ = 100;
		int base = 9;				// ebben a számrendszerben várjuk az első sort
#ifdef DEBUG
		cout << "Számot várunk (base: " << base << "):";
#endif // DEBUG
		char buf1[SORHOSSZ];
		while (cin.getline(buf1, SORHOSSZ)) {    // amíg van file
			char buf2[SORHOSSZ];
			buf2[0] = 0;
#ifdef DEBUG
			cout << "Következő sor: ";
#endif // DEBUG
			cin.getline(buf2, SORHOSSZ);
			str = sajat::strcat(buf1, buf2);      // két soronként összefűzzük az inputot
			cout << str << endl;                  // kiírjuk
			delete[] str;                         // nem kell tovább a string
			int val = sajat::atoi(buf1, base); 	// átalakítás base rendszerből
#ifdef DEBUG
			cout << "A szám átalakítva: ";
#endif // DEBUG
			cout << val << endl; 			        // kiírjuk
			base = val % 9 + 2;			        // ebben a számrendszerben várjuk legközelebb
#ifdef DEBUG
			cout << "Számot várunk (base: " << base << "):";
#endif // DEBUG
		}
	}
	catch (const char *p) {
		cout << "const char* kivétel jött: " << p << endl;
	}
	catch (...) {
		cout << "Baj van: Nem várt kivétel jött" << endl;
	}
	return 0;
}