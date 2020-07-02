#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


#define NICK "admin"
#define PASS "admin"
#define Q1 "admin"
#define GAME_KEY "W3HF8-NSKJ3-2KSNT"

using namespace std;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void print(string line) {

	int x = 0;
	while (line[x] != '\0') {
		cout << line[x];
		Sleep(1);
		x++;
	};
}

void printNewLine(string line) {

		int x = 0;
		while (line[x] != '\0') {
			cout << line[x];
			Sleep(1);
			x++;
		};
		cout << endl;
}

void printBar(int lenght) {

	char box = 219;
	int wait;

	for (int i = 0; i < lenght; i++) {

		wait = 10 + rand() % 250;
		printf("%c", box);
		Sleep(wait);
	}
}

void printStart() {

	string blume = "                                  `:oy+.                                   ";
	printNewLine(blume);
	blume = "                               ./ymMMMMNdo:`                               ";
	printNewLine(blume);
	blume = "                           `:odNMMMMMMMMMMNmy/.                            ";
	printNewLine(blume);
	blume = "                        -+hmMMMMMMMMMMMMMMMMMMNdo-`                        ";
	printNewLine(blume);
	blume = "                       .sdMMMMMMMMMMMMMMMMMMMMMMMh+                        ";
	printNewLine(blume);
	blume = "                 .:so `+-.-ohNMMMMMMMMMMMMMMMNh+-.-+` -/.                  ";
	printNewLine(blume);
	blume = "              .+ymMMy .MNds:../sdNMMMMMMMMmy/..:sdNM. oMmh+-`              ";
	printNewLine(blume);
	blume = "          `-odNMMMMMs .MMMMMmy+-.-+hmMNdo:.-+ymMMMMM. oMMMMNds:`           ";
	printNewLine(blume);
	blume = "          `-odNMMMMMs .MMMMMmy+-.-+hmMNdo:.-+ymMMMMM. oMMMMNds:`           ";
	printNewLine(blume);
	blume = "       .:sdNMMMMMMMMs .MMMMMMMMNdo:..:..:odNMMMMMMMM. oMMMMMMMMmy/.        ";
	printNewLine(blume);
	blume = "      -mMMMMMMMMMMMMs .MMMMMMMMMMMMm- -mMMMMMMMMMMMM. oMMMMMMMMMMMNd:      ";
	printNewLine(blume);
	blume = "      :MMMMMMMMMMMMMo .MMMMMMMMMMMMM: :MMMMMMMMMMMMM. oMMMMMMMMMMMMMs      ";
	printNewLine(blume);
	blume = "      :MMMMMMMMMMMMMo -MMMMMMMMMMMMM: :MMMMMMMMMMMMM- oMMMMMMMMMMMMMs      ";
	printNewLine(blume);
	blume = "      :MMMMMMMMMMMMMo -MMMMMMMMMMMMM: :MMMMMMMMMMMMM- oMMMMMMMMMMMMMy      ";
	printNewLine(blume);
	blume = "      :MMMMMMMMMMMmh- :MMMMMMMMMMMMM/ /MMMMMMMMMMMMM: -hmMMMMMMMMMMMy      ";
	printNewLine(blume);
	blume = "      :MMMMMMMNms/.`-odMMMMMMMMMMMMM/ /MMMMMMMMMMMMMdo-`./ymNMMMMMMMh      ";
	printNewLine(blume);
	blume = "      :MMMMNho-`./ymMMMMMMMMMMMMMMMM/ /MMMMMMMMMMMMMMMMmy/.`:odNMMMMh      ";
	printNewLine(blume);
	blume = "      :Nmy/.`.+hNMMMMMMMMMMMMMMMMMMM/ /MMMMMMMMMMMMMMMMMMMNh+.`-+hNMd      ";
	printNewLine(blume);
	blume = "      `:``-odNMMMMMMMMMMMMMMMMMMMMMM: :MMMMMMMMMMMMMMMMMMMMMMNdo-`./+      ";
	printNewLine(blume);
	blume = "        :dMMMMMMMMMMMMMMMMMMMMMMNmy/```/ymNMMMMMMMMMMMMMMMMMMMMMMd/        ";
	printNewLine(blume);
	blume = "      :/``:smNMMMMMMMMMMMMMMMNdo-``/sds/``-odNMMMMMMMMMMMMMMMNms:.`/o      ";
	printNewLine(blume);
	blume = "      oMNh+.`-odNMMMMMMMMMNy/. .+hNMMMMMNh+. ./yNMMMMMMMMMNdo-`.+hNMm      ";
	printNewLine(blume);
	blume = "      oMMMMMms:`./yNMMMds:``:sdMMMMMMMMMMMMMds:``:sdMMMNy/``:sdMMMMMd      ";
	printNewLine(blume);
	blume = "      oMMMMMMMMNh+. -/. `/yNMMMMMMMMMMMMMMMMMMMNy/` ./- `/yNMMMMMMMMd      ";
	printNewLine(blume);
	blume = "      oMMMMMMMMMMMMd. :dMMMMMMMMMMMMMMMMMMMMMMMMMMMd: -hNMMMMMMMMMMMd      ";
	printNewLine(blume);
	blume = "      oMMMMMMMMMMMMM- oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo /MMMMMMMMMMMMMh      ";
	printNewLine(blume);
	blume = "      oMMMMMMMMMMMMM: oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo /MMMMMMMMMMMMMh      ";
	printNewLine(blume);
	blume = "      oMMMMMMMMMMMMM: oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo /MMMMMMMMMMMMMh      ";
	printNewLine(blume);
	blume = "      /mMMMMMMMMMMMM/ oMMMMMMMMMMMmy/./ymMMMMMMMMMMMo /MMMMMMMMMMMNh/      ";
	printNewLine(blume);
	blume = "       `-odNMMMMMMMM/ oMMMMMMMNho-`./o/.`-ohNMMMMMMMo /MMMMMMMMmy/.        ";
	printNewLine(blume);
	blume = "          `.+hNMMMMM/ oMMMMmy/.`-+hNMMMNh+-`./ymMMMMo /MMMMNdo:`           ";
	printNewLine(blume);
	blume = "              `:smMM+ oNho-`./smNMMMMMMMMMNds:``-ohNo /Mmy+.`              ";
	printNewLine(blume);
	blume = "                 `-o: ..`-+hNMMMMMMMMMMMMMMMMMmy/.`.. .:`                  ";
	printNewLine(blume);
	blume = "                       -yNMMMMMMMMMMMMMMMMMMMMMMMh/                        ";
	printNewLine(blume);
	blume = "                        `-ohNMMMMMMMMMMMMMMMMNdo-`                         ";
	printNewLine(blume);
	blume = "                            ./ydMMMMMMMMMMmy/.`                            ";
	printNewLine(blume);
	blume = "                               `-ohmMMNds:.                                ";
	printNewLine(blume);
	blume = "                                   ./+-`                                   ";
	printNewLine(blume);

	cout << endl << endl << endl;

	blume = "     .-nnn`         .-            -.  .-         -.   `-`        dHHHH`    ";
	printNewLine(blume);
	blume = "     +M   d.        hm           .Mo  yN`        mN+`.hM/        dN        ";
	printNewLine(blume);
	blume = "     +MhydN-        hm           .Mo  yN`        mN hm M/        dNsss-    ";
	printNewLine(blume);
	blume = "     +M  /Ny        hm           .Ns  hN`        mh s+ M/        dN        ";
	printNewLine(blume);
	blume = "     /mdddh-        ymddd/        +hddh:         hy   -m:        ymddh/    ";
	printNewLine(blume);

	cout << endl << endl << "     ";
	printBar(66);
	Sleep(500);
	system("CLS");
}

void printPuzzle() {

	cout << "Kappa";
}

void sysCheck() {

#if defined WIN32 || defined _WIN32  || defined __WIN32__ || defined __NT__
	printf("Windows ");
#ifdef _WIN64
	printf("x64");
#else
	printf("x32");
#endif
#elif __APPLE__
	printf("iOS");
#elif __linux__
	printf("Linux");
#elif __unix__ 
	printf("Unix");
#elif defined(_POSIX_VERSION)
	printf("Unix");
#else
#   error "Unknown"
#endif   
}

void dateCheck() {

	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof str, &result);
	print(str);
	cout << '\b';
}

void softCheck() {

	dateCheck();
	Sleep(250);
	print("//System: ");
	sysCheck();
	printNewLine("//\n");
	Sleep(250);
	
	printNewLine("//Starting environment//");
	Sleep(250);
}

void login() {
	SetConsoleTextAttribute(hConsole, 15);

	string nick;
	string pass;
	string quest1;

	do {
		do {
			printNewLine("//Request username and password//");
			Sleep(250);
			cout << '\n' << '\n';
			print("-> Username: ");
			cin >> nick;
			print("-> Password: ");
			cin >> pass;

			if (nick != NICK) {
				SetConsoleTextAttribute(hConsole, 12);
				printNewLine("\n//Couldn't find that username//");
				Sleep(2000);
				system("CLS");
			}

			if (nick == NICK && pass != PASS) {
				SetConsoleTextAttribute(hConsole, 12);
				printNewLine("\n//Wrong password//");
				Sleep(2000);
				system("CLS");
			}
			SetConsoleTextAttribute(hConsole, 15);
		} while ((nick != NICK) || (pass != PASS));

		Sleep(500);
		printNewLine("\n//Verify your identity by security question//\n");
		print("-> Favourite song: ");
		cin >> quest1;
		transform(quest1.begin(), quest1.end(), quest1.begin(), ::tolower);

		if (quest1.compare(Q1)) {

			SetConsoleTextAttribute(hConsole, 12);
			print("\n//You've been kicked//");
			Sleep(2000);
			SetConsoleTextAttribute(hConsole, 15);
			system("CLS");
		}

	} while (quest1 !=Q1);
	
	SetConsoleTextAttribute(hConsole, 10);
	printNewLine("\nACCESS GRANTED!\n");
	SetConsoleTextAttribute(hConsole, 15);
	print("Connecting to blume-inc.weebly.com");
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "./\n\n\n" << endl;
	
}

void decodeChar(char finalChar) {

	SetConsoleTextAttribute(hConsole, 12);
	char tempChar;

	for (int j = 25 + rand() % 51; j > 0; j--) {
		tempChar = 33 + rand() % 93;
		cout << tempChar << '\b';
		Sleep(50);
	}

	SetConsoleTextAttribute(hConsole, 10);
	cout << finalChar;
	SetConsoleTextAttribute(hConsole, 15);
}

void decode() {

	string key = GAME_KEY;
	int keySize = size(key);

	for (int i = keySize; i > 0; i--) {

		decodeChar(key[keySize - i]);
	}
}


int main() {

	srand((unsigned int)time(NULL));

	softCheck();
	login();
	printStart();


	decode();
	return (0);
}