/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[]) {

	int nr;

	printf("FizzBuzz v1.0\n");
	printf("Do ilu gramy? : ");
	scanf("%d", &nr);

	FILE* out;
	out = fopen("FizzBuzz.txt", "w");

	if (out) {

		for (unsigned int i = 1; i <= nr; i++) {
			if (i % 15 == 0) {
				printf("FizzBuzz\n");
				fprintf(out, "FizzBuzz\n");
			}
			else if (i % 3 == 0) {
				printf("Fizz\n");
				fprintf(out, "Fizz\n");
			}
			else if (i % 5 == 0) {
				printf("Buzz\n");
				fprintf(out, "Buzz\n");
			}
			else {
				printf("%u\n", i);
				fprintf(out, "%d\n", i);
			}
		}

		fclose(out);
	}

	else {

		FILE* error;
		error = fopen("errors.txt", "w");

		fprintf(error, "Warning: Coudn't create output file");
		fprintf(stderr, "Warning: Coudn't create output file");

		fclose(error);
	}
	return 0;

}