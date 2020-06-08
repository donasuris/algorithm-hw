#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
	Node(int value) {
		this->next = NULL;
		this->value = value;
	}
	Node* next;
	int value; 
};

struct stack {
	long long count;
	Node* head; 

	stack() {
		count = 0;
		head = new Node(0);
		head->next = NULL;
	}

	void push(int value)  {
		Node* temp = new Node(value);
		temp->next = head->next;
		head->next = temp;
		count++;
	}

	int pop() {
		if (count > 0) {
			int temp = head->next->value;
			Node* del = head->next;
			count--;
			head->next = head->next->next;
			delete del;
			return temp;
		}
		else cout << "Empty queue";
	}

	void print(Node* tmp) {
		if (tmp != NULL) {
			print(tmp->next);
			cout << tmp->value << ' ';
		}
	}

	void print() {
		print(head->next);
	}
};


int main()
{
	ifstream input("input.txt");
	freopen("output.txt", "w", stdout);
	stack stack;
	string cmd;
	while (input >> cmd) {
		if (cmd[0] == '-') {
			if (stack.count < 1) {
				stack.count--;
				cout << "ERROR";
				break;
			}
			else stack.pop();
		}
		else {
			string temp = cmd.substr(1);
			stack.push(atoi(temp.c_str()));
		}
	}
	if (stack.count == 0) cout << "EMPTY";
	else stack.print();
}
