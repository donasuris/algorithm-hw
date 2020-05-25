#include <iostream>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int val;
	Node(int val) {
		this->val = val;
		this->next = NULL;
		this->prev = NULL;
	}

};

class circle {
public:
	void push(int val);
	void print(int k, int c);
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur;
};

void circle::push(int val) {
	Node* tmp = new Node(val);
	if (head == NULL) {
		head = tmp;
		return;
	}

	cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = tmp;
	tmp->prev = cur;
	tail = tmp;
}

void circle::print(int k, int c) {
	Node* tmp = head;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < c - 1; ++j) {
			if (j == c - 2) cur = tmp;
			tmp = tmp->next;
		}
		cur->next = cur->next->next;
		cur = tmp->next;
		cout << tmp->val << " ";
		delete tmp;
		tmp = cur;
	}
}

int main()
{
	int N, K;
	circle ch;
	cin >> N >> K;
	if (N == 1) {
		cout << 1;
		return 0;
	}
		
	for (int i = 1; i <= N; i++) {
		ch.push(i);
	}
	ch.tail->next = ch.head;
	ch.head->prev = ch.tail;

	ch.print(N, K);
}
