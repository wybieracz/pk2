#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <string.h>


#define NICK "Ralph"
#define PASS "K@rIss0n"
#define Q1 "gran vals"
#define FIGURE "cyjan triangle"
#define FILE_NAME "key0702.dat"
#define GAME_KEY "BRAWO-KONIEC-GRY"

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

	printNewLine("Oscar and Jack are trying to figure out which geometric figure form below list is Lily's favourite one.\n");
	SetConsoleTextAttribute(hConsole, 14);
	printNewLine("-> yellow star");
	SetConsoleTextAttribute(hConsole, 13);
	printNewLine("-> magenta star");
	SetConsoleTextAttribute(hConsole, 14);
	printNewLine("-> yellow triangle");
	SetConsoleTextAttribute(hConsole, 11);
	printNewLine("-> cyjan triangle");
	SetConsoleTextAttribute(hConsole, 14);
	printNewLine("-> yellow square");
	SetConsoleTextAttribute(hConsole, 13);
	printNewLine("-> magenta square");
	SetConsoleTextAttribute(hConsole, 14);
	printNewLine("-> yellow hexagon");
	SetConsoleTextAttribute(hConsole, 11);
	printNewLine("-> cyjan circle");
	SetConsoleTextAttribute(hConsole, 13);
	printNewLine("-> magenta circle\n");
	SetConsoleTextAttribute(hConsole, 15);
	printNewLine("Oscar knows, that Lily told Jack which shape it is and Jack knows, that Oscar knows what color the figure is.\nThen Oscar said : \"I don't know which figure is Lily's favourite one,\nbut I know that Jack also doesn't know that\".\nJack replied : \"At the begining I didn't know Lily's favourite figure, but now I know\".\nHearding that, Oscar said : Now, I also know it\". What is Lily's favourite figure?\n");

	print("-> Anwser: ");
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
			getline(cin, nick);
			print("-> Password: ");
			getline(cin, pass);

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
		getline(cin, quest1);
		transform(quest1.begin(), quest1.end(), quest1.begin(), ::tolower);

		if (quest1.compare(Q1)) {

			SetConsoleTextAttribute(hConsole, 12);
			print("\n//You've been kicked//");
			Sleep(2000);
			SetConsoleTextAttribute(hConsole, 15);
			system("CLS");
		}

	} while (quest1 != Q1);
	
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

void puzzle() {

	bool first = true;
	string anwser;

	do {

		SetConsoleTextAttribute(hConsole, 15);
		system("CLS");

		if (first) {
			print("Solve puzzle to decode file. Be careful you have only one chance.");
			SetConsoleTextAttribute(hConsole, 12);
			printNewLine(" Incorrect answer can damage file!\n");
			SetConsoleTextAttribute(hConsole, 15);
		}

		printPuzzle();
		getline(cin, anwser);
		transform(anwser.begin(), anwser.end(), anwser.begin(), ::tolower);

		if (!first && anwser != FIGURE) {
			SetConsoleTextAttribute(hConsole, 12);
			printNewLine("\n//Anwser incorrect. Decoding failed!//");
			Sleep(2000);
			system("CLS");
		}

		if (first && anwser != FIGURE) {
			Sleep(600);
			cout << ".";
			Sleep(600);
			cout << ".";
			Sleep(600);
			cout << ".";
			system("CLS");
			cout << "I said ";
			Sleep(1000);
			cout << "ONE ";
			Sleep(1000);
			cout << "chance!";
			Sleep(2000);
			system("CLS");
			print("Mehh..");
			Sleep(1000);
			print(" fine, try again :/");
			Sleep(1500);
			system("CLS");
			first = false;
		}

	} while (anwser != FIGURE);

	SetConsoleTextAttribute(hConsole, 10);
	printNewLine("\n//Anwser correct. Starting decoding//\n");
	SetConsoleTextAttribute(hConsole, 15);
	Sleep(1500);
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

void decode(string inputKey) {

	string key = inputKey;
	int keySize = size(key);

	for (int i = keySize; i > 0; i--) {

		decodeChar(key[keySize - i]);
	}
}

void openBadFile(string name) {

	SetConsoleTextAttribute(hConsole, 15);
	print("\n//File: ");
	print(name);
	printNewLine("//\n");

	printNewLine("BLUME INC.");
	printNewLine("Extension: .dat");
	printNewLine("File type: key");
	printNewLine("Digital signature: true");
	printNewLine("Encoded: false");
	printNewLine("Key: 00000-00000-00000\n");

	printNewLine("/EOF\n");
}

bool checkExt(string name) {

	if (name.length() > 4) {

		char ext[5];
		ext[4] = '\0';

		for (int i = 0; i < 4; i++) {
			ext[i] = name[size(name) - 4 + i];
		}

		if (strcmp(ext, ".dat") != 0) return false;
		else return true;
	}
	else {
		return false;
	}
}

string makeFileName(int i) {

	if (i < 10) return "key000" + to_string(i) + ".dat";
	if (i >= 10 && i < 100) return "key00" + to_string(i) + ".dat";
	if (i >= 100) return "key0" + to_string(i) + ".dat";
}

bool yesNoF(char letter) {

	if (letter == 'y' || letter == 'n') return true;
	else return false;
}

void searchFile(string* name) {

	string output, yesNo;
	bool isFound = false;

	for (int i = 0; i < 1000; i++) {

		output = makeFileName(i);
		cout << output << endl;

		if (output == *name) {

			isFound = true;
			break;
		}
	}

	if (!isFound) {

		SetConsoleTextAttribute(hConsole, 12);
		print("\n//");
		print(*name);
		printNewLine(" file is not found//\n");
		SetConsoleTextAttribute(hConsole, 15);
	}
	else {

		SetConsoleTextAttribute(hConsole, 10);
		print("\n//");
		print(*name);
		printNewLine(" file found//\n");
		SetConsoleTextAttribute(hConsole, 15);

		do {
			printNewLine("Do you want to open it? <y/n>");
			print("-> ");
			getline(cin, yesNo);

			if (yesNo[0] == 'y') {
				if(*name != FILE_NAME) openBadFile(*name);
			}

			if (yesNo[0] == 'n') {
				if (*name == FILE_NAME) *name = "error";
				cout << endl;
				break;
			}

		} while (!yesNoF(yesNo[0]));
	}
}

void openGoodFile(bool* exit) {

	string yesNo;

	SetConsoleTextAttribute(hConsole, 15);
	print("\n//File: ");
	print(FILE_NAME);
	printNewLine("//\n");

	printNewLine("BLUME INC.");
	printNewLine("Extension: .dat");
	printNewLine("File type: global key");
	printNewLine("Digital signature: true");
	printNewLine("Encoded: true");
	print("Key: ");
	SetConsoleTextAttribute(hConsole, 12);
	printNewLine("XXXXX-XXXXX-XXXXX\n");
	SetConsoleTextAttribute(hConsole, 15);
	printNewLine("/EOF\n");

	printNewLine("//Key is decrypted//\n");

	do {
		printNewLine("Do you want to decrypt it? <y/n>");
		print("-> ");
		getline(cin, yesNo);

		if (yesNo[0] == 'y') {
			*exit = true;
		}

		if (yesNo[0] == 'n') {
			cout << endl;
		}

	} while (!yesNoF(yesNo[0]));
}

void searchMachine() {

	string fileName;
	bool exit = false;

	SetConsoleTextAttribute(hConsole, 15);
	printNewLine("//Server's Files Browser v1.2//");
	printNewLine("//IP: 258.12.192.3//\n");
	printNewLine("//INFO: To seachr file, type its name and press enter//\n");
	
	do {
		do {

			SetConsoleTextAttribute(hConsole, 15);
			print("-> ");
			getline(cin, fileName);

			if (!checkExt(fileName)) {
				SetConsoleTextAttribute(hConsole, 12);
				Sleep(2000);
				printNewLine("\n//Could not find any file with this extension//\n");
			}
			else {

				if (fileName.find("key") != string::npos) {

					searchFile(&fileName);
				}
				else {

					Sleep(2000);
					SetConsoleTextAttribute(hConsole, 12);
					print("\n//Could not find ");
					print(fileName);
					printNewLine(" file//\n");
				}
			}
		} while (fileName != FILE_NAME);

		openGoodFile(&exit);
	} while (!exit);
}

void openEncodedFile() {

	SetConsoleTextAttribute(hConsole, 15);
	print("\n//File: ");
	print(FILE_NAME);
	printNewLine("//\n");

	printNewLine("BLUME INC.");
	printNewLine("Extension: .dat");
	printNewLine("File type: global key");
	printNewLine("Digital signature: true");
	printNewLine("Encoded: true");
	print("Key: ");
	decode(GAME_KEY);
	printNewLine("\n\n/EOF\n");
}

void licznik(int count, int maxWide) {

	string temp;

	for (int i = count; i >= 0; i--) {

		cout << setfill('0') << setw(maxWide) << i;
		Sleep(1000);
		cout << '\b' << '\b';
	}
}

string status(int randomInt) {

	if (randomInt % 2) return "working";
	else return "unknown";
}

void disconnect() {
	
	SetConsoleTextAttribute(hConsole, 12);
	printNewLine("\n//SERVER CONNECTION LOST!//\n");
	SetConsoleTextAttribute(hConsole, 15);
	print("-> Trying to reconnect in: ");
	Sleep(100);
	licznik(10, 2);
	cout << endl;

	for (int i = 0; i < 50; i++) {

		cout << "-> ip: 258." << rand() % 255 << "." << rand() % 255 << "." << rand() % 255 << "  status: " << status(rand() % 10) << "  connection: ";
		SetConsoleTextAttribute(hConsole, 12);
		Sleep(50);
		cout << "fail" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		Sleep(10);
	}

	Sleep(100);
	int x = 50;

	cout << "\n/home/wybieracz/.local/share/Steam/ubuntu12_32/../ubuntu12_64/gldriverquery: 1:" << endl;
	Sleep(x);
	cout << "/home/wybieracz/.local/share/Steam/ubuntu12_32/../ubuntu12_64/gldriverquery: Syntax error: unexpected" << endl;
	Sleep(x);
	cout << "Generating new string page texture 7: 128x256, total string texture memory is 131,07 KB" << endl;
	Sleep(x);
	cout << "Generating new string page texture 8: 64x256, total string texture memory is 196,61 KB" << endl;
	Sleep(x);
	cout << "Generating new string page texture 9: 48x256, total string texture memory is 245,76 KB" << endl;
	Sleep(x);
	cout << "Generating new string page texture 10: 256x256, total string texture memory is 507,90 KB" << endl;
	Sleep(x);
	cout << "Illegal instruction (core dumped)" << endl;
	Sleep(x);
	cout << "/home/wybieracz/.local/share/Steam/ubuntu12_32/../ubuntu12_64/vulkandriverquery: 1: " << endl;
	Sleep(x);
	cout << "/home/wybieracz/.local/share/Steam/ubuntu12_32/../ubuntu12_64/vulkandriverquery: cannot create" << endl;
	Sleep(x);
	cout << "@8: Directory nonexistent" << endl;
	Sleep(x);
	cout << "/home/wybieracz/.local/share/Steam/ubuntu12_32/../ubuntu12_64/vulkandriverquery: 1: " << endl;
	Sleep(x);
	cout << "/home/wybieracz/.local/share/Steam/ubuntu12_32/../ubuntu12_64/vulkandriverquery: not found" << endl;
	Sleep(x);
	cout << "Syntax error: Unterminated quoted string" << endl;
	Sleep(x);
	cout << "Generating new string page texture 11: 8x256, total string texture memory is 516,10 KB" << endl;
	Sleep(x);
	cout << "Generating new string page texture 12: 16x256, total string texture memory is 532,48 KB" << endl;
	Sleep(x);
	cout << "Generating new string page texture 13: 24x256, total string texture memory is 557,06 KB" << endl;
	Sleep(x);
	cout << "Generating new string page texture 14: 32x256, total string texture memory is 589,82 KB" << endl;
	Sleep(x);
	cout << "Installing breakpad exception handler for appid(steam)/version(1513371133)" << endl;
	Sleep(x);
	cout << "Installing breakpad exception handler for appid(steam)/version(1513371133)" << endl;
	Sleep(x);
	cout << "Generating new string page texture 19: 384x256, total string texture memory is 983,04 KB" << endl;
	Sleep(x);
	cout << "Installing breakpad exception handler for appid(steam)/version(1513371133)" << endl;
	Sleep(x);
	cout << "Installing breakpad exception handler for appid(steam)/version(1513371133)" << endl;
	Sleep(x);
	cout << "roaming config store loaded successfully - 6771 bytes." << endl;
	Sleep(x);
	cout << "migrating temporary roaming config store" << endl;
	Sleep(x);
	cout << "Failed to init SteamVR because it isn't installed" << endl;
	Sleep(x);
	cout << "crash_20180205010025_1.dmp[2295]: Uploading dump (out-of-process)" << endl;
	Sleep(x);
	cout << "/tmp/dumps/crash_20180205010025_1.dmp" << endl;
	Sleep(x);
	cout << "/home/wybieracz/.local/share/Steam/steam.sh: linia 927:  2250 B³êdna instrukcja" << endl;
	Sleep(x);
	cout << "(zrzut pamiêci) $STEAM_DEBUGGER $STEAMROOT / $STEAMEXEPATH $@" << endl;
	Sleep(x);
	cout << "crash_20180205010025_1.dmp[2295]: Finished uploading minidump (out-of-process): success = yes" << endl;
	Sleep(x);
	cout << "crash_20180205010025_1.dmp[2295]: response: CrashID=bp-7ead86bb-81c8-4302-8fce-6fa892180204" << endl;
	Sleep(x);
	cout << "crash_20180205010025_1.dmp[2295]: file /tmp/dumps/crash_20180205010025_1.dmp, upload yes: CrashID=bp-7ead86bb-81c8-4302-8fce-6fa892180204" << endl;
	Sleep(x);
	Sleep(1000);

	for (int i = 0; i < 50000; i++) {

		printf("%c", 33 + rand() % 93);
	}
}

int main() {

	srand((unsigned int)time(NULL));

	softCheck();
	login();
	printStart();
	searchMachine();
	puzzle();
	openEncodedFile();
	disconnect();
	return (0);
}