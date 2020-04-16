/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

void print_num(int* number) {
	
	//funkcja asset(bool) sprawdza warto�� wyra�enia; je�eli jest fa�szywe wypisuje komunikat diagnostyczny i przerywa dzia�anie aplikacji.
	assert(number);
	printf("%d\n", *number);
}

int main()
{
	char str[] = "Kappa Pride";
	
	//funkcja memset(wska�nik, warto��, ilo�� bit�w) ustawia n pierwszych blok�w pai�ci na zadan� warto��;
	memset(str, '-', 5);
	//funkcja puts(wska�nik) wypisuje �a�cuch i przechodzi do nowej linii;
	puts(str);

	char str2[20];
	//funkcja memcpy(wska�nik na cel, wska�nik na �r�d�o, liczba bit�w; np. sizeof(struct) je�eli kopiujemy ca�� struktur�) kopiuje zadan� ilo�� bit�w do nowej lokalizacji;
	memcpy(str2, str+6, strlen(str+6) + 1);
	//funkcja fputs(wska�nik na �r�d�o, wyj�cie) wpisuje �a�cuch do pliku wskazywanego; nie dodaje \n na ko�cu;
	fputs(str2, stdout);

	//Funkcja memmove(wsk na cel, wsk. na �r�d�o, io�� bit�w) kopiuje n bajt�w ze �r�d�a do obiektu docelowego. R�ni si� od memcpy tym, �e obszar obiekt�w source oraz dest mog� si� cz�ciowo pokrywa�.
	memmove(str, str + 6, 5);

	char buffor [50];
	int n;
	//funkcja sprintf(wsk. na cel, tekst+znaki jak w printf) zapisuje tekst do podanej w arg. tablicy znak�w
	n=sprintf(buffor, "Kappa %d Pride Emoticon", 2);
	printf("\n[%s] is a string %d chars long\n", buffor, n);

	//funkcja isdigit(char) zwraca warto�� r�n� od zera gdy argument, kt�ry zosta� przekazany do funkcji jest cyfr�. W przeciwnym wypadku funkcja zwraca warto�� zero.

	if (isdigit(buffor[6])) {
		int a = 1;
		int* b = &a;
		int* c = NULL;

		print_num(b);
		//print_num(c);
	}
	
	//funkcja system(funcja) wywo�uje polecenie systemowe
	printf("Interpreter polecen:");
	if (system(NULL)) puts("OK\n");
	else exit(1);

	printf("Wywolywanie polecenia dir: \n");
	int res = system("dir");
	printf("Funkcja zwrocila wartosc: %d.\n", res);

	//funkcja strchr(wsk. na ci�g przeszukiwany, char) zwraca wska�nik do pierwszego wyst�pienia znaku c w �a�cuchu znak�w s
	//funkcja strstr(wsk. na ci�g przeszukiwany, wsk. na ci�g szukany) szuka pierwszego wyst�pienia �a�cucha znakowego str2 w �a�cuchu str1

	char str3[] = "Terranie, Protosi i Zergi";
	char* przecinek = strchr(str3, ',');
	char* rasa = strstr(str3, "Protosi");

	printf("\nZnaleziono:'%c'", *przecinek);
	printf("\nZnaleziono: %s\n", rasa);

	//funkcja strdup(wsk. na �r�d�o) zwraca utworzon� kopi� �a�cucha znak�w przekazanego poprzez argument funkcji w przypadku sukcesu. Funkcja zwraca warto�� NULL w przypadku niepowodzenia.
	char* rasy = strdup(str3);
	puts(rasy);

	return 0;
}