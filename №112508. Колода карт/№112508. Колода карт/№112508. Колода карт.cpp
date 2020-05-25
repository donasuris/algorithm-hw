#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct Node {
	Node* next;
	Node* prev;
	string text;
	Node(string text) {
		this->text = text;
		this->next = NULL;
		this->prev = NULL;
	}
};

class dequeue {
public:
	dequeue();
	void push_start(string text);
	void push_end(string text);
	void pop_start();
	void pop_end();
	void print();
	bool replay(string text);
	Node* head;
	Node* tail;
	Node* cur;
};

dequeue::dequeue() {
	head = new Node("0");
	tail = new Node("0");
	head->next = tail;
	tail->prev = head;
	Node* cur = NULL;
}

bool dequeue::replay(string text) {
	cur = head->next;
	while (cur!=tail) {
		if (cur->text == text) {
			return false;
		}
		cur = cur->next;
	}
	return true;
}

void dequeue::push_start(string text) {
	Node* tmp = new Node(text);
	head->next->prev = tmp;
	tmp->next = head->next;
	head->next = tmp;
	tmp->prev = head;
}

void dequeue::push_end(string text) {
	Node* tmp = new Node(text);
	tail->prev->next = tmp;
	tmp->prev = tail->prev;
	tail->prev = tmp;
	tmp->next = tail;
}

void dequeue::pop_start() {
	cur = head->next;
	head->next = cur->next;
	cur->next->prev = head;
	delete cur;
}

void dequeue::pop_end() {
	cur = tail->prev;
	cur->prev->next = tail;
	tail->prev = cur->prev;
	delete cur;
}

void dequeue::print() {
	cur = head->next;
	if (cur == tail) {
		fout << "EMPTY";
		return;
	}
	while (cur != tail) {
		fout << cur->text << " ";
		cur = cur->next;
	}
}

int main()
{
	dequeue d;
	string str;
	while (fin >> str) {
		if (str[0] == '+') {
			if (d.replay(str.substr(1))) {

				d.push_start(str.substr(1));

			}
			else {
				fout << "ERROR";
				return 0;
			}
		}
		else if (str[0] == '#') {
			 if (d.replay(str.substr(1))) {

				 d.push_end(str.substr(1));

			 }
			 else {
				 fout << "ERROR";
				 return 0;
			 }
		}
		else if (str[0] == '^') {
			if(d.head->next==d.tail){
				fout << "ERROR";
				return 0;
			}
			d.pop_start();
		}
		else if (str[0] == '/') {
			if (d.head->next == d.tail) {
				fout << "ERROR";
				return 0;
			}
			d.pop_end();
		}
	}
	d.print();
}
