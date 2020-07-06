/*@author Michal Pawlowski*/
/*Progrma nale¿y wywo³ywaæ z 2 parametrami -i nazwaPlikuWejœciwego -c standardowyZnak£añcucha */

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/** Funkcja sprawdza parametry wejsciowe oraz wczytuje z nich dane do zmiennych
@author Michal Pawlowski
@date 2020-07-05
@param argc ilosc wczytanych parametrow
@param argv tablica wczytanych parametrow
@param input plik wesciowy
@param narmalChar znak najczêœciej wystêpuj¹cy w ci¹gu
@return prawde jezeli wczytano prawid³owo parametry
*/
bool paramsCheck(int argc, char* argv[], char** input, char* normalChar) {

	char* in = "-i";
	char* nChar = "-c";
	int count = 0;

	if (argc == 5) {

		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], in)) {

				*input = argv[i + 1];
				count++;
			}

			if (!strcmp(argv[i], nChar)) {

				*normalChar = *argv[i + 1];
				count++;
			}
		}

		if (count == 2) return true;

		else return false;
	}

	else return false;
}

/** Funkcja wypiuje pomoc
@author Michal Pawlowski
@date 2020-07-05
*/
void help() {

	printf("-------------------- H E L P --------------------\n");
	printf("Program must be started with 2 parameters:\n");
	printf("-i input file\n");
	printf("-c standard char in array\n");
	printf("-------------------------------------------------\n");
}



int main(int argc, char* argv[]) {
	{

		char* input = NULL;
		char normalChar;

		if (!paramsCheck(argc, argv, &input, &normalChar)) {

			help();
		}

		else {

			FILE* file = fopen(input, "r");
			if (file) {

				char sign;
				int count = 0, last = -1;
				bool isTitleDisplayed = false;

				while ((sign = getc(file)) != EOF) {

					if (sign == normalChar) count++;
					else {

						if (!isTitleDisplayed) {

							fprintf(stdout, "Found spacial chars in array of %c:\n\n", normalChar);
							isTitleDisplayed = true;
						}

						if (last < 0) {

							fprintf(stdout, "-\"%c\" -> on position: %d\n", sign, count);
							last = count;
							count++;
						}
						else {

							fprintf(stdout, "-\"%c\" -> on position: %d -> from last special char: +%d\n", sign, count, count - last);
							last = count;
							count++;
						}
					}
				}

				fclose(file);

				if (!isTitleDisplayed) fprintf(stdout, "Special chars not found in array!");
			}

		}

		_CrtDumpMemoryLeaks();
		return 0;
	}
}