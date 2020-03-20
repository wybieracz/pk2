/*@author Michal Pawlowski*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

/** Funkacja wypisuje podana liczbe w systemie binarnym.
@date 2020-03-06
@param liczba liczba podana do konwersji
*/
void bin(int liczba) {

	if (liczba) {
		if (liczba != 1) {
			bin(liczba / 2);
			if (liczba % 2) {
				printf("%d", 1);
			}
			else {
				printf("%d", 0);
			}
		}
		else {
			printf("%d", 1);
		}
	}
	else {
		printf("%d", 0);
	}
}

int main(int argc, char* argv[]) {

	//zadanie 1
	
	int rozmiar = 5;
	int* tab = calloc(rozmiar, sizeof(int));

	//Pobieranie 5 liczb do konwersji
	for (int i = 0; i < rozmiar; i++) {
		printf("tab[%d]=", i);
		scanf_s("%d", &tab[i]);
	}

	//Wypisywanie liczb w systemie binarnym
	for (int i = 0; i < rozmiar; i++) {
		printf("tab[%d]=", i);
		bin(tab[i]);
		printf("\n");
	}

	return 0;
}
