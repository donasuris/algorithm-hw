#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	Node* parent;
	int val;
	int len;
	Node(int val){
		this->len = 0;
		this->val = val;
	}
};

Node* max_;
int max_len;
vector<Node*> maxNode;

void push(Node* tmp) {
	for (int i = 0; i < tmp->val; i++) {
		if (maxNode[i] != NULL) {
			if (tmp->len < maxNode[i]->len + 1) {
				tmp->len = maxNode[i]->len + 1;
				tmp->parent = maxNode[i];
			}
		}
	}

	if (tmp->len > max_len) {
		max_len = tmp->len;
		max_ = tmp;
	}
}

void add(int val) {
	Node* new_node = new Node(val);
	push(new_node);
	if (maxNode[val] == NULL or new_node->len > maxNode[val]->len) 
		maxNode[val] = new_node;
}

void print() {
	vector<int> arr;
	Node* cur = max_;

	while (cur->val != 0) {
		arr.push_back(cur->val);
		cur = cur->parent;
	}

	int k = arr.size();
	cout << k << endl;
	while (k > 0){
		k--;
		cout << arr[k] << ' ';
	}
}

int main()
{
	max_len = 0;
	for (int i = 0; i < 100001; i++) maxNode.push_back(NULL);
	add(0);
	int N, val;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> val;
		add(val);
	}
	print();
}