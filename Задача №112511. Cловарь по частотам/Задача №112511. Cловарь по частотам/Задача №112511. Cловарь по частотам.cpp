#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct Node{
	int val;
	string word;
	Node* next;
	Node* prev;

	Node(string word){
		this->val = 1;
		this->word = word;
		this->next = NULL;
		this->prev = NULL;
	}

};

class List{
private:
	Node* head = new Node("0");
	Node* tail = new Node("0");

public:
	List(){
		head->next = tail;
		tail->prev = head;
	}

	void push(string word){
		Node* tmp = head->next;

		while (tmp != NULL){
			if (tmp->word == word){
				++tmp->val;
				return;
			}
			tmp = tmp->next;
		}

		Node* cur = new Node(word);

		if (head->next == NULL){
			head->next = cur;
			cur->prev = head;
			tail->prev = cur;
			cur->next = tail;
		}
		else {
			tail->prev->next = cur;
			cur->prev = tail->prev;
			tail->prev = cur;
			cur->next = tail;
		}
	}

	void sort(){
		for (Node* i = head->next; i != tail; i = i->next){                            //сортировка списка 
			for (Node* j = head->next; j != tail->prev; j = j->next){
				if (j->next->val > j->val){
					swap(j->next->val, j->val);
					swap(j->next->word, j->word);
				}

				if (j->next->val == j->val and j->next->word < j->word){
					swap(j->next->val, j->val);
					swap(j->next->word, j->word);
				}
			}
		}
	}

	void print(){
		Node* tmp = head->next;
		while (tmp->word != "0") {
			fout << tmp->word << " " << tmp->val << endl;
			tmp = tmp->next;
		}
	}
};

	int main()
	{
		List l;
		string str;
		while (fin >> str) l.push(str);
		l.sort();
		l.print();
	}