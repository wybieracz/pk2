/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

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

int main(int argc, char* argv[]) {

	int ilosc_k, ilosc_w, zakres_d, zakres_g;

	if (!sprawdzArgumenty(argc, argv, &ilosc_k, &ilosc_w, &zakres_d, &zakres_g)) {

		pomoc();
	}

	else {

		srand((unsigned int)time(NULL));
		
		FILE* fp;
		fp = fopen("dane.csv", "w");

		if (!fp) {
			printf("B³¹d zapisu!\n");
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


		FILE* fb;
		fb = fopen("propertis.dat", "wb");

		if (!fb) {
			printf("B³¹d zapisu!\n");
			exit(1);
		}

		fprintf(fp, "%d ", ilosc_k);
		fprintf(fp, "%d ", ilosc_w);
		fprintf(fp, "%d ", zakres_d);
		fprintf(fp, "%d ", zakres_g);

		fclose(fb);
	}
}
