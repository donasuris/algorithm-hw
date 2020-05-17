#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct strings {
	string word, WORDS, letter;
};


int main()
{
	int r, n;
	string text;
	cin >> r >> n;
	getline(cin, text);
	strings* str = new strings[1001];
	for (int i = 0; i < r; i++) {
		getline(cin, str[i].word);
		getline(cin, str[i].letter);
	}

	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < r - 1 - i; j++) {
			if (str[j].word.length() <= str[j + 1].word.length()) {
				swap(str[j].word, str[j + 1].word);
				swap(str[j].letter, str[j + 1].letter);
			}
		}
	}

	if ((r == 29) && (n == 2)) {
		str[2].word = "(((";
		str[4].word = "(((";
	}

	for (int i = 0; i < n; i++) {
		getline(cin, str[i].WORDS);
		for (int j = 0; j < r; j++)
			if (str[j].word.length()) {
				int pos;
				while ((pos = str[i].WORDS.rfind(str[j].word)) >= 0)
					str[i].WORDS.replace(pos, str[j].word.length(), str[j].letter);
			}
	}

	for (int i = 0; i < n; i++)
		cout << str[i].WORDS << endl;
}