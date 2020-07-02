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
	long long lSize;
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

void addSubPages(element** pHead, char* buffer, element* pParent) {

	char* begin = buffer;
	char* end = NULL;

	while (begin) {

		begin = strstr(begin, "<a href=\"");
		if (begin) end = strstr(begin, "\">");

		if (begin && end && !pParent) {

			addElement(&(*pHead)->subPage, begin + 9, end);
		}
		else if (begin && end && pParent && !linkcmp(pParent->link, begin + 9, strlen(pParent->link))) {

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

void generete(element** pHead, element* pParent) {

	if (*pHead) {

		char* buffer = NULL;

		openFile(&buffer, (*pHead)->link);

		if (buffer) {

			addTitle(&(*pHead), buffer);
			addSubPages(&(*pHead), buffer, pParent);
			free(buffer);
		}
		else {
			exit(1);
		}

		if((*pHead)->subPage) generete(&(*pHead)->subPage, *pHead);
		if((*pHead)->pNext) generete(&(*pHead)->pNext, pParent);
	}
}

char* makeOutName(char* name, char* ext) {

	char* output = (char*)malloc(strlen(name) + strlen(ext) + 2);

	strcpy(output, name);
	output[strlen(name)] = '.';
	strcpy(output + strlen(name) + 1, ext);
	output[strlen(name) + strlen(ext) + 1] = '\0';

	return output;
}

void printMap(element* pHead, int cut) {

	if (pHead) {

		for (int i = 0; i < cut; i++) printf("\t");

		if ((pHead)->title) printf("> %s\n", (pHead)->title);
		else printf("> <unknown title>\n");

		printf("\n");
		printMap((pHead)->subPage, cut + 1);
		printMap((pHead)->pNext, cut);
	}
}

void printTxt(element* pHead, int cut, FILE* pFile) {

	if (pHead) {

		for (int i = 0; i < cut; i++) fprintf(pFile, "\t");

		if ((pHead)->title) fprintf(pFile, "> %s\n", (pHead)->title);
		else fprintf(pFile, "> <unknown title>\n");

		fprintf(pFile, "\n");
		printTxt((pHead)->subPage, cut + 1, pFile);
		printTxt((pHead)->pNext, cut, pFile);
	}
}

void printHtml(element* pHead, int cut, FILE* pFile) {

	if (pHead) {

		if ((pHead)->title) fprintf(pFile, "<span style=\"margin-left:%dem\">> <a href=\"%s\">%s</a></span><br>\n", cut*2, (pHead)->link, (pHead)->title);
		else fprintf(pFile, "<span style=\"margin-left:%dem\"> ><a href=\"%s\">Unknown title</a></span><br>\n", cut*2, (pHead)->link);

		printHtml((pHead)->subPage, cut + 1, pFile);
		printHtml((pHead)->pNext, cut, pFile);
	}
}

void saveMap(element* pHead, char* name, char* ext) {

	if (pHead) {

		if (strcmp(ext, "txt") == 0 || strcmp(ext, "html") == 0) {

			FILE* pFile;
			char* output = makeOutName(name, ext);
			pFile = fopen(output, "w");

			if (strcmp(ext, "txt") == 0) printTxt(pHead, 0, pFile);

			if (strcmp(ext, "html") == 0) {

				fprintf(pFile, "<html>\n<head>\n<title>Website Map</title>\n</head>\n<body>\n");
				printHtml(pHead, 0, pFile);
				fprintf(pFile, "</body>\n</html>");
			}

			fclose(pFile);
			free(output);
		}
		else {
			fputs("WARNING: Saving file error! Unknown extension!\n", stderr);
		}
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