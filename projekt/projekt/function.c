/*@author Michal Pawlowski*/
/*@file function.c*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"
#include "header.h"

#ifndef FUNCTION
#define FUNCTION

void paramCpy(char* argv[], char** param, int* count, int* i) {

	*param = argv[*i + 1];
	(*count)++;
}

bool paramsCheck(int argc, char* argv[], char** input, char** output, char** ext) {
	
	int count = 0; // utworzenie zmiennej do zliczania poprawnie wczytanych parametrow startowych

	if (argc == 7) {

		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], "-i")) paramCpy(argv, input, &count, &i);
			if (!strcmp(argv[i], "-o")) paramCpy(argv, output, &count, &i);
			if (!strcmp(argv[i], "-e")) paramCpy(argv, ext, &count, &i);
		}

		if (count == 3) return true; // jezeli poprawnie wczytano 3 parametry, funkcja zwraca prawde
		else return false; // jezeli podano bledne parametry, funkcja zwraca falsz
	}

	else return false; // jezeli podano nieprawidlowa liczbe argumentow, funkcja zwraca falsz
}

void help() {

	printf("-------------------- H E L P --------------------\n");
	printf("Program must be started with 3 parameters:\n");
	printf("-i input file\n");
	printf("-o output file name\n");
	printf("-e output file extension (.txt or .html)\n");
	printf("-------------------------------------------------\n");
}

void openFile(char** buffer, char* input) {

	FILE* pFile;
	long long lSize;
	size_t result;

	pFile = fopen(input, "rb"); // otwarcie pliku do odczytu
	if (pFile == NULL) { fputs("WARNING: File error!", stderr); exit(1); } // wyswietlenie bledu jezeli plik nie zostal otworzony

	fseek(pFile, 0, SEEK_END); // przesuniecie kursora odczytu na koniec pliku
	lSize = ftell(pFile); // sczytanie pozycji
	rewind(pFile); // ustawienie kursora odczytu na poczatek pliku

	*buffer = (char*)malloc(sizeof(char) * lSize); // zaalokowanie pamieci rownej wielkosci pliku
	if (*buffer == NULL) { fputs("WARNING: Memory error!", stderr); exit(2); } // wyswietlenie bledu jezeli nie udalo sie przekopiowac zawartosci pliku do bufora

	result = fread(*buffer, 1, lSize, pFile); // sczytanie rozmiaru pliku
	if (result != lSize) { fputs("WARNING: Reading error!", stderr); exit(3); } // wyswietlenie bledu jezeli zawartosc bufora jest rozna od zawartosci pliku

	fclose(pFile);
}

bool linkcmp(char* parent, char* link, int bytes) {

	if (parent && link) {

		if (memcmp(parent, link, bytes) != 0) return false;
		else return true;
	}
	else {

		return false;
	}
}

void addFoundTitle(element** pHead, char* begin, char* end) {

	int byte = end - (begin + 7); // obliczenie rozmiaru tytulu
	(*pHead)->title = (char*)malloc(byte + 1); // alokacja pamieci
	memcpy((*pHead)->title, begin + 7, byte); // kopiowanie tyutlu
	(*pHead)->title[byte] = '\0'; // ustawienie konca ciagu znakow
}

void addUnknownTitle(element** pHead) {

	(*pHead)->title = (char*)malloc(16); // alokacja pamieci
	strcpy((*pHead)->title, "<Title unknown>"); // ustawienie tytulu
}

void addTitle(element** pHead, char* buffer) {
	
	if (*pHead) {

		char* begin = strstr(buffer, "<title>"); // wyszukanie poczatku tytulu
		char* end = strstr(buffer, "</title>"); // wyszukanie konca tytulu

		if (begin && end) addFoundTitle(pHead, begin, end); // wywolanie funkcji jezeli znaleziono tytul
		else addUnknownTitle(pHead); // wywolanie funkcji jezeli nie znaleziono tytulu
	}
}

void addNullElement(element** pHead) {

	*pHead = (element*)malloc(sizeof(element));
	(*pHead)->pNext = NULL;
	(*pHead)->subPage = NULL;
	(*pHead)->title = NULL;
	(*pHead)->link = NULL;
}

void addLinkToElement(element** pHead, char* begin, char* end) {

	int byte = end - begin; // obliczenie rozmiaru linku
	(*pHead)->link = (char*)malloc(byte + 1); // alokacja pamieci
	memcpy((*pHead)->link, begin, byte); // kopiowanie linku
	(*pHead)->link[byte] = '\0'; // ustawienie konca ciagu znakow
}

void addElement(element** pHead, char* begin, char* end) {

	if (*pHead) {

		if ((*pHead)->pNext) {
			
			// wywolanie funkcji dla kolejnego elementu listy
			addElement(&(*pHead)->pNext, begin, end);
		}
		else {

			// dodanie kolejnego elementu listy
			addNullElement(&(*pHead)->pNext);
			addLinkToElement(&(*pHead)->pNext, begin, end);
		}
	}
	else {

		// dodanie pierwszego elementu listy, lub listy odchodzacej
		addNullElement(pHead);
		addLinkToElement(pHead, begin, end);
	}
}

void addSubPages(element** pHead, char* buffer, element* pParent) {

	char* begin = buffer;
	char* end = NULL;

	while (begin) {

		// wyszukiwanie w petli odnosnikow do podstron
		begin = strstr(begin, "<a href=\"");
		if (begin) end = strstr(begin, "\">");

		if (begin && end && !pParent) {

			// dodanie elementow listy, podstron dla strony glownej
			addElement(&(*pHead)->subPage, begin + 9, end);
		}
		else if (begin && end && pParent && !linkcmp(pParent->link, begin + 9, strlen(pParent->link))) {

			// dodanie elementow listy, podstron dla podstron, jezeli nie jest to link powrotu do strony nadrzednej
			addElement(&(*pHead)->subPage, begin + 9, end);
		}

		if(begin) begin = end + 2;
	}
}

void createFirst(element** pHead, char* input) {

	*pHead = (element*)malloc(sizeof(element)); // alokacja pamieci dla pierwszego elementu
	(*pHead)->pNext = NULL;
	(*pHead)->subPage = NULL;
	(*pHead)->title = NULL;
	(*pHead)->link = (char*)malloc(strlen(input) + 1);
	memcpy((*pHead)->link, input, strlen(input) + 1); // ustawienie linku strony glownej z wczytanego parametru
}

void generete(element** pHead, element* pParent) {

	if (*pHead) {

		char* buffer = NULL;

		openFile(&buffer, (*pHead)->link); // pobranie danych do bufora

		if (buffer) {

			addTitle(&(*pHead), buffer); // dodanie tytulu
			addSubPages(&(*pHead), buffer, pParent); // dodanie podstron
			free(buffer);
		}
		else {
			exit(1);
		}

		if((*pHead)->subPage) generete(&(*pHead)->subPage, *pHead); // wywolanie funkcji dla pierwszej z podstron
		if((*pHead)->pNext) generete(&(*pHead)->pNext, pParent); // wywolanie funkcji dla kolejnej strony rownorzednej
	}
}

char* makeOutName(char* name, char* ext) {

	char* output = (char*)malloc(strlen(name) + strlen(ext) + 2); // alokacja pamieci 

	// polaczenie nazwy i rozszerzenia w pelna nazwe pliku

	strcpy(output, name);
	output[strlen(name)] = '.';
	strcpy(output + strlen(name) + 1, ext);
	output[strlen(name) + strlen(ext) + 1] = '\0';

	return output;
}

void printMap(element* pHead, int cut) {

	if (pHead) {

		// wypisanie struktury na konsoli

		for (int i = 0; i < cut; i++) printf("\t");

		if ((pHead)->title) printf("> %s\n\n", (pHead)->title);
		else printf("> <unknown title>\n\n");

		printMap((pHead)->subPage, cut + 1); // wywolanie funkcji dla pierwszej z podstron
		printMap((pHead)->pNext, cut); // wywolanie funkcji dla kolejnej strony rownorzednej
	}
}

void printTxt(element* pHead, int cut, FILE* pFile) {

	if (pHead) {

		// zapis do pliku txt

		for (int i = 0; i < cut; i++) fprintf(pFile, "\t");

		if ((pHead)->title) fprintf(pFile, "> %s\n", (pHead)->title);
		else fprintf(pFile, "> <unknown title>\n");

		fprintf(pFile, "\n");
		printTxt((pHead)->subPage, cut + 1, pFile); // wywolanie funkcji dla pierwszej z podstron
		printTxt((pHead)->pNext, cut, pFile); // wywolanie funkcji dla kolejnej strony rownorzednej
	}
}

void printHtml(element* pHead, int cut, FILE* pFile) {

	if (pHead) {

		// zapis do pliku html

		if ((pHead)->title) fprintf(pFile, "<span style=\"margin-left:%dem\">> <a href=\"%s\">%s</a></span><br>\n", cut*2, (pHead)->link, (pHead)->title);
		else fprintf(pFile, "<span style=\"margin-left:%dem\"> ><a href=\"%s\">Unknown title</a></span><br>\n", cut*2, (pHead)->link);

		printHtml((pHead)->subPage, cut + 1, pFile);
		printHtml((pHead)->pNext, cut, pFile);
	}
}

void saveMap(element* pHead, char* name, char* ext) {

	if (pHead) {

		if (strcmp(ext, "txt") == 0 || strcmp(ext, "html") == 0) {

			FILE* pFile;
			char* output = makeOutName(name, ext);
			pFile = fopen(output, "w");

			if (strcmp(ext, "txt") == 0) printTxt(pHead, 0, pFile); // zapis do pliku txt

			if (strcmp(ext, "html") == 0) {

				//zapis do pliku html
				fprintf(pFile, "<html>\n<head>\n<title>Website Map</title>\n</head>\n<body>\n");
				printHtml(pHead, 0, pFile);
				fprintf(pFile, "</body>\n</html>");
			}

			fclose(pFile);
			free(output);
		}
		else {
			fputs("WARNING: Saving file error! Unknown extension!\n", stderr); // komunikat bledu, jezeli nie mozliwy jest zapis do pliku
		}
	}
}

void deleteList(element** pHead) {

	if (*pHead) {

		// usuniecie calej struktury
		deleteList(&(*pHead)->pNext);
		deleteList(&(*pHead)->subPage);

		free((*pHead)->title);
		free((*pHead)->link);
		free(*pHead);
		*pHead = NULL;
	}
}
#endif