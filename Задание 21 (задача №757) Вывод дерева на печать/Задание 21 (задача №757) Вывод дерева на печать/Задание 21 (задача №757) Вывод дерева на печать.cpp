#include <iostream>
using namespace std;

class bin_t {
	bin_t* left;
	bin_t* right;
	int val, k;

public:
	bin_t();
	bin_t(int val);
	bin_t* push(bin_t* root, int val);
	int height(bin_t* root);
	void print(bin_t* root);
};

bin_t::bin_t() {
	this->val = 0;
	this->left = this->right = NULL;
}

bin_t::bin_t(int val) {
	this->val = val;
	this->left = NULL;
	this->right = NULL;
}

bin_t* bin_t::push(bin_t* root, int val) {
	if (!root)
		return new bin_t(val);
	if (val > root->val)
		root->right = push(root->right, val);
	else
		root->left = push(root->left, val);
	return root;
}

int bin_t::height(bin_t* root) {
	if (root == NULL)
		return 0;

	int left_hight = height(root->left);
	int right_hight = height(root->right);

	if (left_hight > right_hight)
		return  left_hight + 1;
	else
		return right_hight + 1;
}

void bin_t::print(bin_t* root) {
	if (!root) return;
	k++;
	print(root->right);
	for (int i = 0; i < k; i++) cout << "  ";
	cout << root->val << endl;
	print(root->left);
	k--; 
}


int main()
{
	bin_t tree;
	bin_t* root = NULL;
	bool elem[1000000]{ false };
	int value = 0;
	cin >> value;
	elem[value] = true;
	root = tree.push(root, value);
	cin >> value;
	while (value != 0) {
		if (elem[value] != true) {

			elem[value] = true;
			tree.push(root, value);

		}
		cin >> value;
	}
	cout << tree.height(root) << endl;

	tree.print(root);  //вывод дерева на печать 
}
