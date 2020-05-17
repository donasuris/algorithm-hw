#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	int ham = 0;
	cin >> str1 >> str2;
	int len = str1.length();
	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) ham++;
	}
	cout << ham;
}
