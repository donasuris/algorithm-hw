#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout("output.txt");

class Node {
public:
	Node* prev;
	string val;

	Node(string val) {
		this->val = val;
		this->prev = NULL;
	}
};

class stack {
public:
	Node* head;
	int len;

	stack() {
		this->len = 0;
		this->head = new Node("0");
	}

	void push(string val) {
		Node* tmp = new Node(val);
		tmp->prev = head->prev;
		head->prev = tmp;
		++len;
	}

	void pop() {
		--len;
		Node* tmp = head->prev;
		head->prev = tmp->prev;
		delete tmp;
	}

	void print(int c, int len, Node* tmp) {
		if (c < len) print(++c, len, tmp->prev);
		fout << tmp->val << " ";
	}
};

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	stack s;
	string str;
	while (fin >> str) {
		if (str[0] == '-') {
			if (s.len < 1){
				s.len--;
				fout << "ERROR";
				break;
			}
			else {
				s.pop();
			}
		}
		else {
			string c = str.substr(1);
			s.push(c);
		}
	}
	if (s.len == 0) fout << "EMPTY";
	else if (s.len > 0) {
		s.print(1, s.len, s.head->prev);
	}
}
