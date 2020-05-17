#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int k = 0;
	int len = str.length()-1;

	for (int i = 0; i < len; i++) {
		if (str[i] == '1') k++;
	}

	if (k % 2 == 0) {
		if (str[len] == 'e') str[len] = '0';
		else str[len] = '1';
	}
	else {
		if (str[len ] == 'e') str[len] = '1';
		else str[len] = '0';
	}
	cout << str;
}
