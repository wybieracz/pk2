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

	pFile = fopen("index.html", "rb");
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

void addTitle(element** pHead, char* buffer) {
	
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

void generete(char* input, element** pHead) {

	char* buffer = NULL;

	openFile(&buffer, input);

	if (buffer) {
		
		*pHead = (element*)malloc(sizeof(element));
		(*pHead)->pNext = NULL;
		(*pHead)->subPage = NULL;
		(*pHead)->title= NULL;
		(*pHead)->link = NULL;

		addTitle(pHead, buffer);

		printf("%s\n", (*pHead)->title);

		free(buffer);
	}
	else {
		exit(1);
	}
}

void deleteList(element** pHead) {

	if (*pHead) {

		deleteList(&(*pHead)->pNext);

		if ((*pHead)->subPage) {

			deleteList(&(*pHead)->subPage);

			free((*pHead)->title);
			free((*pHead)->link);
			free(*pHead);
			*pHead = NULL;
		}

		free((*pHead)->title);
		free((*pHead)->link);
		free(*pHead);
		*pHead = NULL;

	}
}
#endif