#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node* parent;

	Node(int value, Node* par = NULL) {
		data = value;
		left = NULL;
		right = NULL;
		parent = par;
	}

	bool operator>(Node node) {
		return data > node.data;
	}
};

struct bin_tree {
	Node* root;
	int count = 0;

	bin_tree() {
		root = NULL;
	}

	bool Add(int value) {
		Node* newNode = new Node(value);
		Node* par = root;
		Node* prevPar = NULL; 

		while (par != NULL && par->data != value) {
			prevPar = par;

			if (*par > * newNode)
				par = par->left;
			else
				par = par->right;
		}

		if (par != NULL && par->data == value) {
			delete newNode;
			return false;
		}

		newNode->parent = prevPar;

		if (prevPar == NULL)
			root = newNode;

		else {
			if (*prevPar > * newNode)
				prevPar->left = newNode;
			else
				prevPar->right = newNode;
		}

		return true;
	}

	Node* Find(int value) {
		Node* temp = root;
		while (temp != NULL && temp->data != value) 
			temp = temp->data > value ? temp->left : temp->right;
		return temp;
	}

	Node* FindMin(Node* temp) {
		if (temp == NULL) throw "Empty tree";
		while (temp->left != NULL) temp = temp->left;
		return temp;
	}

	Node* FindMax(Node* temp) {
		if (temp == NULL) throw "Empty tree";
		while (temp->right != NULL) temp = temp->right;
		return temp;
	}

	int Min() {
		return FindMin(root)->data;
	}

	int Max() {
		return FindMax(root)->data;
	}

	bool delete_node(Node* node) {
		if (node == NULL)
			return false;

		if (node->left != NULL && node->right != NULL) {
			Node* temp = FindMax(node->left);
			node->data = temp->data;
			return delete_node(temp);
		}

		if (node->left != NULL)
			node->left->parent = node->parent;
		else if (node->right != NULL)
			node->right->parent = node->parent;

		if (node != root) {
			if (node == node->parent->right)
				node->parent->right = node->left != NULL ? node->left : node->right;
			else
				node->parent->left = node->left != NULL ? node->left : node->right;
		}
		else {
			root = node->left != NULL ? node->left : node->right;
		}
		delete node;
		return true;
	}

	bool Delete(int value) {
		return delete_node(Find(value));
	}

	void Print(Node* p, int level) {
		if (p == NULL) return;
		Print(p->left, level + 1);
		for (int i = 0; i < level; i++) cout << ".";
		cout << p->data << endl;
		Print(p->right, level + 1);
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	bin_tree bt;
	string cmd;
	long long temp;

	while (!cin.eof()) {
		cin >> cmd;

		if (cmd == "ADD") {
			cin >> temp;
			if (bt.Add(temp)) cout << "DONE" << endl;
			else cout << "ALREADY" << endl;
		}
		else if (cmd == "DELETE") {
			cin >> temp;
			if (bt.Delete(temp)) cout << "DONE" << endl;
			else cout << "CANNOT" << endl;
		}
		else if (cmd == "SEARCH") {
			cin >> temp;
			if (bt.Find(temp) != NULL) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else if (cmd == "PRINTTREE") {
			bt.Print(bt.root, 0);
		}
		cmd = "";
	}
	return 0;
}
