/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <Windows.h>


/** Funkcja kopiuje zawartoœæ pliku do bufora
@date 2020-04-25
@param buffer wskaŸnik na bufor
*/
void openFile(char **buffer) {

	FILE* pFile;
	long lSize;
	//char* buffer;
	size_t result;

	pFile = fopen("index.html", "rb");
	if (pFile == NULL) { fputs("File error", stderr); exit(1); }

	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	*buffer = (char*)malloc(sizeof(char) * lSize);
	if (*buffer == NULL) { fputs("Memory error", stderr); exit(2); }

	result = fread(*buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("Reading error", stderr); exit(3); }

	fclose(pFile);
}

/** Funkcja okreœla czy char nale¿y do znaków zapisu rzymskiego
@date 2020-04-25
@param sign char do sprawdzenia
*/
bool ifRome(char sign) {

	switch (sign){
	case 'I':
	case 'V':
	case 'X':
	case 'L':
	case 'C':
	case 'D':
	case 'M': return true;
		break;
	default: return false;
		break;
	}
}

/** Funkcja wypisuje wszystkie liczby rzymskie w formacie <z1><z2><z3>V<z4><z5><z6> z pliku
@date 2020-04-25
@param buffer wskaŸnik na bufor
*/
void printNum(char* buffer) {

	char* v;
	v = strchr(buffer, 'V');

	if (v && ifRome(*(v - 3)) && ifRome(*(v - 2)) && ifRome(*(v - 1)) && ifRome(*v) && ifRome(*(v + 1)) && ifRome(*(v + 2)) && ifRome(*(v + 3))) {
		printf("%c%c%c%c%c%c%c\n", *(v - 3), *(v - 2), *(v - 1), *v, *(v + 1), *(v + 2), *(v + 3));
		printNum(v + 4);
	}
}

int main() {
	{
	char* buffer = NULL;
	openFile(&buffer);
	printf("Znaleziono liczby rzymskie:\n");
	printNum(buffer);
	Sleep(10000);
	free(buffer);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}