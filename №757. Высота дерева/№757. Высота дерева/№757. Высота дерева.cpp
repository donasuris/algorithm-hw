﻿#include <iostream>
using namespace std;

class bin_t {
	bin_t* left;
	bin_t* right;
	int val, k;

public:
	bin_t();
	bin_t(int val);
	bin_t* push(bin_t* root, int val);
	int hight(bin_t* root);
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

int bin_t::hight(bin_t* root) {
	if (root == NULL)
		return 0;

	int left_hight = hight(root->left);
	int right_hight = hight(root->right);

	if (left_hight > right_hight)
		return  left_hight + 1;
	else
		return right_hight + 1;
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
	cout << tree.hight(root) << endl;
}
