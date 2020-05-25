/*@author Michal Pawlowski*/

#define _CRT_SECURE_NO_WARNINGS
#define BUF_SIZE 100
#define OPEN_KEY '1'
#define STOP_KEY '2'
#define CLOSE_KEY '3'
#define EXIT_KEY '4'

#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum machineState {

	open,
	opening,
	stop,
	closing,
	close

}machineState;

typedef struct circularBuffer {

	char tab[BUF_SIZE];
	int writeIndex;
	int readIndex;
	int bufferLength;

}circularBuffer;

typedef struct gateMachine {

	machineState gateCase;
	int percent;

}gateMachine;

/** Funkcja tworzy bufor cykilczny
@date 2020-05-15
@return wskaznik na bufor cykilczny
*/
circularBuffer createCircularBuffer() {

	circularBuffer buffer;
	buffer.writeIndex = 0;
	buffer.readIndex = 0;
	buffer.bufferLength = 0;

	return buffer;
}

/** Funkcja dodaje element do bufora cyklicznego
@date 2020-05-15
@param buffer wskaznik na bufor
@param input dane wejsciowe
*/
void addToCircularBuffer(circularBuffer* buffer, char input) {

	if (input == OPEN_KEY || input == STOP_KEY || input == CLOSE_KEY || input == EXIT_KEY) {

		if (buffer->bufferLength == BUF_SIZE) {

			printf("ERROR: Buffer overflow!\n");
			return;
		}
		else {

			buffer->tab[buffer->writeIndex] = input;
			buffer->bufferLength++;
			buffer->writeIndex++;
			if (buffer->writeIndex == BUF_SIZE) buffer->writeIndex = 0;
		}
	}
}

/** Funkcja odczytuje wartosc z bufora oraz niszczy ja
@date 2020-05-15
@param buffer wskaznik na bufor
*/
char readFromCircularBuffer(circularBuffer* buffer) {

	if (buffer->bufferLength > 0) {

		char temp = buffer->tab[buffer->readIndex];

		buffer->tab[buffer->readIndex] = '\0';
		buffer->bufferLength--;
		buffer->readIndex++;

		if (buffer->readIndex == BUF_SIZE) buffer->readIndex = 0;
		return temp;
	}
	else {

		return '\0';
	}
}

/** Funkcja obslugujaca maszyne stanow
@date 2020-05-15
@param buffer wskaznik na bufor
@param gate wskaznik na maszyne stanow
@param exitStatus zmienna okreslajaca czy zakonczyc program
*/
void caseServis(circularBuffer* buffer, gateMachine* gate, bool* exitStatus) {

	switch (readFromCircularBuffer(buffer)) {

	case OPEN_KEY:

		switch (gate->gateCase) {

		case open:
			break;

		case opening:
			gate->percent -= 10;
			if (gate->percent == 0) gate->gateCase = open;
			break;

		case stop:
		case closing:
		case close:
			gate->percent -= 10;
			gate->gateCase = opening;
			break;
		}
		break;

	case STOP_KEY:
		switch (gate->gateCase) {

		case open:
		case stop:
			break;

		case opening:
		case closing:
		case close:
			gate->gateCase = stop;
			break;
		}
		break;

	case CLOSE_KEY:

		switch (gate->gateCase) {

		case open:
		case opening:
		case stop:
			gate->percent += 10;
			gate->gateCase = closing;
			break;

		case closing:
			gate->percent += 10;
			if (gate->percent == 100) gate->gateCase = close;
			break;

		case close:
			break;
		}
		break;

	case EXIT_KEY:

		*exitStatus = true;
		break;

	default:

		switch (gate->gateCase) {

		case open:
		case close:
		case stop:
			break;

		case opening:

			gate->percent -= 10;
			if (gate->percent == 0) gate->gateCase = open;
			break;

		case closing:
			gate->percent += 10;
			if (gate->percent == 100) gate->gateCase = close;
			break;
		}
		break;
		break;
	}
}

/** Funkcja tworzy strukture odwzorowujaca stan maszyny stanow
@date 2020-05-15
@return wskaznik na strukture
*/
gateMachine createGate() {

	gateMachine tempGate;
	tempGate.gateCase = close;
	tempGate.percent = 100;

	return tempGate;
}

/** Funkcja dodaje element do bufora cyklicznego
@date 2020-05-15
@param strumien wyjsciowy
@param maszyna stanow
*/
void printState(FILE* outStream, gateMachine gate) {

	switch (gate.gateCase) {

	case open:
		fprintf(outStream, "Gate status: Open\n");
		printf("Gate status: Open\n");
		break;
	case opening:
	case closing:
		fprintf(outStream, "Gate status: Closed in %d%%\n", gate.percent);
		printf("Gate status: Closed in %d%%\n", gate.percent);
		break;
	case stop:
		fprintf(outStream, "Gate status: Closed in %d%% (Stopped)\n", gate.percent);
		printf("Gate status: Closed in %d%% (Stopped)\n", gate.percent);
		break;
	case close:
		fprintf(outStream, "Gate status: Closed\n");
		printf("Gate status: Closed\n");
		break;
	}
}

int main() {

	circularBuffer buffer = createCircularBuffer();
	gateMachine gate = createGate();
	bool exitStatus = false;
	char input;
	FILE* logFile = fopen("logfile.txt", "w");

	while (!exitStatus) {

		input = '\0';
		printState(logFile, gate);

		if (_kbhit())
			input = getchar();

		addToCircularBuffer(&buffer, input);
		caseServis(&buffer, &gate, &exitStatus);
		Sleep(1500);
	}

	fprintf(logFile, "INFO: Program Stopped!\n");
	printf("INFO: Program Stopped!\n");
	return 0;
}