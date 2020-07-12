/*@author Michal Pawlowski*/
/*@file source.c*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"
#include "struct.h"

int main(int argc, char* argv[]) {
	{
		int kappa = 1;
		// stworzenie 3 wskaznikow na parametry startowe

		char* input = NULL;
		char* output = NULL;
		char* ext = NULL;

		// sprawdzenie i przekopiowanie parametrow startowych na utworzone powyzej wskazniki

		if (!paramsCheck(argc, argv, &input, &output, &ext)) {

			help(); // wypisanie pomocy w razie blednego uruchomienia programu
		}

		else {

			element* pHead = NULL; // utworzenie wskaznika, glowy tworzonej struktury

			createFirst(&pHead, input); // utworzenie pierwszego elementu struktury w oparciu o parametr poczatkowy input
			generete(&pHead, NULL); // utworzenie reszty struktury, mapy witryny
			printMap(pHead, 0); // wypisanie struktury na konsoli
			saveMap(pHead, output, ext); // zapisanie mapy do pliku
			deleteList(&pHead); // usuniecie struktury
		}

		_CrtDumpMemoryLeaks();
		return 0;
	}
}