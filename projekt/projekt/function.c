#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "struct.h"
#include "header.h"

#ifndef FUNCTION
#define FUNCTION

bool paramsCheck(int argc, char* argv[], char** input, char** output, char** ext) {

	char* in = "-i";
	char* out = "-o";
	char* e = "-e";
	int count = 0;

	if (argc == 7) {

		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], in)) {

				*input = argv[i + 1];
				count++;
			}

			if (!strcmp(argv[i], out)) {

				*output = argv[i + 1];
				count++;
			}

			if (!strcmp(argv[i], e)) {

				*ext = argv[i + 1];
				count++;
			}
		}

		if (count == 3) return true;

		else return false;
	}

	else return false;
}

void help() {

	printf("-------------------- H E L P --------------------\n");
	printf("Program must be started with 3 parameters:\n");
	printf("-i input file\n");
	printf("-o output file name\n");
	printf("-e output file extension (.txt or .html)\n");
	printf("-------------------------------------------------\n");
}

void openFile(char** buffer, char* input) {

	FILE* pFile;
	long lSize;
	size_t result;

	pFile = fopen(input, "rb");
	if (pFile == NULL) { fputs("WARNING: File error!", stderr); exit(1); }

	fseek(pFile, 0, SEEK_END);
	lSize = ftell(pFile);
	rewind(pFile);

	*buffer = (char*)malloc(sizeof(char) * lSize);
	if (*buffer == NULL) { fputs("WARNING: Memory error!", stderr); exit(2); }

	result = fread(*buffer, 1, lSize, pFile);
	if (result != lSize) { fputs("WARNING: Reading error!", stderr); exit(3); }

	fclose(pFile);
}

bool linkcmp(char* parent, char* link, int bytes) {

	if (parent && link) {

		if (memcmp(parent, link, bytes) != 0) return false;
		else return true;
	}
	else {

		return false;
	}
}

void addTitle(element** pHead, char* buffer) {
	
	if (*pHead) {

		char* begin = NULL;
		char* end = NULL;

		begin = strstr(buffer, "<title>");
		end = strstr(buffer, "</title>");

		if (begin && end) {

			int byte = end - (begin + 7);
			(*pHead)->title = (char*)malloc(byte + 1);
			memcpy((*pHead)->title, begin + 7, byte);
			(*pHead)->title[byte] = '\0';
		}
		else {

			(*pHead)->title = (char*)malloc(16);
			strcpy((*pHead)->title, "<Title unknown>");
		}
	}
}

void addElement(element** pHead, char* begin, char* end) {

	if (*pHead) {

		if ((*pHead)->pNext) {
			addElement(&(*pHead)->pNext, begin, end);
		}
		else {

			(*pHead)->pNext = (element*)malloc(sizeof(element));
			(*pHead)->pNext->pNext = NULL;
			(*pHead)->pNext->subPage = NULL;
			(*pHead)->pNext->title = NULL;
			(*pHead)->pNext->link = NULL;

			int byte = end - begin;
			(*pHead)->pNext->link = (char*)malloc(byte + 1);
			memcpy((*pHead)->pNext->link, begin, byte);
			(*pHead)->pNext->link[byte] = '\0';
		}
	}
	else {

		*pHead = (element*)malloc(sizeof(element));
		(*pHead)->pNext = NULL;
		(*pHead)->subPage = NULL;
		(*pHead)->title = NULL;
		(*pHead)->link = NULL;

		int byte = end - begin;
		(*pHead)->link = (char*)malloc(byte + 1);
		memcpy((*pHead)->link, begin, byte);
		(*pHead)->link[byte] = '\0';
	}
}

void addSubPages(element** pHead, char* buffer, char* parent) {

	char* begin = buffer;
	char* end = NULL;

	while (begin) {

		begin = strstr(begin, "<a href=\"");
		if (begin) end = strstr(begin, "\">");

		if (begin && end && !linkcmp(parent, begin + 9, strlen(parent))) {

			addElement(&(*pHead)->subPage, begin + 9, end);
		}

		if(begin) begin = end + 2;
	}
}

void createFirst(element** pHead, char* input) {

	*pHead = (element*)malloc(sizeof(element));
	(*pHead)->pNext = NULL;
	(*pHead)->subPage = NULL;
	(*pHead)->title = NULL;
	(*pHead)->link = (char*)malloc(strlen(input) + 1);
	memcpy((*pHead)->link, input, strlen(input) + 1);
}

void generete(element** pHead, char* input) {

	if (*pHead) {

		char* buffer = NULL;

		openFile(&buffer, input);

		if (buffer) {

			addTitle(&(*pHead), buffer);
			addSubPages(&(*pHead), buffer, (*pHead)->link);
			free(buffer);
		}
		else {
			exit(1);
		}

		if((*pHead)->subPage) generete((*pHead)->subPage, (*pHead)->subPage->link);
		if((*pHead)->pNext) generete((*pHead)->pNext, (*pHead)->pNext->link);
	}
}

void printMap(element* pHead, int cut) {

	if (pHead) {

		for (int i = 0; i < cut; i++) printf("\t");
		if ((pHead)->title) printf("%s\n", (pHead)->title);
		else printf("<unknown title>\n");
		//if ((pHead)->link) printf("%s\n", (pHead)->link);
		//else printf("<unknown link>\n");

		printMap((pHead)->pNext, cut);
		printMap((pHead)->subPage, cut + 1);
	}
}

void deleteList(element** pHead) {

	if (*pHead) {

		deleteList(&(*pHead)->pNext);
		deleteList(&(*pHead)->subPage);

		free((*pHead)->title);
		free((*pHead)->link);
		free(*pHead);
		*pHead = NULL;
	}
}
#endif