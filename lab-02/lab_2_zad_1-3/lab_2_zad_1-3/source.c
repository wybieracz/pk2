/*@author Michal Pawlowski*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BUF_SIZE 10

typedef struct RGB {
	unsigned int R;
	unsigned int G;
	unsigned int B;
}RGB;

typedef struct element {
	struct element* pPrev;
	struct element* pNext;
	struct RGB color;
}element;

/** Funkcja generuje warto�ci RGB do momentu zape�nienia buforu
@date 2020-04-02
@param buf wska�nik na bufor
@param bufferLength aktualna liczba element�w bufora
@param writeIndex aktualna pozycja zapisu
*/
void makeRGB(RGB* buf, int* bufferLength, int* writeIndex) {

	srand(time(NULL));

	while (true) {

		if ((*bufferLength) == BUF_SIZE) break;

		buf[*writeIndex].R = rand() % 255;
		buf[*writeIndex].G = rand() % 255;
		buf[*writeIndex].B = rand() % 255;
		(*bufferLength)++;
		(*writeIndex)++;

		if ((*writeIndex) == BUF_SIZE) (*writeIndex) = 0;
	}
}

/** Funkcja odczytuje i kopiuje warto�ci z bufora do tablicy
@date 2020-04-02
@param buf wska�nik na bufor
@param tab tablica do kt�rej zostan� wczytane warto�ci
@param bufferLength aktualna liczba element�w bufora
@param writeIndex aktualna pozycja odczytu
*/
void readRGB(RGB* buf, RGB* tab, int* bufferLength, int* readIndex) {

	while (true) {

		if ((*bufferLength) == 0) break;

		tab[*readIndex] = buf[*readIndex];

		(*bufferLength)--;
		(*readIndex)++;

		if ((*readIndex) == BUF_SIZE) (*readIndex) = 0;
	}
}

/** Funkcja generuje warto�ci RGB do bufufora cyklicznego a nast�pnie przepisuje warto�ci do tablicy
@date 2020-04-02
@param tab tablica docelowa
*/
void circularBufferToTable(RGB tab[]) {

	struct RGB* circularBuffer = malloc(sizeof(RGB) * BUF_SIZE);
	int bufferLength = 0;
	int readIndex = 0;
	int writeIndex = 0;

	makeRGB(circularBuffer, &bufferLength, &writeIndex);
	readRGB(circularBuffer, tab, &bufferLength, &readIndex);

	free(circularBuffer);
}

/** Funkcja dodaje element do listy niepustej
@date 2020-04-02
@param pHead wska�nik na pocz�tek listy
@param color struktura zawieraj�ca warto�ci RGB
*/
void addElem(element** pHead, RGB color) {

	element* pHelp = *pHead;

	while (pHelp->pNext) pHelp = pHelp->pNext;

	pHelp->pNext = (element*)malloc(sizeof(element));
	pHelp->pNext->color = color;
	pHelp->pNext->pNext = NULL;
	pHelp->pNext->pPrev = pHelp;
}

/** Funkcja zlicza ilo�� ellement�w o wi�kszej zadanje warto�ci R
@date 2020-04-02
@param pHead wska�nik na pocz�tek listy
@param value zadana wartos�
*/
unsigned int countR(element* pHead, unsigned int value) {

	unsigned int number = 0;

	do {
		if (pHead->color.R > value) number++;
		pHead = pHead->pNext;
	} while (pHead);
	return number;
}

/** Funkcja usuwa liste
@date 2020-04-02
@param pHead wska�nik na pocz�tek lsty
*/
void deleteList(element** pHead) {

	if (*pHead) {
		deleteList((*pHead)->pNext);
		(*pHead)->pPrev->pNext = NULL;
		free(*pHead);
		*pHead = NULL;
	}
}

/** Funkcja tworzy list� dwukierunkow� z tablicy kolor�w a nast�pnie zlicza warto�ci wi�ksze od zadanej sk�adowej
@date 2020-04-02
@param tab wska�nik na tablice z danymi
*/
void makeListAndCount(RGB* tab) {
	
	element* pHead = NULL;
	pHead = (element*)malloc(sizeof(element));
	pHead->color = tab[0];
	pHead->pNext = NULL;
	pHead->pPrev = NULL;

	for (int i = 1; i < BUF_SIZE; i++) {
		addElem(&pHead, tab[i]);
	}

	printf("\nIlosc elementow o skladowej R wiekszej niz %d: %d", 128, countR(pHead, 128));

	deleteList(&pHead);
}

/** Funkcja tworzy list� dwukierunkow� z tablicy kolor�w a nast�pnie zlicza warto�ci wi�ksze od zadanej sk�adowej, wersja z arytmetyk� wska�nik�w
@date 2020-04-02
@param tab wska�nik na tablice z danymi
*/
void makeListAndCount2(RGB* tab) {

	RGB* ptr = tab;
	element* pHead = NULL;
	pHead = (element*)malloc(sizeof(element));
	pHead->color = *(ptr++);
	pHead->pNext = NULL;
	pHead->pPrev = NULL;

	for (int i = 1; i < BUF_SIZE; i++) {
		addElem(&pHead, *ptr++);
	}

	printf("\nIlosc elementow o skladowej R wiekszej niz %d: %d", 128, countR(pHead, 128));
}

int main(int argc, char* argv[]) {

	RGB tab[BUF_SIZE];

	circularBufferToTable(tab);

	for (int i = 0; i < BUF_SIZE; i++) {
		printf("%d,%d,%d\n", tab[i].R, tab[i].G, tab[i].B);
	}

	makeListAndCount2(tab);
}
