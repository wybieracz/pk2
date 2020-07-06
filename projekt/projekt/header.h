#pragma once

/*@author Michal Pawlowski*/
/*@file header.h*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"struct.h"

#ifndef HEADER
#define HEADER

/** Funkcja kopiuje dane z tablicy parametrow do zmiennych
@author Michal Pawlowski
@date 2020-07-02
@param argv tablica wczytanych parametrow
@param param aktualnie kopiowany parametr
@param count licznik kopiowanych parametrow
@param i licznik petli
*/
void paramCpy(char* argv[], char** param, int* count, int* i);

/** Funkcja sprawdza parametry wejsciowe oraz wczytuje z nich dane do zmiennych
@author Michal Pawlowski
@date 2020-07-02
@param argc ilosc wczytanych parametrow
@param argv tablica wczytanych parametrow
@param input plik wesciowy
@param output nazwa pliku wyjsciowego
@param ext rozszerzenie pliku wyjsciowego
@return prawde jezeli wczytano prawid≥owo parametry
*/
bool paramsCheck(int argc, char* argv[], char** input, char** output, char** ext);

/** Funkcja wypiuje pomoc
@author Michal Pawlowski
@date 2020-07-02
*/
void help();

/** Funkcja kopiuje zawartosc pliku do bufora
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] buffer wskaznik na bufor
@param wskaznik na nazwe pliku
*/
void openFile(char** buffer, char* input);

/** Funkcja sprawdza czy nazwy podane w argumentach sa takie same
@author Michal Pawlowski
@date 2020-07-02
@param parent link strony rodzica
@param link znaleziony link
@param bytes liczba bitow do sprawdzenia
@return prawde jezeli link jest strona rodzicem (nazwy sa takie same)
*/
bool linkcmp(char* parent, char* link, int bytes);

/** Funkcja dodaje znaleziony tytul do przetwarzanego elementu
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] pHead wskaznik na element listy
@param begin wskaxnik na poczatek tytulu
@param end wskaznik na koniec tytulu
*/
void addFoundTitle(element** pHead, char* begin, char* end);

/** Funkcja dodaje podpis o nieznanym tytule danej strony do przetwarzanego elementu
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] pHead wskaznik na element listy
*/
void addUnknownTitle(element** pHead);

/** Funkcja znajduje i dodaje tytul do aktualnie przetwarzanego elementu
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] pHead wskaznik na element listy
@param buffer wskaznik na bufor
*/
void addTitle(element** pHead, char* buffer);

/** Funkcja dodaje nazwe plku do aktualnie przetwarzanego elementu
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] pHead wskaznik na element listy
@param begin wskaznik na poczatek nazwy
@param end wskaxnik na koniec nazwy
@see addElement() funkcja nadrzedna
*/
void addLinkToElement(element** pHead, char* begin, char* end);

/** Funkcja alokuje nowy pusty element listy
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] pHead wskaznik na ktorym zostanie utworzony nowy element
@see addElement() funkcja nadrzedna
*/
void addNullElement(element** pHead);

/** Funkcja dodaje nowy element do listy
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] wskaznik na glowe listy
@param begin wskaznik na poczatek linku strony dodawanej
param end wskaznik na koniec linku strony dodawanej
@see generate() funkcja nadrzedna
*/
void addElement(element** pHead, char* begin, char* end);

/** Funkcja wyszukuje i dodaje podstrony do struktury
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] wskaznik na glowe listy
@param buffer wskaznik na bufor z zawartoscia z pliku
param parent wskaznik na strone rodzica
@see generate() funkcja nadrzedna
*/
void addSubPages(element** pHead, char* buffer, element* pParent);

/** Funkcja tworzy pierwszy element struktury
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] wskaznik na glowe listy
@param input wskaznik na nazwe pliku strony glownej
*/
void createFirst(element** pHead, char* input);

/** Funkcja tworzy mape witryny oparta o liste podwieszana
@author Michal Pawlowski
@date 2020-07-02
@param [in,out] wskaznik na zaalokowana glowe listy
@param pParent wskaznik na strone rodzica
@see addTitle() funkcja dodajaca tytul
@see addSubPages() funkcja dodajaca do struktury podstrony
*/
void generete(element** pHead, element* pParent);

/** Funkcja generuje pelna nazwe pliku wyjsciowego
@author Michal Pawlowski
@date 2020-07-02
@param name nazwa wysjciowa
@param ext rozszerzenie wyjsciowe
@return wskaznik na pelna nazwe pliku wyjsciowego
*/
char* makeOutName(char* name, char* ext);

/** Funkcja wypisuje na konsoli cala strukture
@author Michal Pawlowski
@date 2020-07-02
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
*/
void printMap(element* pHead, int cut);

/** Funkcja wypisuje do pliku txt cala strukture
@author Michal Pawlowski
@date 2020-07-02
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
@param pFile strumien wyjscia
@see saveMap() funkcja nadrzedna
*/
void printTxt(element* pHead, int cut, FILE* pFile);

/** Funkcja wypisuje do pliku html cala strukture
@author Michal Pawlowski
@date 2020-07-02
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
@param pFile strumien wyjscia
@see saveMap() funkcja nadrzedna
*/
void printHtml(element* pHead, int cut, FILE* pFile);

/** Funkcja zapisuje cala strukture do pliku z wybranym rozszerzeniem
@author Michal Pawlowski
@date 2020-07-02
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
@param name nazwa wyjsciowa pliku
@param ext rozszerzenie pliku
@see printTxt funkcja zapisujaca do pliku txt
@see printHtml funkcja zapisujaca do pliku html
*/
void saveMap(element* pHead, char* name, char* ext);

/** Funkcja usuwa cala strukture danych - liste podwieszana
@date 2020-07-02
@param [in,out] pHead wskaünik na poczπtek lsty
*/
void deleteList(element** pHead);
#endif