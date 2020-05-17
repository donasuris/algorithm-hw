#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void decode(string str) {                              //распаковка
	ifstream input(str, ios::binary | ios::in);
	ofstream output(str + "_decoded", ios::binary | ios::out);

	char byte;
	char temp;

	while (!input.eof()) {
		input.read((char*)(&byte), 1);
		if (byte > 0) {
			input.read((char*)(&temp), 1);
			for (int i = 0; i < byte; i++)
				output.write((char*)(&temp), 1);
		}
		else {
			for (int i = 0; i < -byte; i++) {
				input.read((char*)(&temp), 1);
				output.write((char*)(&temp), 1);
			}
		}
	}
	input.close();
	output.close();
}

int main()
{
	string text;
	cout << "name of file:";
	cin >> text;
	
	decode(text);
}
