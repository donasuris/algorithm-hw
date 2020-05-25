#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

class Node {
public:
	string number;
	Node* next;

	Node(string number) {
		this->number = number;
		this->next = NULL;
	}
};

class queue {
public:
	int size;
	Node* head;
	Node* middle;
	Node* tail;
	void push(string number);
	void pop();
	void push_mid(string number);

	queue() {
		size = 0;
		head = NULL;
		middle = NULL;
		tail = NULL;
	}
};

void queue::pop() {
	string number = tail->number;
	Node* del = tail;
	tail = tail->next;

	if (size == 1) {
		middle = NULL;
	}
	else if (size % 2 == 0 and size > 1) {
		middle = middle->next;
	}
	size--;
	cout << number << endl;
	delete del;
}

void queue::push(string number) {
	Node* tmp = new Node(number);
	if (size > 0) {
		head->next = tmp;
		head = tmp;

		if (size % 2 == 0) {
			middle = middle->next;
		}
	}
	else {
		head = tmp;
		middle = tmp;
		tail = tmp;
	}
	++size;
}

void queue::push_mid(string number) {
	if (size <= 1) {
		push(number);
	}
	else {
		Node* tmp = new Node(number);
		tmp->next = middle->next;
		middle->next = tmp;

		if (size % 2 == 0) middle = tmp;
		++size;
	}
}


int main()
{
	queue g;
	string number;
	while (getline(fin, number)) {
		if (number[0] == '+') g.push(number.substr(2));
		else if (number[0] == '-') g.pop();
		else if (number[0] == '*') g.push_mid(number.substr(2));
	}
}