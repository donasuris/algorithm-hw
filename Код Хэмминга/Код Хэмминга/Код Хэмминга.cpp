#include <iostream>
#include <string>

using namespace std;

int main()
{
	string StrokaX10;

	string StrokaX2;
	cin >> StrokaX10;

	for (int i = 0; i < StrokaX10.length(); i++) {
		int chisloXasc;
		string tmp = "";
		chisloXasc = int(StrokaX10[i]);

		if (chisloXasc < 0)
			chisloXasc = abs(chisloXasc) + 48;
		else
			tmp += '0';

		do {
			tmp.insert(1, to_string(chisloXasc % 2));
			chisloXasc /= 2;
		} while (chisloXasc != 0);
		StrokaX2 += tmp;
	}

	int start = 1;
	while (start < StrokaX2.length() - 1) {
		StrokaX2.insert(start - 1, " ");
		start *= 2;
	}

	start = 1;

	while (start < StrokaX2.length() - 1) {
		int tmp = false;
		int point = start;
		while (point <= StrokaX2.length()) {
			for (int i = 0; ((i < start) && (i + point <= StrokaX2.length())); i++) {
				if ((StrokaX2[point - 1 + i] != ' ') && (StrokaX2[point - 1 + i] == '1'))
					tmp = !tmp;
			}
			point += 2 * start;
		}
		StrokaX2[start - 1] = (char)(((int)'0') + tmp);
		start *= 2;
	}

	cout << StrokaX2;
	if (StrokaX2.length() % 8 != 0) {
		for (int i = 0; i < StrokaX2.length() % 8; i++)
			StrokaX2 += '0';
	}
	cout << endl << endl;
	for (int i = 0; i < StrokaX2.length(); i += 8) {
		string tmp = "";
		tmp.replace(0, 0, StrokaX2, i, 8);

		int mnoj = 1;
		int sum = 0;
		for (int i = 7; i >= 0; i--) {
			if (tmp[i] == '1')sum += mnoj;
			mnoj *= 2;
		}
		cout << (char)sum << " ";
	}
	cout << endl;
	for (int i = 0; i < StrokaX2.length(); i += 8) {
		string tmp = "";
		tmp.replace(0, 0, StrokaX2, i, 8);

		int mnoj = 1;
		int sum = 0;
		for (int i = 7; i >= 0; i--) {
			if (tmp[i] == '1')sum += mnoj;
			mnoj *= 2;
		}
		cout << sum << " ";
	}
}