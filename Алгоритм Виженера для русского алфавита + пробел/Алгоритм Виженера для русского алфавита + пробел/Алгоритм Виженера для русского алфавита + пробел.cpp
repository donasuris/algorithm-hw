#include <iostream>
#include <Windows.h>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	string keyword, letter;
	cin >> keyword;
	getline(cin, letter);
	getline(cin, letter);
	vector<int> keynum(keyword.length());

	for (int i = 0; i < keyword.length(); i++) {
		if (static_cast<int>(keyword[i]) > 64 && static_cast<int>(keyword[i]) < 91) // A, B, C,..,Z
			keynum[i] = static_cast<int>(keyword[i]) - 65;
		if (static_cast<int>(keyword[i]) > 96 && static_cast<int>(keyword[i]) < 123) // a, b, c,..,z
			keynum[i] = static_cast<int>(keyword[i]) - 97;
		if (static_cast<int>(keyword[i]) > -65 && static_cast<int>(keyword[i]) < -32) // А, Б, В,..,Я
			keynum[i] = static_cast<int>(keyword[i]) + 64;
		if (static_cast<int>(keyword[i]) > -33 && static_cast<int>(keyword[i]) < 0) // а, б, в,..,я
			keynum[i] = static_cast<int>(keyword[i]) + 32;
	}

	int a = 0, j = 0;
	for (int i = 0; i < letter.length(); i++) {
		if (j == keyword.length())
			j = 0;
		if (static_cast<int>(letter[i]) > 64 && static_cast<int>(letter[i]) < 91) {
			a = static_cast<int>(letter[i]) + keynum[j++];
			while (a > 90)
				a -= 26;
		}

		else if (static_cast<int>(letter[i]) > 96 && static_cast<int>(letter[i]) < 123) {
			a = static_cast<int>(letter[i]) + keynum[j++];
			while (a > 122)
				a -= 26;
		}

		else if (static_cast<int>(letter[i]) > -65 && static_cast<int>(letter[i]) < -32) {
			a = static_cast<int>(letter[i]) + keynum[j++];
			while (a > -33)
				a -= 33;
			while (a < -64)
				a += 33;
		}

		else if (static_cast<int>(letter[i]) > -33 && static_cast<int>(letter[i]) < 0) {
			a = static_cast<int>(letter[i]) + keynum[j++];
			while (a > -1)
				a -= 33;
			while (a < -32)
				a += 33;
		}

		letter[i] = a;
	}

	cout << letter;
}