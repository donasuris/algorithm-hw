#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> vec;
string source, final;

int func(int i, int j) {
	if (i < 0) return j + 1;
	if (j < 0) return i + 1;
	if (vec[i][j] == -1) {
		vec[i][j] = 1 + func(i - 1, j);
		vec[i][j] = min(vec[i][j], 1 + func(i, j - 1));
		if (source[i] == final[j]) {
			vec[i][j] = min(func(i - 1, j - 1), vec[i][j]);
		}
		else {
			vec[i][j] = min(vec[i][j], 1 + func(i - 1, j - 1));
		}
	}
	return vec[i][j];
}

int main()
{
	int n, m;
	cin >> n >> source >> m >> final;
	int len1 = source.length(), len2 = final.length();

	for (int i = 0; i < len1; i++) {
		vector<int> arr;
		for (int j = 0; j < len2; j++) {
			arr.push_back(-1);
		}
		vec.push_back(arr);
	}

	cout << func(len1 - 1, len2 - 1) << endl;
}
