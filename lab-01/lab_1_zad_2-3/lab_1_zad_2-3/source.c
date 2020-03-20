/*@author Michal Pawlowski*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

/** Funkacja oblicza dlugosc lancucha
@date 2020-03-06
@param napis wskaznik na lancuch podany do wyliczenia dlugosci
*/
int my_strlen(char* napis) {

	int liczba = 0;

	while (*napis++) {
		liczba++;
	}
	return liczba;
}

/** Funkacja wypisuje lancuch
@date 2020-03-06
@param napis wskaznik na lancuch podany do wypisania
*/
void write(char* napis) {

	do {
		printf("%c", *napis);
	} while (*napis++);
	printf("\n");
}

/** Funkacja sprawdza czy podany lancuch jest binarny
@date 2020-03-06
@param napis wskaznik na podany lancuch
*/
bool if_bin(char* napis) {

	if (!*napis) return false;
	while (*napis++) {
		if (*napis && *napis != '0' && *napis != '1') return false;
	}
	return true;
}

/** Funkacja zastepuje podany jeden bit
@date 2020-03-06
@param napis wskaznik na lancuch ze zemienianym bitem
@param bit wskaznik na lancuch z bitem zrodlowym
@param pozycja pozycja bitu
*/
void insert_one(char* napis, char* bit, unsigned int pozycja) {

	if (if_bin(napis) && if_bin(bit)) {
		
		if (pozycja < my_strlen(napis) && pozycja < my_strlen(bit)) {
			napis[pozycja] = bit[pozycja];
		}
		else {
			printf("Error: wyjscie poza zakres");
		}
	}
	else {
		printf("Error: bledny format!");
	}
}

/** Funkacja zastepuje podany zakres bitow
@date 2020-03-06
@param napis wskaznik na lancuch ze zmienianymi bitami
@param bit wskaznik na lancuch z bitami zrodlowymi
@param pozycja pozycja pierwszego zmienianego bitu
@param ilosc liczba zmienianych bitow
*/
void insert_range(char* napis1, char* napis2, unsigned int pozycja, unsigned int ilosc) {

	if (if_bin(napis1) && if_bin(napis2)) {

		if (pozycja+ilosc <= my_strlen(napis1) && pozycja+ilosc <= my_strlen(napis2)) {
			
			for (int i = pozycja; i < pozycja + ilosc; i++) {
				napis1[i] = napis2[i];
			}
		}
		else {
			printf("Error: wyjscie poza zakres\n");
		}
	}
	else {
		printf("Error: bledny format!\n");
	}
}

int main(int argc, char* argv[]) {

	//zadanie 2
	
	char alfa[] = "10101111";
	char bravo[] = "01010000";

	write(alfa);
	insert_one(alfa, bravo, 2);
	write(alfa);
	printf("\n");

	//zadanie 3

	char charlie[] = "11110000";
	char delta[] = "00001111";

	write(charlie);
	insert_range(charlie, delta, 4, 4);
	write(charlie);

	return 0;
}
