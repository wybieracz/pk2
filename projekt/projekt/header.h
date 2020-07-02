#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"struct.h"

#ifndef HEADER
#define HEADER

/** Funkcja sprawdza parametry wejsciowe oraz wczytuje z nich dane do zmiennych
@author Michal Pawlowski
@date 2020-05-01
@param argc ilosc wczytanych parametrow
@param argv tablica wczytanych parametrow
@param input plik wesciowy
@param output nazwa pliku wyjsciowego
@param ext rozszerzenie pliku wyjsciowego
@return prawde jezeli wczytano prawid�owo parametry
*/
bool paramsCheck(int argc, char* argv[], char** input, char** output, char** ext);

/** Funkcja wypiuje pomoc
@date 2020-04-15
*/
void help();

/** Funkcja kopiuje zawartosc pliku do bufora
@author Michal Pawlowski
@date 2020-05-01
@param [in,out] buffer wskaznik na bufor
@param wskaznik na nazwe pliku
*/
void openFile(char** buffer, char* input);

/** Funkcja sprawdza czy dany link nie jest strona rodzicem
@author Michal Pawlowski
@date 2020-05-01
@param parent link strony rodzica
@param link znaleziony link
@param bytes liczba bitow do sprawdzenia
@return prawde jezeli link jest strona rodzicem
*/
bool linkcmp(char* parent, char* link, int bytes);

/** Funkcja dodaje tytul do aktualnie przetwarzanego elementu
@author Michal Pawlowski
@date 2020-05-01
@param [in,out] pHead wskaznik na element listy
@param buffer wskaznik na bufor
*/
void addTitle(element** pHead, char* buffer);

/** Funkcja dodaje nowy element do listy
@author Michal Pawlowski
@date 2020-05-01
@param [in,out] wskaznik na glowe listy
@param begin wskaznik na poczatek linku strony dodawanej
param end wskaznik na koniec linku trony dodawanej
*/
void addElement(element** pHead, char* begin, char* end);

/** Funkcja wyszukuje i dodaje podstrony do struktury
@author Michal Pawlowski
@date 2020-05-01
@param [in,out] wskaznik na glowe listy
@param buffer wskaznik na bufor z zawartoscia z pliku
param parent wskaznik na strone rodzica
*/
void addSubPages(element** pHead, char* buffer, element* pParent);

/** Funkcja tworzy pierwszy element struktury
@author Michal Pawlowski
@date 2020-05-01
@param input wskaznik na nazwe pliku strony glownej
@param [in,out] wskaznik na glowe listy
*/
void createFirst(element** pHead, char* input);

/** Funkcja tworzy mape witryny oparta na liscie podwieszanej
@author Michal Pawlowski
@date 2020-05-01
@param [in,out] wskaznik na zaalokowana glowe listy
@param pParent wskaznik na strone rodzica
*/
void generete(element** pHead, element* pParent);

/** Funkcja generuje pelna nazwe pliku wyjsciowego
@author Michal Pawlowski
@date 2020-05-01
@param name nazwa wysjciowa
@param ext rozszerzenie wyjsciowe
*/
char* makeOutName(char* name, char* ext);

/** Funkcja wypisuje na konsoli cala strukture
@author Michal Pawlowski
@date 2020-05-01
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
*/
void printMap(element* pHead, int cut);

/** Funkcja wypisuje do pliku txt cala strukture
@author Michal Pawlowski
@date 2020-05-01
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
@param pFile strumien wyjscia
*/
void printTxt(element* pHead, int cut, FILE* pFile);

/** Funkcja wypisuje do pliku html cala strukture
@author Michal Pawlowski
@date 2020-05-01
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
@param pFile strumien wyjscia
*/
void printHtml(element* pHead, int cut, FILE* pFile);

/** Funkcja zapisuje cala strukture do pliku z wybranym rozszerzeniem
@author Michal Pawlowski
@date 2020-05-01
@param pHead wskaznik na glowe struktury
@param cut wciecie dla podstron
@param name nazwa wyjsciowa pliku
@param ext rozszerzenie pliku
*/
void saveMap(element* pHead, char* name, char* ext);

/** Funkcja usuwa cala strukture danych - liste podwieszana
@date 2020-04-02
@param [in,out] pHead wska�nik na pocz�tek lsty
*/
void deleteList(element** pHead);
#endif