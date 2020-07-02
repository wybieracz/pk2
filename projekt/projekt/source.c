/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"
#include "struct.h"

int main(int argc, char* argv[]) {
	{

		char* input = NULL;
		char* output = NULL;
		char* ext = NULL;

		if (!paramsCheck(argc, argv, &input, &output, &ext)) {

			help();
		}

		else {

			element* pHead = NULL;

			createFirst(&pHead, input);
			generete(&pHead, NULL);
			printMap(pHead, 0);
			saveMap(pHead, output, ext);
			deleteList(&pHead);
		}

		_CrtDumpMemoryLeaks();
		return 0;
	}
}