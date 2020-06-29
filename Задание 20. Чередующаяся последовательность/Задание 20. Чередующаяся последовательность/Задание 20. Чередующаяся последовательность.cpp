#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next, * prev;

	Node(int val) {
		this->val = val;
		this->next = NULL;
		this->prev = NULL;
	}
};

class List {
public:
	Node* head, * tail;
	int count;

	List();
	List(const List&);
	List(int count, int val = 0); //коунт элементов и все равны val

	int Count();
	Node* At(int); //выдает указатель на ноду
	int Value(int); //вызывает Ат и берет значение этого нода
	void Remove(int pos); //удалит ноду на такой позиции 
	void Remove(Node*); //возьмет указатель на ноду и удалит ноду 
	void Insert(int pos, int val); //вставить val на pos 
	void PushBack(int n);
	void PushFront(int n);
	void Print();
};

List::List() {
	head = NULL;
	tail = NULL;
	count = 0;
}

List::List(const List& L) {
	head = NULL;
	tail = NULL;
	count = 0;

	Node* temp = L.head;
	while (temp != 0) {
		PushBack(temp->val);
		temp = temp->next;
	}
}

List::List(int count, int val) {
	head = NULL;
	tail = NULL;
	this->count = 0;
	for (int i = 0; i < count; i++) PushBack(val);
}

void List::PushFront(int n) {
	Node* temp = new Node(n);
	temp->next = head;
	if (head != 0) head->prev = temp;
	if (count == 0) head = tail = temp;
	else head = temp;
	count++;
}

void List::PushBack(int n) {
	Node* temp = new Node(n);
	temp->prev = tail;
	if (tail != 0) tail->next = temp;
	if (count == 0) head = tail = temp;
	else tail = temp;
	count++;
}

void List::Insert(int pos, int val) {
	if (pos < 0 || pos > count) throw "error";
	if (pos == count) {
		PushBack(val);
		return;
	}
	else if (pos == 0) {
		PushFront(val);
		return;
	}

	Node* temp = head;
	for (int i = 0; i < pos; i++) temp = temp->next;
	Node* prevTemp = temp->prev;
	Node* tmp = new Node(val);
	prevTemp->next = tmp;

	temp->prev = tmp;
	tmp->next = temp;
	tmp->prev = prevTemp;
	count++;
}

void List::Remove(int pos) {
	if (pos < 0 || pos >= count) throw "error";
	Node* temp = head;

	for (int i = 0; i < pos; i++) temp = temp->next;
	
	Node* prevTemp = temp->prev;
	Node* nextTemp = temp->next;

	if (prevTemp != 0) prevTemp->next = nextTemp;
	if (nextTemp != 0) nextTemp->prev = prevTemp;
	if (pos == 0) head = nextTemp;
	if (pos == count - 1) tail = prevTemp;

	delete temp;
	count--;
}

void List::Remove(Node* node) {
	if (node->next != NULL) node->next = node->prev;
	if (node->prev != NULL) node->prev = node->next;
	if (head == node) head = node->next;
	if (tail == node) tail = node->prev;
	count--;
}

void List::Print() {
	if (count != 0) {
		Node* temp = head;
		while (temp->next != 0) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << temp->val << "\n";
	}
}

int List::Count() {
	return count;
}

Node* List::At(int index) {
	if (index < 0 || index >= count) throw "error";
	Node* temp = head;
	for (int i = 0; i < index; i++) temp = temp->next;
	return temp;
}

int List::Value(int index) {
	return At(index)->val;
}


int main()
{
	List list;
	int n, el;

	cin >> n;
	cin >> el;
	list.PushBack(el);

	if (n != 1) { //если н не 1
		if (n == 2) { 
			cin >> el;
			if (list.Value(0) != el) {
				list.PushBack(el);
			}
		}
		else {
			bool cur;
			int last = list.Value(0);
			int i;
			for (i = 1; i < n; i++) {
				cin >> el;
				if (last != el) {
					cur = last > el;
					last = el;
					list.PushBack(last);
					break;
				}
			}

			for (i = i + 1; i < n; i++) {
				cin >> el;
				if (el != last) {
					if ((last > el) != cur) {
						list.PushBack(el);
						cur = last > el;
						last = el;
					}
					else {
						list.tail->val = el;
						last = el;
					}
				}
			}
		}
	}

	list.Print();
	return 0;
}