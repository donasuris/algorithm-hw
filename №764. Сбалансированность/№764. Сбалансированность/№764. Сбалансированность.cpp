#include <iostream>
using namespace std;

struct Node 
{
	int data;
	Node* left; 
	Node* right; 
	Node* parent;

	int dep;
	int dif;

	Node(int value, Node* par = NULL) {
		data = value;
		left = NULL;
		right = NULL;
		parent = par;
		dep = 1;
		dif = 0;
	}

	void calc() {
		dif = (right == NULL ? 0 : right->dep) - (left == NULL ? 0 : left->dep);
	}
};


struct bin_tree {
	Node* root; 
	int count = 0;
	bin_tree() {
		root = NULL;
	}

	bool add(Node* node, Node* cur) {
		if (cur->data == node->data) return false;
		if (cur->data > node->data) {
			if (cur->right != NULL) {
				add(node, cur->right);
				if (cur->right->dep == cur->dep) cur->dep++;
			}
			else {
				cur->right = node;
				if (cur->dep == 1) cur->dep++;
			}
		}
		else {
			if (cur->left != NULL) {
				add(node, cur->left);
				if (cur->left->dep == cur->dep) cur->dep++;
			}
			else {
				cur->left = node;
				if (cur->dep == 1) cur->dep++;
			}
		}
		cur->calc();
		return true;
	}

	bool calc(Node* cur) {
		bool l = true;
		bool r = true;
		if (cur->left != NULL) l = calc(cur->left);
		if (cur->right != NULL) r = calc(cur->right);
		return (abs(cur->dif) <= 1) && l && r;
	}

	void add(int value) {
		Node* temp = new Node(value);
		if (count == 0) {
			root = temp;
			count++;
		}
		else {
			int res = add(temp, root);
			if (!res) delete temp;
			else count++;
		}
	}

	bool is_balanced() {
		return count > 2 ? calc(root) : true;
	}
};

int main()
{
	bin_tree tree;
	int x;
	cin >> x;
	while (x != 0) {
		tree.add(x);
		cin >> x;
	}
	if (tree.is_balanced()) cout << "YES";
	else cout << "NO";
}

