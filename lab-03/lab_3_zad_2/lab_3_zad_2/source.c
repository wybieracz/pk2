/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

typedef struct element {
	int liczba;
	struct element* pNext;
}element;

/** Funkcja sprawdza parametry wejœciowe oraz wczytuje z nich dane do zmiennych
@date 2020-04-15
@param argc ilosc wczytanych parametrow
@param argv tablica wczytanych parametrów
@param ilosc_k wskaŸnik na zmienn¹ okreœlaj¹c¹ iloœæ kolumn
@param ilosc_w wskaŸnik na zmienn¹ okreœlaj¹c¹ iloœæ wierszy
@param zakres_d wskaŸnik na zmienn¹ okreœlaj¹c¹ dolny zakres generowanych liczb
@param zakres_g wskaŸnik na zmienn¹ okreœlaj¹c¹ górny zakres generowanych liczb
@return prawdê je¿eli podano prawid³owo parametry
*/
bool sprawdzArgumenty(int argc, char* argv[], int* ilosc_k, int* ilosc_w, int* zakres_d, int* zakres_g) {

	///< sprawdzenie czy zostala podana zgodna ilosc argumentow

	char* k = "-k";
	char* w = "-w";
	char* d = "-d";
	char* g = "-g";
	int zlicz = 0;

	if (argc <= 9) {

		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], k)) {

				*ilosc_k = atoi(argv[i + 1]);
				zlicz++;
			}

			if (!strcmp(argv[i], w)) {

				*ilosc_w = atoi(argv[i + 1]);
				zlicz++;
			}

			if (!strcmp(argv[i], d)) {

				*zakres_d = atoi(argv[i + 1]);
				zlicz++;
			}

			if (!strcmp(argv[i], g)) {

				*zakres_g = atoi(argv[i + 1]);
				zlicz++;
			}
		}

		if (zlicz == 4) return true;

		else return false;
	}

	else return false;
}

/** Funkcja wypiuje pomoc
@date 2020-04-15
*/
void pomoc() {

	printf("------------------- P O M O C -------------------\n");
	printf("Uwaga! Program nalezy uruchamiac z 4 parametrami:\n");
	printf("-w ilosc wierszy\n");
	printf("-k ilosc kolumn\n");
	printf("-d dolny zakres generowanych liczb\n");
	printf("-g gorny zakres generowanych liczb\n");
	printf("-------------------------------------------------\n");
}

/** Funkcja losuj¹ca
@date 2020-04-15
@param zakres_d zmienna okreœlaj¹ca dolny zakres generowanej liczby
@param zakres_g zmienna okreœlaj¹ca górny zakres generowanej liczby
@return liczbê pseudo losow¹
*/
int los(int zakres_d, int zakres_g){

	return zakres_d + rand() % (zakres_g - zakres_d + 1);
}

/** Funkcja generuj¹ca plik csv z danymi seudo losowymi
@date 2020-04-15
@param ilosc_k iloœæ kolumn
@param ilosc_w iloœæ wierszy
@param zakres_d dolny zakres generowanych liczb
@param zakres_g górny zakres generowanych liczb
*/
void generuj(int ilosc_k, int ilosc_w, int zakres_d, int zakres_g) {

	FILE* fp;
	fp = fopen("dane.csv", "w");

	if (!fp) {
		printf("Blad zapisu!\n");
		exit(1);
	}

	for (int i = 0; i < ilosc_w; i++) {

		for (int j = 0; j < ilosc_k; j++) {

			fprintf(fp, "%d", los(zakres_d, zakres_g));
			if (j == ilosc_k - 1) fprintf(fp, "\n");
			else fprintf(fp, ", ");
		}
	}
	fclose(fp);
}

/** Funkcja generuj¹ca plik binarny dat z zapisanymi parametrami
@date 2020-04-15
@param ilosc_k iloœæ kolumn
@param ilosc_w iloœæ wierszy
@param zakres_d dolny zakres generowanych liczb
@param zakres_g górny zakres generowanych liczb
*/
void zapiszParamDat(int ilosc_k, int ilosc_w, int zakres_d, int zakres_g) {

	FILE* fDat;
	fDat = fopen("propertis.dat", "wb");

	if (!fDat) {
		printf("Blad zapisu!\n");
		exit(1);
	}

	fprintf(fDat, "%d ", ilosc_k);
	fprintf(fDat, "%d ", ilosc_w);
	fprintf(fDat, "%d ", zakres_d);
	fprintf(fDat, "%d ", zakres_g);

	fclose(fDat);
}

/** Funkcja generuj¹ca plik json z zapisanymi parametrami
@date 2020-04-15
@param ilosc_k iloœæ kolumn
@param ilosc_w iloœæ wierszy
@param zakres_d dolny zakres generowanych liczb
@param zakres_g górny zakres generowanych liczb
*/
void zapiszParamJson(int ilosc_k, int ilosc_w, int zakres_d, int zakres_g) {

	FILE* fJson;
	fJson = fopen("propertis.json", "w");

	if (!fJson) {
		printf("Blad zapisu!\n");
		exit(1);
	}

	fprintf(fJson, "{\n");
	fprintf(fJson, "	%cparams%c: {\n", '"', '"');
	fprintf(fJson, "		%ckolumny%c: %d,\n", '"', '"', ilosc_k);
	fprintf(fJson, "		%cwiersze%c: %d,\n", '"', '"', ilosc_w);
	fprintf(fJson, "		%czakres dolny%c: %d,\n", '"', '"', zakres_d);
	fprintf(fJson, "		%czakres gorny%c: %d,\n", '"', '"', zakres_g);
	fprintf(fJson, "	}\n");
	fprintf(fJson, "}\n");

	fclose(fJson);
}

/** Funkcja dodaje element do listy niepustej w sposób posortowany
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
@param liczba wartoœæ do dodania
*/
void dodElem(element** pHead, int liczba) {

	element* pHelp = *pHead;
	element* pHelp2 = NULL;
	
	if (liczba < pHelp->liczba) {
		pHelp2 = (element*)malloc(sizeof(element));
		pHelp2->liczba = liczba;
		pHelp2->pNext = pHelp;
		*pHead = pHelp2;
	}
	else {
		while (pHelp->pNext && liczba >= pHelp->pNext->liczba)
			pHelp = pHelp->pNext;
		
		if (pHelp->pNext) {
			pHelp2 = pHelp->pNext;
			pHelp->pNext = NULL;
			pHelp->pNext = (element*)malloc(sizeof(element));
			pHelp->pNext->liczba = liczba;
			pHelp->pNext->pNext = pHelp2;
		}
		else {
			pHelp->pNext = (element*)malloc(sizeof(element));
			pHelp->pNext->liczba = liczba;
			pHelp->pNext->pNext = NULL;
		}
	}
}

/** Funkcja usuwa liste
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek lsty
*/
void usunListe(element** pHead) {

	element* pHelp = *pHead;

	while (*pHead) {
		
		*pHead = (*pHead)->pNext;
		free(pHelp);
		pHelp = *pHead;
	}
}


/** Funkcja wypisuje liste
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
*/
void wypisz(element* pHead) {
	while (pHead) {
		printf("%d	", pHead->liczba);
		pHead = pHead->pNext;
	}
}

/** Funkcja wypisuje wartoœæ zadanego argumentem elementu. W wypadku podania nr przekraczaj¹cego liczbê elementów, funkcja zwróci ostatni element z listy
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
@param nr numer elementu
@return wartoœæ elementu
*/
int wypiszEl(element* pHead, unsigned int nr) {

	if (pHead) {

		for (int i = 1; i < nr; i++) {

			pHead = pHead->pNext;
		}

		return pHead->liczba;
	}
}

/** Funkcja liczy ilosæ elementów w liœcie
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
@return iloœæ elementów
*/
int policzEl(element* pHead) {

	int i = 0;

	while (pHead) {
		i++;
		pHead = pHead->pNext;
	}
	return i;
}

/** Funkcja podaje element o maksymalnej wartoœci z listy posortowanej rosn¹co
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
@return wartoœæ elementu o najwiêksej wartoœci
*/
int elMax(element* pHead) {

	if (pHead) {
		
		while (pHead->pNext) pHead = pHead->pNext;
		return pHead->liczba;
	} else return 0;
}


/** Funkcja wylicza œredni¹ wartoœci elementów z listy
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
@return wartoœæ œredni¹
*/
float srednia(element* pHead) {

	if (pHead) {

		float i = 0;
		float suma = 0;

		while (pHead) {
			
			i++;
			suma += pHead->liczba;
			pHead = pHead->pNext;
		}

		return suma / i;
	}
	else return 0;
}

/** Funkcja wylicza medianê wartoœci elementów z listy
@date 2020-04-02
@param pHead wskaŸnik na pocz¹tek listy
@return miedianê elementów 
*/
float mediana(element* pHead) {

	if (pHead) {

		float dwa = 2;

		if (policzEl(pHead) % 2) {
			return wypiszEl(pHead, (policzEl(pHead)/2)+1);
		}
		else {
			return (wypiszEl(pHead, (policzEl(pHead) / 2)) + wypiszEl(pHead, (policzEl(pHead) / 2) + 1)) / dwa;
		}
	}
	else return 0;
}

/** Funkcja generuj¹ca plik csv ze statystyk¹ danych z wycztanego pliku
@date 2020-04-15
@param ilosc_k iloœæ kolumn
@param ilosc_w iloœæ wierszy
*/
void generator(int ilosc_k, int ilosc_w) {
	
	FILE* fCsvW;
	fCsvW = fopen("stats.csv", "w");

	if (!fCsvW) {
		printf("Blad zapisu!\n");
		exit(1);
	}

	fprintf(fCsvW, "%cmax%c, %cmin%c, %cavg%c, %cmed%c\n", '"', '"', '"', '"', '"', '"', '"', '"');

	FILE* fCsv;
	fCsv = fopen("dane.csv", "r");

	if (!fCsv) {
		printf("Blad odczytu!\n");
		exit(1);
	}
	else {

		for (int x = 0; x < ilosc_w; x++) {

			int buf;
			char bufC;

			fscanf(fCsv, "%d", &buf);
			fscanf(fCsv, "%c", &bufC);

			element* pHead = NULL;
			pHead = (element*)malloc(sizeof(element));
			pHead->liczba = buf;
			pHead->pNext = NULL;

			for (int y = 1; y < ilosc_k; y++) {

				fscanf(fCsv, "%d", &buf);
				if(y != ilosc_k-1) fscanf(fCsv, "%c", &bufC);
				dodElem(&pHead, buf);
			}

			wypisz(pHead);
			printf("\n");

			fprintf(fCsvW, "%d, ", elMax(pHead));
			fprintf(fCsvW, "%d, ", pHead->liczba);
			fprintf(fCsvW, "%.2f, ", srednia(pHead));
			fprintf(fCsvW, "%.2f\n", mediana(pHead));

			usunListe(&pHead);
		}
	}

	fclose(fCsv);
	fclose(fCsvW);
}

int main(int argc, char* argv[]) {

	int ilosc_k, ilosc_w, zakres_d, zakres_g;

	if (!sprawdzArgumenty(argc, argv, &ilosc_k, &ilosc_w, &zakres_d, &zakres_g)) {

		pomoc();
	}

	else {

		srand((unsigned int)time(NULL));
		generuj(ilosc_k, ilosc_w, zakres_d, zakres_g);
		zapiszParamDat(ilosc_k, ilosc_w, zakres_d, zakres_g);
		zapiszParamJson(ilosc_k, ilosc_w, zakres_d, zakres_g);
		generator(ilosc_k, ilosc_w);
	}
}
