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
@return prawde jezeli wczytano prawid≥owo parametry
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

/** Funkcja dodaje tytul do aktualnie przetwarzanego elementu
@author Michal Pawlowski
@date 2020-05-01
@param [in,out] pHead wskaznik na element listy
@param buffer wskaznik na bufor
*/
void addTitle(element** pHead, char* buffer);

/** Funkcja tworzy mape witryny oparta na liscie podwieszanej
@author Michal Pawlowski
@date 2020-05-01
@param input wskaznik na nazwe pliku strony glownej
@param [in,out] wskaznik na glowe listy
*/
void generete(char* input, element** pHead);

/** Funkcja usuwa cala strukture danych - liste podwieszana
@date 2020-04-02
@param [in,out] pHead wskaünik na poczπtek lsty
*/
void deleteList(element** pHead);
#endif