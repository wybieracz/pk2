#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void print(string line) {

		int x = 0;
		while (line[x] != '\0') {
			cout << line[x];
			Sleep(1);
			x++;
		};
		cout << endl;
}

void printStart() {

	string blume = "                                  `:oy+.                                   ";
	print(blume);
	blume = "                               ./ymMMMMNdo:`                               ";
	print(blume);
	blume = "                           `:odNMMMMMMMMMMNmy/.                            ";
	print(blume);
	blume = "                        -+hmMMMMMMMMMMMMMMMMMMNdo-`                        ";
	print(blume);
	blume = "                       .sdMMMMMMMMMMMMMMMMMMMMMMMh+                        ";
	print(blume);
	blume = "                 .:so `+-.-ohNMMMMMMMMMMMMMMMNh+-.-+` -/.                  ";
	print(blume);
	blume = "              .+ymMMy .MNds:../sdNMMMMMMMMmy/..:sdNM. oMmh+-`              ";
	print(blume);
	blume = "          `-odNMMMMMs .MMMMMmy+-.-+hmMNdo:.-+ymMMMMM. oMMMMNds:`           ";
	print(blume);
	blume = "          `-odNMMMMMs .MMMMMmy+-.-+hmMNdo:.-+ymMMMMM. oMMMMNds:`           ";
	print(blume);
	blume = "       .:sdNMMMMMMMMs .MMMMMMMMNdo:..:..:odNMMMMMMMM. oMMMMMMMMmy/.        ";
	print(blume);
	blume = "      -mMMMMMMMMMMMMs .MMMMMMMMMMMMm- -mMMMMMMMMMMMM. oMMMMMMMMMMMNd:      ";
	print(blume);
	blume = "      :MMMMMMMMMMMMMo .MMMMMMMMMMMMM: :MMMMMMMMMMMMM. oMMMMMMMMMMMMMs      ";
	print(blume);
	blume = "      :MMMMMMMMMMMMMo -MMMMMMMMMMMMM: :MMMMMMMMMMMMM- oMMMMMMMMMMMMMs      ";
	print(blume);
	blume = "      :MMMMMMMMMMMMMo -MMMMMMMMMMMMM: :MMMMMMMMMMMMM- oMMMMMMMMMMMMMy      ";
	print(blume);
	blume = "      :MMMMMMMMMMMmh- :MMMMMMMMMMMMM/ /MMMMMMMMMMMMM: -hmMMMMMMMMMMMy      ";
	print(blume);
	blume = "      :MMMMMMMNms/.`-odMMMMMMMMMMMMM/ /MMMMMMMMMMMMMdo-`./ymNMMMMMMMh      ";
	print(blume);
	blume = "      :MMMMNho-`./ymMMMMMMMMMMMMMMMM/ /MMMMMMMMMMMMMMMMmy/.`:odNMMMMh      ";
	print(blume);
	blume = "      :Nmy/.`.+hNMMMMMMMMMMMMMMMMMMM/ /MMMMMMMMMMMMMMMMMMMNh+.`-+hNMd      ";
	print(blume);
	blume = "      `:``-odNMMMMMMMMMMMMMMMMMMMMMM: :MMMMMMMMMMMMMMMMMMMMMMNdo-`./+      ";
	print(blume);
	blume = "        :dMMMMMMMMMMMMMMMMMMMMMMNmy/```/ymNMMMMMMMMMMMMMMMMMMMMMMd/        ";
	print(blume);
	blume = "      :/``:smNMMMMMMMMMMMMMMMNdo-``/sds/``-odNMMMMMMMMMMMMMMMNms:.`/o      ";
	print(blume);
	blume = "      oMNh+.`-odNMMMMMMMMMNy/. .+hNMMMMMNh+. ./yNMMMMMMMMMNdo-`.+hNMm      ";
	print(blume);
	blume = "      oMMMMMms:`./yNMMMds:``:sdMMMMMMMMMMMMMds:``:sdMMMNy/``:sdMMMMMd      ";
	print(blume);
	blume = "      oMMMMMMMMNh+. -/. `/yNMMMMMMMMMMMMMMMMMMMNy/` ./- `/yNMMMMMMMMd      ";
	print(blume);
	blume = "      oMMMMMMMMMMMMd. :dMMMMMMMMMMMMMMMMMMMMMMMMMMMd: -hNMMMMMMMMMMMd      ";
	print(blume);
	blume = "      oMMMMMMMMMMMMM- oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo /MMMMMMMMMMMMMh      ";
	print(blume);
	blume = "      oMMMMMMMMMMMMM: oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo /MMMMMMMMMMMMMh      ";
	print(blume);
	blume = "      oMMMMMMMMMMMMM: oMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo /MMMMMMMMMMMMMh      ";
	print(blume);
	blume = "      /mMMMMMMMMMMMM/ oMMMMMMMMMMMmy/./ymMMMMMMMMMMMo /MMMMMMMMMMMNh/      ";
	print(blume);
	blume = "       `-odNMMMMMMMM/ oMMMMMMMNho-`./o/.`-ohNMMMMMMMo /MMMMMMMMmy/.        ";
	print(blume);
	blume = "          `.+hNMMMMM/ oMMMMmy/.`-+hNMMMNh+-`./ymMMMMo /MMMMNdo:`           ";
	print(blume);
	blume = "              `:smMM+ oNho-`./smNMMMMMMMMMNds:``-ohNo /Mmy+.`              ";
	print(blume);
	blume = "                 `-o: ..`-+hNMMMMMMMMMMMMMMMMMmy/.`.. .:`                  ";
	print(blume);
	blume = "                       -yNMMMMMMMMMMMMMMMMMMMMMMMh/                        ";
	print(blume);
	blume = "                        `-ohNMMMMMMMMMMMMMMMMNdo-`                         ";
	print(blume);
	blume = "                            ./ydMMMMMMMMMMmy/.`                            ";
	print(blume);
	blume = "                               `-ohmMMNds:.                                ";
	print(blume);
	blume = "                                   ./+-`                                   ";
	print(blume);

	cout << endl << endl << endl;



	blume = "     .-nnn`         .-            -.  .-         -.   `-`        dHHHH`    ";
	print(blume);
	blume = "     +M   d.        hm           .Mo  yN`        mN+`.hM/        dN        ";
	print(blume);
	blume = "     +MhydN-        hm           .Mo  yN`        mN hm M/        dNsss-    ";
	print(blume);
	blume = "     +M  /Ny        hm           .Ns  hN`        mh s+ M/        dN        ";
	print(blume);
	blume = "     /mdddh-        ymddd/        +hddh:         hy   -m:        ymddh/    ";
	print(blume);
}

void login() {
	SetConsoleTextAttribute(hConsole, 15);

	string nick, nickGood = "admin";
	string pass, passGood = "admin";
	string quest2, questGood2 = "gran";

	do {
		do {
			cout << "Nick: ";
			cin >> nick;
			cout << "Password: ";
			cin >> pass;

			if (nick != nickGood) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Couldn't find that username." << endl;
				Sleep(2000);
				system("CLS");
			}

			if (nick == nickGood && pass != passGood) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << "Wrong password." << endl;
				Sleep(2000);
				system("CLS");
			}
			SetConsoleTextAttribute(hConsole, 15);
		} while ((nick != nickGood) || (pass != passGood));

		SetConsoleTextAttribute(hConsole, 10);
		Sleep(500);
		cout << "Verify your identity by security question:" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << "2. Favourite song: ";
		cin >> quest2;

		if (quest2.compare(questGood2)) {

			SetConsoleTextAttribute(hConsole, 12);
			cout << "You've been kicked!" << endl;
			Sleep(2000);
			SetConsoleTextAttribute(hConsole, 15);
			system("CLS");
		}

	} while (quest2 != questGood2);
	
	SetConsoleTextAttribute(hConsole, 10);
	cout << "Logging in";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << ".";
	Sleep(1000);
	cout << "." << endl;
	SetConsoleTextAttribute(hConsole, 15);
}


int main() {

	login();
	printStart();

	//cout << '\b' << '\b' << '\b';
	return (0);
}