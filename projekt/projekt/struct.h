#pragma once
#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT
#define STRUCT

typedef struct element {

	struct element* pNext;
	struct element* subPage;
	char* title;
	char* link;

}element;

#endif