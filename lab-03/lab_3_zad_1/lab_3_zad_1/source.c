/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

void print_num(int* number) {
	
	//funkcja asset(bool) sprawdza wartoœæ wyra¿enia; je¿eli jest fa³szywe wypisuje komunikat diagnostyczny i przerywa dzia³anie aplikacji.
	assert(number);
	printf("%d\n", *number);
}

int main()
{
	char str[] = "Kappa Pride";
	
	//funkcja memset(wskaŸnik, wartoœæ, iloœæ bitów) ustawia n pierwszych bloków paiêci na zadan¹ wartoœæ;
	memset(str, '-', 5);
	//funkcja puts(wskaŸnik) wypisuje ³añcuch i przechodzi do nowej linii;
	puts(str);

	char str2[20];
	//funkcja memcpy(wskaŸnik na cel, wskaŸnik na Ÿród³o, liczba bitów; np. sizeof(struct) je¿eli kopiujemy ca³¹ strukturê) kopiuje zadan¹ iloœæ bitów do nowej lokalizacji;
	memcpy(str2, str+6, strlen(str+6) + 1);
	//funkcja fputs(wskaŸnik na Ÿród³o, wyjœcie) wpisuje ³añcuch do pliku wskazywanego; nie dodaje \n na koñcu;
	fputs(str2, stdout);

	//Funkcja memmove(wsk na cel, wsk. na Ÿród³o, ioœæ bitów) kopiuje n bajtów ze Ÿród³a do obiektu docelowego. Ró¿ni siê od memcpy tym, ¿e obszar obiektów source oraz dest mog¹ siê czêœciowo pokrywaæ.
	memmove(str, str + 6, 5);

	char buffor [50];
	int n;
	//funkcja sprintf(wsk. na cel, tekst+znaki jak w printf) zapisuje tekst do podanej w arg. tablicy znaków
	n=sprintf(buffor, "Kappa %d Pride Emoticon", 2);
	printf("\n[%s] is a string %d chars long\n", buffor, n);

	//funkcja isdigit(char) zwraca wartoœæ ró¿n¹ od zera gdy argument, który zosta³ przekazany do funkcji jest cyfr¹. W przeciwnym wypadku funkcja zwraca wartoœæ zero.

	if (isdigit(buffor[6])) {
		int a = 1;
		int* b = &a;
		int* c = NULL;

		print_num(b);
		//print_num(c);
	}
	
	//funkcja system(funcja) wywo³uje polecenie systemowe
	printf("Interpreter polecen:");
	if (system(NULL)) puts("OK\n");
	else exit(1);

	printf("Wywolywanie polecenia dir: \n");
	int res = system("dir");
	printf("Funkcja zwrocila wartosc: %d.\n", res);

	//funkcja strchr(wsk. na ci¹g przeszukiwany, char) zwraca wskaŸnik do pierwszego wyst¹pienia znaku c w ³añcuchu znaków s
	//funkcja strstr(wsk. na ci¹g przeszukiwany, wsk. na ci¹g szukany) szuka pierwszego wyst¹pienia ³añcucha znakowego str2 w ³añcuchu str1

	char str3[] = "Terranie, Protosi i Zergi";
	char* przecinek = strchr(str3, ',');
	char* rasa = strstr(str3, "Protosi");

	printf("\nZnaleziono:'%c'", *przecinek);
	printf("\nZnaleziono: %s\n", rasa);

	//funkcja strdup(wsk. na Ÿród³o) zwraca utworzon¹ kopiê ³añcucha znaków przekazanego poprzez argument funkcji w przypadku sukcesu. Funkcja zwraca wartoœæ NULL w przypadku niepowodzenia.
	char* rasy = strdup(str3);
	puts(rasy);

	return 0;
}