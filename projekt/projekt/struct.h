#pragma once

/*@author Michal Pawlowski*/
/*@file struct.h*/

#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT
#define STRUCT

/** Deklaracja elementu listy podwieszanej
@author Michal Pawlowski
@date 2020-07-02
*/
typedef struct element {

	/** wskaznik na nastepny wezel w liscie (strona o tej samej wadze) */
	struct element* pNext;
	/** wskaznik na nastepny wezel w liscie odchodzacej (podstrona) */
	struct element* subPage;
	/** tytul strony */
	char* title;
	/** nazwa pliku strony */
	char* link;

}element;

#endif